#include "adminapp.h"
#include "DAOmedicament.h"
#include "ajoutmedoc.h"
#include "conbd.h"
#include "mainwindow.h"
#include "qsqlquery.h"
#include "qstringlistmodel.h"
#include <QApplication>
#include "ui_adminapp.h"
#include "ajoutmedoc.h"
#include "application.h"
#include "client.h"
#include "conbd.h"
#include "DAOmedicament.h"
#include <QMessageBox>

AdminApp::AdminApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminApp)
{
    ui->setupUi(this);


    pushButton = findChild<QPushButton*>("pushButton");

    label_4 = ui->label_4;
    label_3 = ui->label_3;

    QStringList list;

    // On récupère tous les médicaments de la BD et on les ajoute à la liste.

    setWindowTitle("Application ADMIN");

    QSqlQuery query(db);
    if (query.exec("SELECT nom FROM medicament") ) {
        while(query.next()){
            QString nomMedicament = query.value("nom").toString();
            list.append(nomMedicament);
        }
        // On créer un model avec la liste qu'on vient de créer.
        QStringListModel *model = new QStringListModel(list, this);
        // Associer le modèle à la QListView
        ui->listView->setModel(model);
        connect(ui->listView, &QListView::clicked, this, &AdminApp::onListViewClicked);
    }
}

AdminApp::~AdminApp()
{
    delete ui;
}

void AdminApp::on_pushButton_clicked(){
    close();
    AjoutMedoc* ajout = new AjoutMedoc();
    ajout -> show();
}

void AdminApp::on_pushButton_4_clicked(){
    close();
    MainWindow* main = new MainWindow();
    main -> show();
}


void AdminApp::onListViewClicked(const QModelIndex &index){
    QString text = index.data(Qt::DisplayRole).toString();
    recupClic = text.toStdString();
    modifMedocSelec(recupClic);
}

void AdminApp::modifMedocSelec(string medocselec){
    DAOmedicament rqMedoc ;
    Medicament* medoc = rqMedoc.ObjetMedoc(medocselec,db) ;

    // On converti le nom du médicament de type String récupéré par le GET en Qstring pour pouvoir changer le Label
    QString nomConvert = QString::fromStdString(medoc->getNom());
    label_3->setText(nomConvert); // Label_2 fait référence au Label (text) Label_2 dans l'application.ui.

    // On fait la même chose pour le prix, sauf qu'on converti le prix(double) en String.
    QString prixConverti = QString::number(medoc->getPrix());
    label_4->setText(prixConverti) ;


}

