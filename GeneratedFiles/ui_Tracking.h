/********************************************************************************
** Form generated from reading UI file 'Tracking.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKING_H
#define UI_TRACKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrackingClass
{
public:
    QWidget *centralWidget;
    QPushButton *btnStartStop;
    QLabel *lblOriginal;
    QLabel *lblProcessed;

    void setupUi(QMainWindow *TrackingClass)
    {
        if (TrackingClass->objectName().isEmpty())
            TrackingClass->setObjectName(QStringLiteral("TrackingClass"));
        TrackingClass->resize(1309, 751);
        centralWidget = new QWidget(TrackingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnStartStop = new QPushButton(centralWidget);
        btnStartStop->setObjectName(QStringLiteral("btnStartStop"));
        btnStartStop->setGeometry(QRect(730, 580, 121, 31));
        lblOriginal = new QLabel(centralWidget);
        lblOriginal->setObjectName(QStringLiteral("lblOriginal"));
        lblOriginal->setGeometry(QRect(0, 70, 640, 480));
        lblOriginal->setFrameShape(QFrame::Box);
        lblProcessed = new QLabel(centralWidget);
        lblProcessed->setObjectName(QStringLiteral("lblProcessed"));
        lblProcessed->setGeometry(QRect(650, 70, 640, 480));
        lblProcessed->setFrameShape(QFrame::Box);
        TrackingClass->setCentralWidget(centralWidget);

        retranslateUi(TrackingClass);

        QMetaObject::connectSlotsByName(TrackingClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrackingClass)
    {
        TrackingClass->setWindowTitle(QApplication::translate("TrackingClass", "Tracking", 0));
        btnStartStop->setText(QApplication::translate("TrackingClass", "Start Camera", 0));
        lblOriginal->setText(QString());
        lblProcessed->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrackingClass: public Ui_TrackingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKING_H
