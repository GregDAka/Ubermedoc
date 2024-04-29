#ifndef DAOCOMMANDE_H
#define DAOCOMMANDE_H
#include "client.h"
#include <QSqlDatabase>

#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <vector>

// NE PAS USING NAMESPACE STD DANS LE .H
class DAOcommande{
    public :
    std::vector<std::pair<std::string, int>> recupCommande( std::string mail, int numCommande, QSqlDatabase db) ;

    void createCommande(QSqlDatabase db);

    int getIdCommande(QSqlDatabase db);

};

#endif // DAOCOMMANDE_H
