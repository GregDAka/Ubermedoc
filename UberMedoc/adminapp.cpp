#include "adminapp.h"
#include "ui_adminapp.h"

AdminApp::AdminApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminApp)
{
    ui->setupUi(this);
}

AdminApp::~AdminApp()
{
    delete ui;
}
