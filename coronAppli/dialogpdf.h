#ifndef DIALOGPDF_H
#define DIALOGPDF_H

#include <QDialog>

namespace Ui {
class DialogPDF;
}

class DialogPDF : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPDF(QWidget *parent = 0);
    ~DialogPDF();

private slots:
    void on_pushButtonClose_clicked();

private:
    Ui::DialogPDF *ui;
};

#endif // DIALOGPDF_H
