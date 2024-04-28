#include "connexion.h"
#include "conbd.h"
#include "ui_connexion.h"
#include "mainwindow.h"
#include "DAOutilisateur.h"
#include <iostream>
using namespace std;

Connexion::Connexion(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Connexion)
{
    ui->setupUi(this);
    setWindowTitle("Connexion");

    mailConnexion = findChild<QLineEdit*>("mailConnexion");
    mdpConnexion = findChild<QLineEdit*>("mdpConnexion");
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
    QString tmp = mailConnexion->text();
    string mail = tmp.toStdString();
    tmp = mdpConnexion->text();
    string mdp = tmp.toStdString();
    DAOutilisateur uti;
    Client* client = dynamic_cast<Client*>(uti.connexionUtilisateur(mail, mdp, db));
    if (client == nullptr){
        cout << "Mot de passe ou mail introuvalbe" << endl;
    }else{
        client->afficherDetails();
    }


    // Quand on confirme, les champs entrer sont paramètre d'une requête SQL qui vérifie si l'adresse Mail et le MDP sont présent dans la base.
    // Si oui on créera un objet CLIENT avec le client log, cet objet nous servira plus tard..
}

