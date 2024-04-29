#ifndef AJOUTMEDOC_H
#define AJOUTMEDOC_H

#include <QWidget>

namespace Ui {
class AjoutMedoc;
}

class AjoutMedoc : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutMedoc(QWidget *parent = nullptr);
    ~AjoutMedoc();

private:
    Ui::AjoutMedoc *ui;
};

#endif // AJOUTMEDOC_H
