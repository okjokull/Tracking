#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tracking.h"
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QMessageBox>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


class Tracking : public QMainWindow
{
	Q_OBJECT

public:
	Tracking(QWidget *parent = Q_NULLPTR);

	VideoCapture *cap;
	Mat matFrame, matBack, matFore, matFramePre, matOriginal, matMask;
	BackgroundSubtractorMOG2 mog2;
	vector<vector<Point> > contours;
	QTimer *videoTimer;

	public slots:
	void processData();

	private slots:
	void on_btnStartStop_pressed();

private:
	Ui::TrackingClass ui;
	void initSettings();
	void showImage(Mat img, QLabel *lbl);
	string status;
	unsigned int minArea;
	Size sizeImg;
};
