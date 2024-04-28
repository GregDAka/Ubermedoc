#include "connexion.h"
#include "ui_connexion.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;

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
    cout << "Confirmer" << endl;
}

