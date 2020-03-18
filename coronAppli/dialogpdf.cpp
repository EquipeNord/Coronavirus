#include "dialogpdf.h"
#include "ui_dialogpdf.h"

DialogPDF::DialogPDF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPDF)
{
    ui->setupUi(this);
}

DialogPDF::~DialogPDF()
{
    delete ui;
}

void DialogPDF::on_pushButtonClose_clicked()
{
    reject();
}
