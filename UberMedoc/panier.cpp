#include "panier.h"
#include "ui_panier.h"
#include "mescommandes.h"
#include "compte.h"
#include "application.h"
#include <string>
#include <QMessageBox>
#include "client.h"
#include "conBd.h"
#include "DAOutilisateur.h"
#include "DAOcommande.h"


Panier::Panier(Client* cl, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Panier)
{
    ui->setupUi(this);
    setWindowTitle("Mon panier");
    m_client = cl;

    pushButton = findChild<QPushButton*>("pushButton");
    pushButton_2 = findChild<QPushButton*>("pushButton_2");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");
    pushButton_5 = findChild<QPushButton*>("pushButton_5");
    pushButton_6 = findChild<QPushButton*>("pushButton_6");
    pushButton_7 = findChild<QPushButton*>("pushButton_7");
    pushButton_8 = findChild<QPushButton*>("pushButton_8");
    label = findChild<QLabel*>("label");
    label_2 = findChild<QLabel*>("label_2");

    if(m_client != nullptr){
        QString nom = QString::fromStdString(m_client->getNom());
        QString prenom = QString::fromStdString(m_client->getPrenom());
        QString total = QString::fromStdString(to_string(m_client->getTotalPanier()));
        QString solde = QString::fromStdString(to_string(m_client->getSolde()));

        //mise à jour des labels
        ui->label->setText(nom);
        ui->label_2->setText(prenom);
        ui->label_8->setText(total);
        ui->label_5->setText(solde);
    }


    QStringList list;
    QString nomMedicament;
    string stringtmp;
    for (const auto& entry : m_client->getPanier()) {
        stringtmp = entry.first->getNom() + " " + to_string(entry.second) + " unitée(s)";
        nomMedicament = QString::fromStdString(stringtmp);
        list.append(nomMedicament);
    }

    // On créer un model avec la liste qu'on vient de créer.
    QStringListModel *model = new QStringListModel(list, this);
    // Associer le modèle à la QListView

    ui->listView->setModel(model);
    //connect(ui->listView, &QListView::clicked, this, &Application::onListViewClicked);

    //m_client->afficherDetails();
}

Panier::~Panier()
{
    delete ui;
}

void Panier::on_pushButton_clicked(){
    close();
    MesCommandes* mesCommande = new MesCommandes(m_client);
    mesCommande -> show();
}

void Panier::on_pushButton_2_clicked(){
    close();
    Compte* compte = new Compte(m_client);
    compte -> show();
}

void Panier::on_pushButton_4_clicked(){


    if (m_client->getTotalPanier() <= m_client->getSolde()){
        if(!m_client->getPanier().empty()){

            DAOcommande rqCommande;
            DAOutilisateur rqUtil;
            int idClient = rqUtil.getIdClientDAO(m_client->getMail(),db);
            rqCommande.createCommande(idClient,db);
            int idCommande = rqCommande.getIdCommande(idClient,db);

            for (const auto& entry : m_client->getPanier()) {
                Medicament* medicament = entry.first;
                int quantite = entry.second;
                rqCommande.createLigneCommande(idCommande,medicament->getRef(),quantite,db);
            }

            m_client->retirerSolde(m_client->getTotalPanier());
            m_client->viderPanier();
            close();
            MesCommandes* mesCommande = new MesCommandes(m_client);
            mesCommande -> show();
            //insertion commande dans la bd
        }else{
            // Créer une boîte de message
            QMessageBox msgBox;
            msgBox.setWindowTitle("Pas si vite...");
            msgBox.setText("Panier vide !");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setFixedSize(800, 400);
            // Ajouter un bouton "OK"
            msgBox.addButton(QMessageBox::Ok);

            // Afficher la boîte de message
            msgBox.exec();
        }
    }else{
        // Créer une boîte de message
        QMessageBox msgBox;
        msgBox.setWindowTitle("Pas si vite...");
        msgBox.setText("Solde insuffisant !");
        msgBox.setIcon(QMessageBox::Information);

        // Ajouter un bouton "OK"
        msgBox.addButton(QMessageBox::Ok);

        // Afficher la boîte de message
        msgBox.exec();
    }


}

void Panier::on_pushButton_5_clicked(){
    m_client->ajouterSolde(1);
    QString solde = QString::fromStdString(to_string(m_client->getSolde()));
    ui->label_5->setText(solde);
}

void Panier::on_pushButton_6_clicked(){
    m_client->ajouterSolde(10);
    QString solde = QString::fromStdString(to_string(m_client->getSolde()));
    ui->label_5->setText(solde);
}

void Panier::on_pushButton_7_clicked(){
    m_client->ajouterSolde(25);
    QString solde = QString::fromStdString(to_string(m_client->getSolde()));
    ui->label_5->setText(solde);
}

void Panier::on_pushButton_8_clicked(){
    close();
    Application* app = new Application(m_client);
    app -> show();
}
