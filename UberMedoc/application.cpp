#include "application.h"
#include "ui_application.h"
#include "client.h"

Application::Application(Client* client, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Application)
    , m_client(client)
{
    ui->setupUi(this);
    setWindowTitle("Application");


    if(m_client != nullptr){
        QString nom = QString::fromStdString(m_client->getNom());
        QString prenom = QString::fromStdString(m_client->getPrenom());

        //mise à jour des labels
        ui->nomLabel->setText(nom);
        ui->prenomLabel->setText(prenom);
    }
}

Application::~Application()
{
    delete ui;
}

