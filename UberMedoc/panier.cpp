#include "panier.h"
#include "ui_panier.h"
#include "mescommandes.h"
#include "compte.h"
#include "application.h"


Panier::Panier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Panier)
{
    ui->setupUi(this);

    pushButton = findChild<QPushButton*>("pushButton");
    pushButton_2 = findChild<QPushButton*>("pushButton_2");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");
    pushButton_5 = findChild<QPushButton*>("pushButton_5");
    pushButton_6 = findChild<QPushButton*>("pushButton_6");
    pushButton_7 = findChild<QPushButton*>("pushButton_7");
    pushButton_8 = findChild<QPushButton*>("pushButton_8");
}

Panier::~Panier()
{
    delete ui;
}

void Panier::on_pushButton_clicked(){
    close();
    MesCommandes* mesCommande = new MesCommandes();
    mesCommande -> show();
}

void Panier::on_pushButton_2_clicked(){
    close();
    Compte* compte = new Compte();
    compte -> show();
}

void Panier::on_pushButton_4_clicked(){
    //comander panier
}

void Panier::on_pushButton_5_clicked(){
    //solde +1
}

void Panier::on_pushButton_6_clicked(){
    //solde +10
}

void Panier::on_pushButton_7_clicked(){
    //solde +25
}

void Panier::on_pushButton_8_clicked(){
    close();
    Application* app = new Application();
    app -> show();
}
