#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkCookieJar>
#include <QUrl>
#include <QUrlQuery>
#include <QByteArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    QString identifiant, pseudo;
    QNetworkAccessManager myNWM;
    QNetworkCookieJar cookieJar;
    ~DialogLogin();

private slots:
    void on_pushButtonCreateAccount_clicked();

    void on_pushButtonLogInAccount_clicked();

    void on_pushButtonLogIn_clicked();

    void on_pushButtonSignUp_clicked();

    bool champsLogInVerifies();
    bool champsSignUpVerifies();
private:
    Ui::DialogLogin *ui;
};

#endif // DIALOGLOGIN_H
