#ifndef CONNEXION_H
#define CONNEXION_H

#include <QWidget>

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
};

#endif // CONNEXION_H
