#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_2->setText("Count " + QString::number(++value));
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().isEmpty()) {
        msgBox.setText("Empty Box.");
        msgBox.exec();
    } else {
        ui->lineEdit->setText("All Done!");
        ui->lineEdit->clear();
    }
}

