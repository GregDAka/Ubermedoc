#include "application.h"
#include "ui_application.h"
#include "client.h"
#include "mescommandes.h"
#include "compte.h"
#include "panier.h"
#include "conbd.h"
#include <iostream>
#include "DAOmedicament.h"
#include <QMessageBox>
using namespace std ;

Application::Application(Client* client, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Application)
    , m_client(client)
{
    ui->setupUi(this);
    setWindowTitle("Application");



    if(m_client != nullptr){
        QString nom = QString::fromStdString(m_client->getNom());
        QString prenom = QString::fromStdString(m_client->getPrenom());

        //mise à jour des labels
        ui->nomLabel->setText(nom);
        ui->prenomLabel->setText(prenom);
    }

    pushButton = findChild<QPushButton*>("pushButton");
    pushButton_2 = findChild<QPushButton*>("pushButton_2");
    pushButton_3 = findChild<QPushButton*>("pushButton_3");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");

    label_2 = ui->label_2;
    label_3 = ui->label_3;

    QStringList list;

    QSqlQuery query(db);
    if (query.exec("SELECT nom FROM medicament") ) {
        while(query.next()){
            QString nomMedicament = query.value("nom").toString();
            list.append(nomMedicament);
        }
    }
    // On créer un model avec la liste qu'on vient de créer.
    QStringListModel *model = new QStringListModel(list, this);
    // Associer le modèle à la QListView
    ui->listView->setModel(model);
    connect(ui->listView, &QListView::clicked, this, &Application::onListViewClicked);

}

Application::~Application()
{
    delete ui;
}



void Application::on_pushButton_clicked(){
    close();
    MesCommandes* mesCommande = new MesCommandes(m_client);
    mesCommande -> show();
}

void Application::on_pushButton_2_clicked(){
    close();
    Compte* compte = new Compte(m_client);
    compte -> show();
}

void Application::on_pushButton_3_clicked(){
    close();
    Panier* panier = new Panier(m_client);
    panier -> show();
}

void Application::on_pushButton_4_clicked(){
    DAOmedicament rqMedoc;
    Medicament* medoc = rqMedoc.ObjetMedoc(recupClic,db);
    m_client->ajouterAuPanier(medoc);

    QMessageBox msgBox;
    msgBox.setWindowTitle("Bonne nouvelle");
    msgBox.setText("Médicament ajouté");
    msgBox.setIcon(QMessageBox::Information);

    // Ajouter un bouton "OK"
    msgBox.addButton(QMessageBox::Ok);

    // Afficher la boîte de message
    msgBox.exec();

}

void Application::onListViewClicked(const QModelIndex &index){
    QString text = index.data(Qt::DisplayRole).toString();
    recupClic = text.toStdString();
    modifMedocSelec(recupClic);
}

void Application::modifMedocSelec(string medocselec){
    DAOmedicament rqMedoc ;
    Medicament* medoc = rqMedoc.ObjetMedoc(medocselec,db) ;

    // On converti le nom du médicament de type String récupéré par le GET en Qstring pour pouvoir changer le Label
    QString nomConvert = QString::fromStdString(medoc->getNom());
    label_2->setText(nomConvert); // Label_2 fait référence au Label (text) Label_2 dans l'application.ui.

    // On fait la même chose pour le prix, sauf qu'on converti le prix(double) en String.
    QString prixConverti = QString::number(medoc->getPrix());
    label_3->setText(prixConverti) ;

}

