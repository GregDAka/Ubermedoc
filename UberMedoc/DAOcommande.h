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

public:
    void createCommande(int idClient,QSqlDatabase db);

    std::vector<std::pair<std::string, int>> recupCommande( std::string mail, int numCommande, QSqlDatabase db) ;


    int getIdCommande(int idClient,QSqlDatabase db);

    void createLigneCommande(int idCommande, int ref, int quant, QSqlDatabase db);

};

#endif // DAOCOMMANDE_H
