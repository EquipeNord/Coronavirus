#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private slots:
    void on_pushButtonCreateAccount_clicked();

    void on_pushButtonLogInAccount_clicked();

    void on_pushButtonLogIn_clicked();

    void on_pushButtonSignUp_clicked();

private:
    Ui::DialogLogin *ui;
};

#endif // DIALOGLOGIN_H
