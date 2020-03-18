#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogpdf.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSeeCertificate_clicked()
{
    DialogPDF afficheFenetrePDF;
    afficheFenetrePDF.exec();
}
