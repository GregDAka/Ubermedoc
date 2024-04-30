#include "ajoutmedoc.h"
#include "DAOmedicament.h"
#include "adminapp.h"
#include "qmessagebox.h"
#include "ui_ajoutmedoc.h"
#include "conBd.h"
#include "DAOmedicament.h"
#include <iostream>
#include <string>
using namespace std;

AjoutMedoc::AjoutMedoc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutMedoc)
{
    ui->setupUi(this);
    setWindowTitle("Ajout médicament");

    pushButton = findChild<QPushButton*>("pushButton");
    pushButton_2 = findChild<QPushButton*>("pushButton_2");
    lineEdit = findChild<QLineEdit*>("lineEdit");
    lineEdit_2 = findChild<QLineEdit*>("lineEdit_2");
}

AjoutMedoc::~AjoutMedoc()
{
    delete ui;
}

void AjoutMedoc::on_pushButton_clicked(){
    close();
    AdminApp* app = new AdminApp();
    app -> show();
}

void AjoutMedoc::on_pushButton_2_clicked(){
    QString tmp = lineEdit->text();
    string nom = tmp.toStdString();
    tmp = lineEdit_2->text();
    bool ok; // variable booléenne pour indiquer si la conversion a réussi
    double prix = tmp.toDouble(&ok);
    if (nom != "" && prix != NULL){
        DAOmedicament med;
        med.ajouterMedoc(nom, prix, db);
        close();
        AdminApp* app = new AdminApp();
        app -> show();
    }else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Pas si vite...");
        msgBox.setText("Nom ou prix vide");
        msgBox.setIcon(QMessageBox::Information);

        // Ajouter un bouton "OK"
        msgBox.addButton(QMessageBox::Ok);

        // Afficher la boîte de message
        msgBox.exec();
    }

}
