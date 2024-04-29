#include "mescommandes.h"
#include "ui_mescommandes.h"
#include "application.h"
#include "panier.h"
#include "compte.h"


MesCommandes::MesCommandes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MesCommandes)
{
    ui->setupUi(this);

    pushButton_2 = findChild<QPushButton*>("pushButton");
    pushButton_5 = findChild<QPushButton*>("pushButton_5");
    pushButton_3 = findChild<QPushButton*>("pushButton_3");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");
}

MesCommandes::~MesCommandes()
{
    delete ui;
}

void MesCommandes::on_pushButton_2_clicked(){
    close();
    Application* mesCommande = new Application();
    mesCommande -> show();
}

void MesCommandes::on_pushButton_5_clicked(){
    //
}

void MesCommandes::on_pushButton_4_clicked(){
    close();
    Panier* panier = new Panier();
    panier -> show();
}

void MesCommandes::on_pushButton_3_clicked(){
    close();
    Compte* compte = new Compte();
    compte -> show();
}
