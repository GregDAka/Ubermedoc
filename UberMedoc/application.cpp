#include "application.h"
#include "ui_application.h"
#include "conbd.h"
#include <iostream>

using namespace std ;

Application::Application(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);
    setWindowTitle("Application");

    label_2 = ui->label_2;
    label_3 = ui->label_3;

    QStringList list;

    QSqlQuery query(db);
    if (query.exec("SELECT nom FROM medicament") ) {
        while(query.next()){
            QString nomMedicament = query.value("nom").toString();
            list.append(nomMedicament);
        }
    }
    // On créer un model avec la liste qu'on vient de créer.
    QStringListModel *model = new QStringListModel(list, this);
    // Associer le modèle à la QListView
    ui->listView->setModel(model);
    connect(ui->listView, &QListView::clicked, this, &Application::onListViewClicked);
}

Application::~Application()
{
    delete ui;
}

void Application::onListViewClicked(const QModelIndex &index) {
    QString text = index.data(Qt::DisplayRole).toString();
    recupClic = text.toStdString();
    modifMedocSelec(recupClic);
}

void Application::modifMedocSelec(string medocselec){
    DAOmedicament rqMedoc ;
    Medicament* medoc = rqMedoc.ObjetMedoc(medocselec,db) ;

    cout<<medoc->getNom()<<endl ;
    cout<<medoc->getPrix()<<endl ;
    // On converti le nom du médicament de type String récupéré par le GET en Qstring pour pouvoir changer le Label
    QString nomConvert = QString::fromStdString(medoc->getNom());
    label_2->setText(nomConvert); // Label_2 fait référence au Label (text) Label_2 dans l'application.ui.

    // On fait la même chose pour le prix, sauf qu'on converti le prix(double) en String.
    QString prixConverti = QString::number(medoc->getPrix());
    label_3->setText(prixConverti) ;
}
