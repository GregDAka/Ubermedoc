#include "mescommandes.h"
#include "ui_mescommandes.h"
#include "application.h"
#include "panier.h"
#include "compte.h"
#include "conBd.h"
#include "DAOcommande.h"
#include <iostream>

using namespace std ;

MesCommandes::MesCommandes(Client* cl, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MesCommandes)
{
    ui->setupUi(this);
    setWindowTitle("Mes commandes");
    m_client = cl;

    pushButton_2 = findChild<QPushButton*>("pushButton");
    pushButton_3 = findChild<QPushButton*>("pushButton_3");
    pushButton_4 = findChild<QPushButton*>("pushButton_4");
    label = findChild<QLabel*>("label");
    label_2 = findChild<QLabel*>("label_2");

    if(m_client != nullptr){
        QString nom = QString::fromStdString(m_client->getNom());
        QString prenom = QString::fromStdString(m_client->getPrenom());

        //mise à jour des labels
        ui->label->setText(nom);
        ui->label_2->setText(prenom);
    }

    // On va afficher toutes les commandes stocké dans la base de donnée pour l'utilisateur connecté.
    QStringList list;

    QSqlQuery query(db);
    query.prepare("SELECT idCommande "
                  "FROM commande "
                  "INNER JOIN utilisateur USING(idUtilisateur) "
                  "WHERE utilisateur.adrMail = :mail");


    QString qMail = QString::fromStdString(m_client->getMail());
    query.bindValue(":mail", qMail);
    int num_commande = 1;
    if (query.exec() ) {
        while(query.next()){
            QString idCommande = query.value(0).toString();
            string stdString = "Commande n°" + to_string(num_commande) + "  -> ref #"+idCommande.toStdString();
            QString ligneDeLaCommande = QString::fromStdString(stdString);
            list.append(ligneDeLaCommande);
            num_commande++;
        }
        // On créer un model avec la liste qu'on vient de créer.
        QStringListModel *model = new QStringListModel(list, this);
        // Associer le modèle à la QListView
        ui->listView->setModel(model);
        connect(ui->listView, &QListView::clicked, this, &MesCommandes::onListViewClicked);
        connect(ui->listView2, &QListView::clicked, this, &MesCommandes::onListView2Clicked);
    }

}

void MesCommandes::onListViewClicked(const QModelIndex &index){ // Quand on clic sur un element de la liste on récupère l'id de la commande
    QString selection = index.data(Qt::DisplayRole).toString();
    string amp = selection.toStdString();
    size_t pos = amp.find('#');
    string partieApresHashtag = amp.substr(pos + 1);
    int idCommande = stoi(partieApresHashtag);
    chargerBloc(idCommande);
}

void MesCommandes::chargerBloc(int id){
    DAOcommande rqCom ;
    vector<pair<string, int>> liste = rqCom.recupCommande(m_client->getMail(),id,db) ;

    // Maintenant on va pouvoir charger le bloc pour afficher la liste des éléments de la commande récupérer juste avant.
    QStringList list;

    for (const auto& pair : liste) {
        string ligne = pair.first + " , quantité : " + to_string(pair.second);
        QString qLigne = QString::fromStdString(ligne);
        list.append(qLigne) ;
    }
    // On créer un model avec la liste qu'on vient de créer.
    QStringListModel *model = new QStringListModel(list, this);
    // Associer le modèle à la QListView
    ui->listView2->setModel(model);

}

void MesCommandes::onListView2Clicked(const QModelIndex &index){ // Quand on clic sur un element de la liste on récupère l'id de la commande
    close();
    Application* app = new Application(m_client);
    app->show();
}



MesCommandes::~MesCommandes()
{
    delete ui;
}

void MesCommandes::on_pushButton_2_clicked(){
    close();
    Application* mesCommande = new Application(m_client);
    mesCommande -> show();
}

void MesCommandes::on_pushButton_4_clicked(){
    close();
    Panier* panier = new Panier(m_client);
    panier -> show();
}

void MesCommandes::on_pushButton_3_clicked(){
    close();
    Compte* compte = new Compte(m_client);
    compte -> show();
}
