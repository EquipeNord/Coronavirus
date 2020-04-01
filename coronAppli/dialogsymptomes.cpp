#include "dialogsymptomes.h"
#include "ui_dialogsymptomes.h"

DialogSymptomes::DialogSymptomes(QNetworkAccessManager *pmyNWM, QString leId, bool saisieAdresse, bool saisieEtatJour, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSymptomes)
{
    myNWM = pmyNWM;
    identifiant = leId;
    ui->setupUi(this);
    qDebug() << identifiant << saisieAdresse << saisieEtatJour;
}

DialogSymptomes::~DialogSymptomes()
{
    delete ui;
}
