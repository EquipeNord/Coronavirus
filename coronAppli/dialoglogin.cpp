#include "dialoglogin.h"
#include "ui_dialoglogin.h"

#define urlLogin "http://lgt-dominique-villars6.pro.dns-orange.fr/~teamjerem/webservices/login.php"
#define urlSignup "http://lgt-dominique-villars6.pro.dns-orange.fr/~teamjerem/webservices/signup.php"

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
    if(champsLogInVerifies()) {
        //verif du user et du pass
        QUrl serviceUrl(urlLogin);
        QUrl donnees;
        QUrlQuery query;
        //ajout de $_POST['user'] et $_POST['mdp']
        query.addQueryItem("user", ui->lineEditLogInUser->text());
        query.addQueryItem("mdp",ui->lineEditLogInPassword->text());
        donnees.setQuery(query);
        QByteArray postData(donnees.toString(QUrl::RemoveFragment).remove(0,1).toLatin1());
        //création de la requête http qui va interroger le service
        QNetworkRequest request(serviceUrl);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        //exécution de la requête http
        QNetworkReply *reply1 = myNWM.post(request,postData);
        //attente de la réception complète de la réponse
        while(!reply1->isFinished())
        {
            qApp->processEvents();
        }
        //lecture de la réponse
        QByteArray response_data = reply1->readAll();
        //affichage pour débugger
        //ui->label_2->setText(response_data);
        //formation du json à partir de la réponse
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);
        //un peu de débogage
        qDebug()<<jsonResponse.object();
        qDebug()<<jsonResponse.object().count();
        //on recoit un tableau de 4 cases: 2 indexées par des entiers et 2 indexées par les noms des champs
        if(jsonResponse.object().count() == 4)
        {
            //recupération des infos (nom, prenom et identifiant sont trois champs renvoyés par la requête sql utilisée par le webService)
            identifiant = jsonResponse.object()["humId"].toString();
            pseudo = jsonResponse.object()["humPseudo"].toString();
            //si c'est bon on ferme la fenêtre de connexion avec un code de retour QDialog::accepted
            accept();
        }
        else
        {
            //identification incorrecte
            ui->labelLogInAlertMessage->setText(tr("Login or password is invalid."));
        }
        //nettoyage de reply1
        reply1->deleteLater();
    } else {

    }
}

bool DialogLogin::champsLogInVerifies()
{
    ui->labelLogInAlertMessage->setText("");
    if(ui->lineEditLogInUser->text().length() < 5 || ui->lineEditLogInPassword->text().length() < 5) {
        ui->labelLogInAlertMessage->setText(tr("Please enter valid login details."));
        return false;
    } else {
        return true;
    }
}

void DialogLogin::on_pushButtonSignUp_clicked()
{
    if(champsSignUpVerifies()) {
        //verif du user, de l'email et du pass
        QUrl serviceUrl(urlSignup);
        QUrl donnees;
        QUrlQuery query;
        //ajout de $_POST['user'], $_POST['email'] et $_POST['mdp']
        query.addQueryItem("user", ui->lineEditSignUpUser->text());
        query.addQueryItem("email", ui->lineEditSignUpEmail->text());
        query.addQueryItem("mdp",ui->lineEditSignUpPassword->text());
        donnees.setQuery(query);
        QByteArray postData(donnees.toString(QUrl::RemoveFragment).remove(0,1).toLatin1());
        //création de la requête http qui va interroger le service
        QNetworkRequest request(serviceUrl);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        //exécution de la requête http
        QNetworkReply *reply2 = myNWM.post(request,postData);
        //attente de la réception complète de la réponse
        while(!reply2->isFinished())
        {
            qApp->processEvents();
        }
        //lecture de la réponse
        QByteArray response_data = reply2->readAll();
        //affichage pour débugger
        ui->labelSignUpAlertMessage->setText(response_data);
        //formation du json à partir de la réponse
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);
        //un peu de débogage
        qDebug()<<jsonResponse.object();
        qDebug()<<jsonResponse.object().count();
        //on recoit un tableau de 4 cases: 2 indexées par des entiers et 2 indexées par les noms des champs
        if(jsonResponse.object().contains("error"))
        {
            qDebug() << jsonResponse.object()["error"].toObject()["code"].toInt();
            switch(jsonResponse.object()["error"].toObject()["code"].toInt()) {
                case 1 : ui->labelSignUpAlertMessage->setText(tr("Username is already taken."));
                         break;
                case 2 : ui->labelSignUpAlertMessage->setText(tr("E-mail address is already taken."));
                         break;
            }
        } else {
            //recupération des infos (nom, prenom et identifiant sont trois champs renvoyés par la requête sql utilisée par le webService)
            identifiant = jsonResponse.object()["humId"].toString();
            pseudo = jsonResponse.object()["humPseudo"].toString();
            //si c'est bon on ferme la fenêtre de connexion avec un code de retour QDialog::accepted
            accept();
        }
        //nettoyage de reply1
        reply2->deleteLater();
    }
}

bool DialogLogin::champsSignUpVerifies()
{
    ui->labelSignUpAlertMessage->setText("");
    if(ui->lineEditSignUpUser->text().length() < 5 || ui->lineEditSignUpEmail->text().length() < 5 || ui->lineEditSignUpPassword->text().length() < 5 || ui->lineEditSignUpPassword2->text().length() < 5) {
        ui->labelSignUpAlertMessage->setText(tr("Please enter valid information."));
        return false;
    } else {
        if(ui->lineEditSignUpPassword->text() != ui->lineEditSignUpPassword2->text()) {
            ui->labelSignUpAlertMessage->setText(tr("Passwords must match."));
            return false;
        } else {
            return true;
        }
    }
}
