#include "Tracking.h"
#include <windows.h>

void Tracking::initSettings()
{

	minArea = 400;
	status = "No Motion";
	sizeImg = Size(ui.lblOriginal->width(), ui.lblOriginal->height());

	cap = new VideoCapture(0);
	videoTimer = new QTimer(this);
	connect(videoTimer, SIGNAL(timeout()), this, SLOT(processData()));
	if (cap->read(matFramePre)) {
		cv::resize(matFramePre, matFramePre, sizeImg);
		cvtColor(matFramePre, matFramePre, CV_RGB2GRAY);
		blur(matFrame, matFrame, Size(5, 5));
		cv::flip(matFrame, matFrame, -1);
	}

}

Tracking::Tracking(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	initSettings();
}

void Tracking::processData()
{
	if (!cap->read(matFrame)) {
		cout << "Unable to capture frame!!!" << endl;
		return;
	}
	if (matFrame.empty()) {
		cout << "Empty frame!!!" << endl;
		return;
	}
	cv::resize(matFrame, matFrame, sizeImg);

	cv::flip(matFrame, matFrame, -1);	    /************************/
	matOriginal = matFrame.clone();


	mog2.operator ()(matFrame, matFore);
	mog2.getBackgroundImage(matBack);
	cv::erode(matFore, matFore, cv::Mat());
	cv::dilate(matFore, matFore, cv::Mat());


	findContours(matFore, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	vector<vector<Point> > ::iterator itc = contours.begin();

	// 
	// 	cout << "No of contours : " << contours.size() << endl;
	status = "No Motion";

	while (itc != contours.end())
	{
		if (contourArea(*itc) > minArea)
		{
			status = "ALERT!!!";
			//ShellExecute(NULL, L"open", L"c:/example1/qq.mp4", NULL, NULL, SW_HIDE);
			Rect tempRect = boundingRect((Mat(*itc)));
			rectangle(matOriginal, tempRect, Scalar(0, 0, 255));

		}
		++itc;
	}

	putText(matOriginal, "Status : " + status, Point(10, 30), 1, 2, Scalar(0, 0, 255), 2);
	showImage(matOriginal, ui.lblOriginal);
	showImage(matFore, ui.lblProcessed);
	matFramePre = matFrame.clone();


}

void Tracking::on_btnStartStop_pressed()
{
	if (videoTimer->isActive()) {
		videoTimer->stop();
		ui.btnStartStop->setText("START CAMERA");
	}
	else {
		videoTimer->start(40);
		ui.btnStartStop->setText("STOP CAMERA");
	}
}

void Tracking::showImage(Mat img, QLabel *lbl)
{
	if (img.empty())
	{
		cout << "Empty image to show!!!" << endl;
		return;
	}

	QImage Qimgbkg;
	if (img.type() == CV_8UC3)
	{
		cvtColor(img, img, CV_BGR2RGB);
		QImage Qimgbkg1((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
		Qimgbkg = Qimgbkg1;

	}
	else if (img.type() == CV_8UC4) {
		cvtColor(img, img, CV_BGRA2RGBA);
		QImage Qimgbkg1((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGBA8888);
		Qimgbkg = Qimgbkg1;

	}
	else {
		QImage Qimgbkg1((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_Indexed8);
		Qimgbkg = Qimgbkg1;

	}

	lbl->setPixmap(QPixmap::fromImage(Qimgbkg));
}

