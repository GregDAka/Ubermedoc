#include "application.h"
#include "ui_application.h"
#include "mescommandes.h"
#include "compte.h"
#include "panier.h"
#include "ajoutmedoc.h"

Application::Application(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);
    setWindowTitle("Application");

    pushButton = findChild<QPushButton*>("pushButton");
    pushButton_2 = findChild<QPushButton*>("pushButton_2");
    pushButton_3 = findChild<QPushButton*>("pushButton_3");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");
}

Application::~Application()
{
    delete ui;
}


void Application::on_pushButton_clicked(){
    close();
    MesCommandes* mesCommande = new MesCommandes();
    mesCommande -> show();
}

void Application::on_pushButton_2_clicked(){
    close();
    Compte* compte = new Compte();
    compte -> show();
}

void Application::on_pushButton_3_clicked(){
    close();
    Panier* panier = new Panier();
    panier -> show();
}

void Application::on_pushButton_4_clicked(){
    //ajout medoc pout admin
}
