#include "panier.h"
#include "ui_panier.h"

Panier::Panier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Panier)
{
    ui->setupUi(this);
}

Panier::~Panier()
{
    delete ui;
}
