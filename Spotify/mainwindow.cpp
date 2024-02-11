#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize player and audio output
    Player = new QMediaPlayer(this);
    AudioOutput = new QAudioOutput(this);
    Player->setAudioOutput(AudioOutput);
    AudioOutput->setVolume(50);

    // Connect signals and slots
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readMusicData);

    // Connect button signals to slots
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::on_playButton_clicked);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::on_pauseButton_clicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::on_stopButton_clicked);

    // Connect to the server
    socket->connectToHost("localhost", 54678);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete socket;
    delete AudioOutput;
}

void MainWindow::onConnected()
{
    qDebug() << "Connected to server";
}

void MainWindow::readMusicData()
{
    QByteArray musicData = socket->readAll();
    buffer.append(musicData); // Append received data to the buffer

    if (buffer.isEmpty()) {
        qDebug() << "No music data received";
        return;
    }

    QString fileName = QCoreApplication::applicationDirPath() + "/received_music.mp3"; // Save received music to a file
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing";
        return;
    }
    file.write(buffer);
    file.close();

    Player->setSource(QUrl::fromLocalFile(fileName));
}

void MainWindow::on_playButton_clicked()
{
    Player->play();
}

void MainWindow::on_pauseButton_clicked()
{
    Player->pause();
}

void MainWindow::on_stopButton_clicked()
{
    Player->stop();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    AudioOutput->setVolume(value);
}
