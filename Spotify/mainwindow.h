#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtMultimedia>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readMusicData();
    void onConnected();

    void on_pauseButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_stopButton_clicked();

    void on_playButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QMediaPlayer *Player;
    QByteArray buffer;
    QAudioOutput *AudioOutput;
};

#endif // MAINWINDOW_H

