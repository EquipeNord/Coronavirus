#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "dialoglogin.h"
#include "dialogsymptomes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QNetworkAccessManager *pmyNWM, QString leId, QString lePseudo, QWidget *parent = 0);
    ~MainWindow();

    void verifSaisies();
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager * myNWM;
    QString humId, humPseudo;
};

#endif // MAINWINDOW_H
