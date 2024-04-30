#include "inscription.h"
#include "application.h"
#include "conbd.h"
#include "qmessagebox.h"
#include "ui_inscription.h"
#include "mainwindow.h"
#include "application.h"
#include <string>
#include <QString>
#include <iostream>
#include "DAOutilisateur.h"
using namespace std;

Inscription::Inscription(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Inscription)
{
    ui->setupUi(this);
    setWindowTitle("Inscription");

    lineEdit = findChild<QLineEdit*>("lineEdit");
    lineEdit_2 = findChild<QLineEdit*>("lineEdit_2");
    lineEdit_3 = findChild<QLineEdit*>("lineEdit_3");
    lineEdit_4 = findChild<QLineEdit*>("lineEdit_4");
    lineEdit_5 = findChild<QLineEdit*>("lineEdit_5");
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::on_pushButton_clicked()
{
    close();
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
}

void Inscription::on_pushButton_2_clicked(){
    QString tmp = lineEdit->text();
    string nom = tmp.toStdString();

    tmp = lineEdit_2->text();
    string prenom = tmp.toStdString();

    tmp = lineEdit_3->text();
    string adr = tmp.toStdString();

    tmp = lineEdit_4->text();
    string mail = tmp.toStdString();

    tmp = lineEdit_5->text();
    string mdp = tmp.toStdString();

    if(nom != "" && prenom != "" && adr != "" && mail != "" && mdp != ""){
        DAOutilisateur uti;
        uti.inscriptionUtilisateur(nom, prenom, adr, mail, mdp, db);
        Client* client = dynamic_cast<Client*>(uti.connexionUtilisateur(mail, mdp, db));
        if (client == nullptr){
            QMessageBox msgBox;
            msgBox.setWindowTitle("OULA !");
            msgBox.setText("Ce client n'existe pas :/");
            msgBox.setIcon(QMessageBox::Information);

            // Ajouter un bouton "OK"
            msgBox.addButton(QMessageBox::Ok);

            // Afficher la boîte de message
            msgBox.exec();
        }else{
            close();
            Application* application = new Application(client);
            application->show();
        }
    }else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Oups !");
        msgBox.setText("Tout les champs ne sont pas rempli :/");
        msgBox.setIcon(QMessageBox::Information);

        // Ajouter un bouton "OK"
        msgBox.addButton(QMessageBox::Ok);

        // Afficher la boîte de message
        msgBox.exec();
    }

}

