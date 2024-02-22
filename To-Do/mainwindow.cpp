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
    QListWidgetItem* item = new QListWidgetItem(ui->lineEdit->text(), ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
}


void MainWindow::on_pushButton_2_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
}

