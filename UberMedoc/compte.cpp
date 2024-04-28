#include "compte.h"
#include "ui_compte.h"

Compte::Compte(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Compte)
{
    ui->setupUi(this);
}

Compte::~Compte()
{
    delete ui;
}
