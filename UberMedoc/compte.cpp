#include "compte.h"
#include "ui_compte.h"
#include "mescommandes.h"
#include "panier.h"
#include "application.h"

Compte::Compte(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Compte)
{
    ui->setupUi(this);

    pushButton = findChild<QPushButton*>("pushButton");
    pushButton_2 = findChild<QPushButton*>("pushButton_2");
    pushButton_5 = findChild<QPushButton*>("pushButton_5");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");
}

Compte::~Compte()
{
    delete ui;
}

void Compte::on_pushButton_clicked(){
    close();
    MesCommandes* mesCommande = new MesCommandes();
    mesCommande -> show();
}

void Compte::on_pushButton_2_clicked(){
    close();
    Application* app = new Application();
    app -> show();
}

void Compte::on_pushButton_5_clicked(){
    //
}

void Compte::on_pushButton_4_clicked(){
    close();
    Panier* panier = new Panier();
    panier -> show();
}
