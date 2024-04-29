#ifndef MESCOMMANDES_H
#define MESCOMMANDES_H

#include <QWidget>

namespace Ui {
class MesCommandes;
}

class MesCommandes : public QWidget
{
    Q_OBJECT

public:
    explicit MesCommandes(QWidget *parent = nullptr);
    ~MesCommandes();

private:
    Ui::MesCommandes *ui;
};

#endif // MESCOMMANDES_H
