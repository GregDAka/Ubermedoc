#include "compte.h"
#include "mainwindow.h"
#include "ui_compte.h"
#include "mescommandes.h"
#include "panier.h"
#include "application.h"

Compte::Compte(Client* cl, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Compte)
{
    ui->setupUi(this);
    setWindowTitle("Mon compte");

    m_client = cl;

    pushButton = findChild<QPushButton*>("pushButton");
    pushButton_2 = findChild<QPushButton*>("pushButton_2");
    pushButton_5 = findChild<QPushButton*>("pushButton_5");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");
    label = findChild<QLabel*>("label");
    label_2 = findChild<QLabel*>("label_2");

    if(m_client != nullptr){
        QString nom = QString::fromStdString(m_client->getNom());
        QString prenom = QString::fromStdString(m_client->getPrenom());
        QString mail = QString::fromStdString(m_client->getMail());
        QString mdp = QString::fromStdString(m_client->getMdp());
        QString adresse = QString::fromStdString(m_client->getAdresse());


        //mise à jour des labels
        ui->label->setText(nom);
        ui->label_2->setText(prenom);
        ui->label_8->setText(nom);
        ui->label_9->setText(prenom);
        ui->label_10->setText(mail);
        ui->label_11->setText(mdp);
        ui->label_12->setText(adresse);
    }
}

Compte::~Compte()
{
    delete ui;
}

void Compte::on_pushButton_clicked(){
    close();
    MesCommandes* mesCommande = new MesCommandes(m_client);
    mesCommande -> show();
}

void Compte::on_pushButton_2_clicked(){
    close();
    Application* app = new Application(m_client);
    app -> show();
}

void Compte::on_pushButton_5_clicked(){
    //
}

void Compte::on_pushButton_4_clicked(){
    close();
    Panier* panier = new Panier(m_client);
    panier -> show();
}

void Compte::on_deconnexion_clicked(){
    close();
    MainWindow* main = new MainWindow();
    main -> show();
}

