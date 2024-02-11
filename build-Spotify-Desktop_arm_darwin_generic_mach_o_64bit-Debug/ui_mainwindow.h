/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPushButton *playButton;
    QPushButton *stopButton;
    QPushButton *pauseButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(542, 236);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName("playButton");
        playButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 50%; /* make button circular */\n"
"	background-color: rgb(88, 175, 158);\n"
"    color: white; /* text color */\n"
"    padding: 10px 20px; /* adjust padding for better appearance */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049; /* darker green on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #367c3a; /* even darker green when pressed */\n"
"}"));

        gridLayout_2->addWidget(playButton, 0, 0, 1, 1);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName("stopButton");
        stopButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 50%; /* make button circular */\n"
"    background-color: rgb(88, 175, 158);\n"
"    color: white; /* text color */\n"
"    padding: 10px 20px; /* adjust padding for better appearance */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1e88e5; /* darker blue on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1976d2; /* even darker blue when pressed */\n"
"}"));

        gridLayout_2->addWidget(stopButton, 2, 0, 1, 1);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setEnabled(true);
        pauseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 50%; /* make button circular */\n"
"    background-color: rgb(88, 175, 158);\n"
"    color: white; /* text color */\n"
"    padding: 10px 20px; /* adjust padding for better appearance */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #d32f2f; /* darker red on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c; /* even darker red when pressed */\n"
"}"));

        gridLayout_2->addWidget(pauseButton, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
