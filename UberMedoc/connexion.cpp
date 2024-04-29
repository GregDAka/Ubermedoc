#include "connexion.h"
#include "adminapp.h"
#include "conbd.h"
#include "qmessagebox.h"
#include "ui_connexion.h"
#include "mainwindow.h"
#include "DAOutilisateur.h"
#include <string>
#include "application.h"
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
    Utilisateur* u = uti.connexionUtilisateur(mail, mdp, db);
    if (u == nullptr){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Oups !");
        msgBox.setText("Mot de passe ou mail incorrect");
        msgBox.setIcon(QMessageBox::Information);

        // Ajouter un bouton "OK"
        msgBox.addButton(QMessageBox::Ok);

        // Afficher la boîte de message
        msgBox.exec();
    }else{
        if (!uti.estAdmin(mail, mdp, db)){
            Client* client = dynamic_cast<Client*>(u);
            close();
            Application* app = new Application(client);
            app->show();
        }else{
            close();
            AdminApp* app = new AdminApp();
            app->show();
        }
    }



    // Quand on confirme, les champs entrer sont paramètre d'une requête SQL qui vérifie si l'adresse Mail et le MDP sont présent dans la base.
    // Si oui on créera un objet CLIENT avec le client log, cet objet nous servira plus tard..
}

