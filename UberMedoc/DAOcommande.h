#ifndef DAOCOMMANDE_H
#define DAOCOMMANDE_H
#include "client.h"
#include <QSqlDatabase>

// NE PAS USING NAMESPACE STD DANS LE .H
class DAOcommande{
    void createCommande(QSqlDatabase db);

    int getIdCommande(QSqlDatabase db);

    void recupCommande(QSqlDatabase db) ; //???



};

#endif // DAOCOMMANDE_H
