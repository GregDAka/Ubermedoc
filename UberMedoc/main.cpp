#include "mainwindow.h"
#include "client.h"
#include "utilisateur.h"
#include "client.h"
#include "medicament.h"
#include "commande.h"
#include "conBd.h"
using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    //On créer des medocs
    Medicament dolipranne(1, "Dolipranne", 8.5);
    Medicament strepsile(2, "Strepsile", 5.5);
    dolipranne.afficherDetails();//test affichage d'un medoc

    //Création d'un client
    Client april("April", "Dufey", "11 allee Guy Charff", "april.dufey@gmail.com", "ad11");
    april.afficherDetails();//test affichage client(plymorphisme pour la methode d'affichage d'un utilisateur)
                            //ici panier vide et solde par défault à 0€


    april.ajouterAuPanier(&dolipranne);
    april.ajouterAuPanier(&strepsile);
    april.ajouterSolde(50.8);
    april.afficherDetails();// on test encore avec des articles dans le panier et un solde

    //Création d'une commande, pensé pour le faire à partir d'un client comme
    //ça juste à récup son panier et le prix du panier (attribut totalPanier)
    Commande com(&april);
    com.afficherDetails();

    connexionBD();
    return a.exec();
}
