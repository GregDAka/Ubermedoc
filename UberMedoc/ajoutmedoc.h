#ifndef AJOUTMEDOC_H
#define AJOUTMEDOC_H
#include "qlineedit.h"
#include "qpushbutton.h"
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

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::AjoutMedoc *ui;

    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QLineEdit* lineEdit;
    QLineEdit* lineEdit_2;

};

#endif // AJOUTMEDOC_H
