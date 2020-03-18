#include "mainwindow.h"
#include "dialoglogin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogLogin dLogin;
    if(dLogin.exec() == QDialog::Accepted) {
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        return 255;
    }

}
