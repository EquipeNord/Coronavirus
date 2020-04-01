#include "dialogpdf.h"
#include "ui_dialogpdf.h"

#include <QPrinter>
#include <QPrinterInfo>
#include <QtWidgets>
#include <QSqlQuery>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextEdit>
#include <QtCore>
#include <QTextDocument>
#include <QString>
#include <QUrl>
#include <QPixmap>
#include <QScrollArea>
#include <QFile>
#include <poppler/qt5/poppler-qt5.h>

DialogPDF::DialogPDF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPDF)
{
    ui->setupUi(this);
    displayCertificate();
}

DialogPDF::~DialogPDF()
{
    delete ui;
}

void DialogPDF::displayCertificate()
{
qDebug() << "DialogPDF::displayCertificate()";

    QString certificateUrl = "/home/theo/Documents/Cours/BTS SIO 2/SLAM4/Qt/opeTrackCorona/Coronavirus/attestation_de_deplacement_derogatoire.pdf";
    int pageNumber=0;

    Poppler::Document* certificate = Poppler::Document::load(certificateUrl);

    if (!certificate || certificate->isLocked())
    {

      qDebug() << "Error 1";

      delete certificate;
      return;
    }

    // Access page of the PDF file

    Poppler::Page* pdfPage = certificate->page(pageNumber);  // Document starts at page 0
    if (pdfPage == 0)
    {
      qDebug() << "Error 2";
      return;
    }

    // Generate a QImage of the rendered page

    QImage imageCertificate = pdfPage->renderToImage(); //xres, yres, x, y, width, height
    if (imageCertificate.isNull())
    {
      qDebug() << "Error 3";
      return;
    }

    // Affichage du QPixmap contenant l'aperçu du fichier PDF

    QPixmap imagePixmap;
    imagePixmap=QPixmap::fromImage(imageCertificate);
    ui->labelPixmap->setPixmap(imagePixmap);

    // After the usage, the page must be deleted

    delete pdfPage;
}

void DialogPDF::on_pushButtonDownload_clicked()
{
qDebug() << "DialogPDF::on_pushButtonDownload_clicked()";

    // Télécharger le document

    // On déclare une variable nomFichier qui reçoit le chemin choisi

    QString fichierUrl="/home/theo/Documents/Cours/BTS SIO 2/SLAM4/Qt/opeTrackCorona/Coronavirus/attestation_de_deplacement_derogatoire.pdf";

    QString nomFichier=QFileDialog::getSaveFileName(0, QString::fromUtf8("Générer un fichier PDF"), QCoreApplication::applicationDirPath(), "*.pdf");

    QFile::copy(fichierUrl, nomFichier);

    if(QFileInfo(nomFichier).suffix().isEmpty())
    {
        // On le fixe en .pdf

        nomFichier.append(".pdf");
    }
}

void DialogPDF::on_pushButtonClose_clicked()
{
    this->accept();
}
