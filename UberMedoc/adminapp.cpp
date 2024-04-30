#include "adminapp.h"
#include "ui_adminapp.h"
#include "ajoutmedoc.h"
#include "application.h"
#include "client.h"
#include "conbd.h"
#include "DAOmedicament.h"
#include <QMessageBox>

AdminApp::AdminApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminApp)
{
    ui->setupUi(this);
    setWindowTitle("Application ADMIN");

    label_3 = ui->label_3;
    label_4 = ui->label_4;

    QStringList list;

    QSqlQuery query(db);
    if (query.exec("SELECT nom FROM medicament") ) {
        while(query.next()){
            QString nomMedicament = query.value("nom").toString();
            list.append(nomMedicament);
        }
        // On créer un model avec la liste qu'on vient de créer.
        QStringListModel *model = new QStringListModel(list, this);
        // Associer le modèle à la QListView
        ui->listView->setModel(model);
        connect(ui->listView, &QListView::clicked, this, &AdminApp::onListViewClicked);
    }
}

AdminApp::~AdminApp()
{
    delete ui;
}

void AdminApp::on_pushButton_clicked()
{
    AjoutMedoc* am = new AjoutMedoc();
    am->show();
}

void AdminApp::onListViewClicked(const QModelIndex &index){
    QString text = index.data(Qt::DisplayRole).toString();
    recupClic = text.toStdString();
    modifMedocSelec(recupClic);
}

void AdminApp::modifMedocSelec(string medocselec){
    DAOmedicament rqMedoc ;
    Medicament* medoc = rqMedoc.ObjetMedoc(medocselec,db) ;

    QString nomConvert = QString::fromStdString(medoc->getNom());
    label_3->setText(nomConvert);

    QString prixConverti = QString::number(medoc->getPrix());
    label_4->setText(prixConverti) ;
}

