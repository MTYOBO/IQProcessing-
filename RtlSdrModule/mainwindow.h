#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "DataTypes.h"
#include "AudioProcesser.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    sdr_status_e        sdr_status;
    streaming_btn_status_e  streaming_btn_status;
public:
    MainWindow(QWidget *parent = nullptr);
    AudioProcesser * audioProcesser;
    ~MainWindow();

private slots:
    void on_pbSdr_clicked();

    void on_pbSamples_clicked();

    void on_pbStream_clicked();

    void on_pbRecord_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
