#ifndef DAOCOMMANDE_H
#define DAOCOMMANDE_H
#include "client.h"
#include <QSqlDatabase>

// NE PAS USING NAMESPACE STD DANS LE .H
class DAOcommande{
public:
    void createCommande(int idClient,QSqlDatabase db);

    int getIdCommande(int idClient,QSqlDatabase db);

    void createLigneCommande(int idCommande, int ref, int quant, QSqlDatabase db);

    void recupCommande(QSqlDatabase db) ; //???



};

#endif // DAOCOMMANDE_H
