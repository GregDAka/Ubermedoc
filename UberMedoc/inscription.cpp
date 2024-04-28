#include "inscription.h"
#include "ui_inscription.h"
#include "mainwindow.h"

Inscription::Inscription(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Inscription)
{
    ui->setupUi(this);
    setWindowTitle("Inscription");
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

