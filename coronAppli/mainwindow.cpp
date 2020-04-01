#include "mainwindow.h"
#include "ui_mainwindow.h"

#define urlVerifs "http://lgt-dominique-villars6.pro.dns-orange.fr/~teamjerem/webservices/verifs.php"

MainWindow::MainWindow(QNetworkAccessManager *pmyNWM, QString leId, QString lePseudo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myNWM = pmyNWM;
    humId = leId;
    humPseudo = lePseudo;
    ui->labelId->setText('[' + humId + ']');
    ui->labelUser->setText(humPseudo);
    verifSaisies();
}

void MainWindow::verifSaisies()
{
    QUrl serviceUrl(urlVerifs);
    QUrl donnees;
    QUrlQuery query;
    //ajout de $_POST['user'] et $_POST['mdp']
    query.addQueryItem("humId", humId);
    donnees.setQuery(query);
    QByteArray postData(donnees.toString(QUrl::RemoveFragment).remove(0,1).toLatin1());
    //préparation de la requête http
    QNetworkRequest request(serviceUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    //reply est une QNetworkReply* déclarée dans le .h de la classe on exécute la requête http
    QNetworkReply *reply1 = myNWM->post(request, postData);
    //attente de la réception complète de la réponse
    while(!reply1->isFinished()) {
        qApp->processEvents();
    }
    //lecture de la réponse
    QByteArray response_data = reply1->readAll();
    //affichage pour débugger
    //ui->labelDebug->setText(response_data);
    //formation du json à partir de la réponse
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);
    //un peu de débogage
    qDebug()<<jsonResponse.object();
    qDebug()<<jsonResponse.object().count();
    //on recoit un tableau de 4 cases: 2 indexées par des entiers et 2 indexées par les noms des champs
    if(jsonResponse.object().count() == 2) {
        bool saisieAdresse = jsonResponse.object()["saisieAdresse"].toBool();
        bool saisieEtatJour = jsonResponse.object()["saisieEtatJour"].toBool();
        if(saisieAdresse && saisieEtatJour == 0) {
            qDebug() << "il manque un truc";
            DialogSymptomes dSymptomes(myNWM, humId, saisieAdresse, saisieEtatJour);
            dSymptomes.exec();
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
