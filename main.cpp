#include "Tracking.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Tracking w;
	w.show();
	return a.exec();
}
