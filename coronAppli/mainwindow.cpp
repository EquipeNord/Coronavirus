#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QNetworkAccessManager *pmyNWM, QString leId, QString lePseudo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myNWM = pmyNWM;
    humId = leId;
    humPseudo = lePseudo;
    ui->labelId->setText('[' + humId + ']');
    ui->labelUser->setText(humPseudo);
}

MainWindow::~MainWindow()
{
    delete ui;
}
