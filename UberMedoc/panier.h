#ifndef PANIER_H
#define PANIER_H

#include <QWidget>

namespace Ui {
class Panier;
}

class Panier : public QWidget
{
    Q_OBJECT

public:
    explicit Panier(QWidget *parent = nullptr);
    ~Panier();

private:
    Ui::Panier *ui;
};

#endif // PANIER_H
