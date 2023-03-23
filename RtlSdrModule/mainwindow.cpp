#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sdr_status            = SDR_NONE;
    streaming_btn_status  = STREAM_BTN_START;
    audioProcesser        = new AudioProcesser();
}

MainWindow::~MainWindow()
{
    delete audioProcesser;
    delete ui;
}


void MainWindow::on_pbSdr_clicked()
{
    if(sdr_status == SDR_STOPPED || sdr_status == SDR_NONE)
    {
      if(audioProcesser->OpenSdr() == 0)
      {
          sdr_status = SDR_RUNNING;
          ui->pbSdr->setText("Close \n SDR");
      }
    }
    else if(sdr_status == SDR_RUNNING)
    {
      audioProcesser->CloseSdr();
      ui->pbSdr->setText("Open \n SDR");
      sdr_status = SDR_STOPPED;
    }
    else
    {
      sdr_status = SDR_NONE;
    }
}


void MainWindow::on_pbSamples_clicked()
{

}


void MainWindow::on_pbStream_clicked()
{

}


void MainWindow::on_pbRecord_clicked()
{

}


