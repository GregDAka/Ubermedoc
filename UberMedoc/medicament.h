#include <string>
using namespace std;
#ifndef MEDICAMENT_H
#define MEDICAMENT_H

class Medicament
{
    private:
        int ref;
        string nom;
        double prix;

    public:
        Medicament();
        Medicament(int, string, double);
        ~Medicament();
        void afficherDetails();
        int getRef();
        string getNom();
        double getPrix();
};

#endif // MEDICAMENT_H
