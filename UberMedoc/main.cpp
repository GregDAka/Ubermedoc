#include "mainwindow.h"
#include "client.h"
#include "utilisateur.h"
#include "client.h"
#include "medicament.h"
using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Page d'accueil");
    w.show();

    //Medicament dolipranne(1, "Dolipranne", 8.5);
    //Medicament strepsile(2, "Strepsile", 5.5);
    //dolipranne.afficherDetails();
    //Client ben("Benoit", "Dufour", "11 allee Guy Charff", "dufour.b3012@gmail.com", "bd11");
    //ben.afficherDetails();
    //ben.ajouterAuPanier(&dolipranne);
    //ben.ajouterAuPanier(&strepsile);
    //ben.afficherDetails();
    return a.exec();
}
