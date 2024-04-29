#include "mescommandes.h"
#include "ui_mescommandes.h"

MesCommandes::MesCommandes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MesCommandes)
{
    ui->setupUi(this);
}

MesCommandes::~MesCommandes()
{
    delete ui;
}
