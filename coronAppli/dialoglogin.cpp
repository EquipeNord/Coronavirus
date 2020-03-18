#include "dialoglogin.h"
#include "ui_dialoglogin.h"

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    //ajustements graphiques
    ui->labelLogInAlertMessage->setText("");
    ui->labelSignUpAlertMessage->setText("");
    ui->widgetCreateAccount->hide();
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_pushButtonCreateAccount_clicked()
{
    //ajustements graphiques
    ui->labelSignUpAlertMessage->setText("");
    ui->widgetLogIn->hide();
    ui->widgetCreateAccount->show();
    ui->pushButtonSignUp->setDefault(true);
}

void DialogLogin::on_pushButtonLogInAccount_clicked()
{
    //ajustements graphiques
    ui->labelLogInAlertMessage->setText("");
    ui->widgetLogIn->show();
    ui->widgetCreateAccount->hide();
    ui->pushButtonLogIn->setDefault(true);
}

void DialogLogin::on_pushButtonLogIn_clicked()
{

}

void DialogLogin::on_pushButtonSignUp_clicked()
{

}
