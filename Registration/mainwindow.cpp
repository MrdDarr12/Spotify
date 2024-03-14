#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filePath = "/Users/martin/Downloads/Spotify project/Registration/registration_data.txt";

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onSerializeClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onDeserializeClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSerializeClicked()
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file");
        return;
    }

    QTextStream out(&file);
    out << ui->lineEdit->text() << "\n";
    out << ui->spinBox->value() << "\n";
    out << ui->spinBox_2->value() << "\n";
    out << ui->spinBox_4->value() << "\n";
    out << ui->spinBox_3->value() << "\n";

    file.close();
}

void MainWindow::onDeserializeClicked()
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file");
        return;
    }

    QTextStream in(&file);
    QString name = in.readLine();
    int age = in.readLine().toInt();
    int day = in.readLine().toInt();
    int month = in.readLine().toInt();
    int year = in.readLine().toInt();

    file.close();

    qDebug() << name << "\n" << age << "\n" << day << "." << month << "." << year << "\n";
}
