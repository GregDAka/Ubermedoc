#include "ajoutmedoc.h"
#include "ui_ajoutmedoc.h"

AjoutMedoc::AjoutMedoc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutMedoc)
{
    ui->setupUi(this);
}

AjoutMedoc::~AjoutMedoc()
{
    delete ui;
}
