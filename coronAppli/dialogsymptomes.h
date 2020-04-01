#ifndef DIALOGSYMPTOMES_H
#define DIALOGSYMPTOMES_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QCheckBox>

namespace Ui {
class DialogSymptomes;
}

class DialogSymptomes : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSymptomes(QNetworkAccessManager *pmyNWM, QString leId, bool saisieAdresse, bool saisieEtatJour, QWidget *parent = nullptr);
    QString identifiant;
    QNetworkAccessManager * myNWM;
    ~DialogSymptomes();

private:
    Ui::DialogSymptomes *ui;
};

#endif // DIALOGSYMPTOMES_H
