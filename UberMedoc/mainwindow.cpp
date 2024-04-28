#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connexion.h"
#include "inscription.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Page d'accueil");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnConnexion_clicked()
{
    Connexion* connexion = new Connexion();
    connexion->show();
    close();
}

void MainWindow::on_btnInscrire_clicked()
{
    Inscription* inscription = new Inscription();
    inscription->show();
    close();
}

