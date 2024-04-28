#ifndef COMPTE_H
#define COMPTE_H

#include <QWidget>

namespace Ui {
class Compte;
}

class Compte : public QWidget
{
    Q_OBJECT

public:
    explicit Compte(QWidget *parent = nullptr);
    ~Compte();

private:
    Ui::Compte *ui;
};

#endif // COMPTE_H
