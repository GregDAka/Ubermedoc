#include "connexion.h"
#include "ui_connexion.h"
#include "mainwindow.h"

Connexion::Connexion(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Connexion)
{
    ui->setupUi(this);
    setWindowTitle("Connexion");
}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_btnRetour_clicked()
{
    close();
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
}


void Connexion::on_btnConfirmer_clicked()
{
    // Quand on confirme, les champs entrer sont paramètre d'une requête SQL qui vérifie si l'adresse Mail et le MDP sont présent dans la base.
    // Si oui on créera un objet CLIENT avec le client log, cet objet nous servira plus tard..
}

