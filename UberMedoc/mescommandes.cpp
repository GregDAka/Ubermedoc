#include "mescommandes.h"
#include "ui_mescommandes.h"
#include "application.h"
#include "panier.h"
#include "compte.h"


MesCommandes::MesCommandes(Client* cl, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MesCommandes)
{
    ui->setupUi(this);
    setWindowTitle("Mes commandes");
    m_client = cl;

    pushButton_2 = findChild<QPushButton*>("pushButton");
    pushButton_5 = findChild<QPushButton*>("pushButton_5");
    pushButton_3 = findChild<QPushButton*>("pushButton_3");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");
    label = findChild<QLabel*>("label");
    label_2 = findChild<QLabel*>("label_2");

    if(m_client != nullptr){
        QString nom = QString::fromStdString(m_client->getNom());
        QString prenom = QString::fromStdString(m_client->getPrenom());

        //mise à jour des labels
        ui->label->setText(nom);
        ui->label_2->setText(prenom);
    }
}

MesCommandes::~MesCommandes()
{
    delete ui;
}

void MesCommandes::on_pushButton_2_clicked(){
    close();
    Application* mesCommande = new Application(m_client);
    mesCommande -> show();
}

void MesCommandes::on_pushButton_5_clicked(){
    //
}

void MesCommandes::on_pushButton_4_clicked(){
    close();
    Panier* panier = new Panier(m_client);
    panier -> show();
}

void MesCommandes::on_pushButton_3_clicked(){
    close();
    Compte* compte = new Compte(m_client);
    compte -> show();
}
