#ifndef CONNEXION_H
#define CONNEXION_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "Client.h"

namespace Ui {
class Connexion;
}

class Connexion : public QWidget
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = nullptr);
    ~Connexion();


private slots:
    void on_btnRetour_clicked();
    void on_btnConfirmer_clicked();

private:
    Ui::Connexion *ui;
    QLineEdit *mailConnexion;
    QLineEdit *mdpConnexion;
    QPushButton *btnConfirmer;


};

#endif // CONNEXION_H
