#include "ajoutmedoc.h"
#include "DAOmedicament.h"
#include "ui_ajoutmedoc.h"
#include "application.h"
#include "conBd.h"
#include "DAOmedicament.h"
#include <string>
using namespace std;

AjoutMedoc::AjoutMedoc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AjoutMedoc)
{
    ui->setupUi(this);

    pushButton = findChild<QPushButton*>("pushButton");
    pushButton_2 = findChild<QPushButton*>("pushButton_2");
    lineEdit = findChild<QLineEdit*>("lineEdit");
    lineEdit_2 = findChild<QLineEdit*>("lineEdit _2");
}

AjoutMedoc::~AjoutMedoc()
{
    delete ui;
}

void AjoutMedoc::on_pushButton_clicked(){
    close();
    //Application* app = new Application(m_client);
    //app -> show();
}

void AjoutMedoc::on_pushButton_2_clicked(){
    QString tmp = lineEdit->text();
    string nom = tmp.toStdString();
    tmp = lineEdit_2->text();
    bool ok; // variable booléenne pour indiquer si la conversion a réussi
    double prix = tmp.toDouble(&ok);
    DAOmedicament med;
    med.ajouterMedoc(nom, prix, db);
    close();
    //Application* app = new Application(m_client);
    //app -> show();
}
