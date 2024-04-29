#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QStringListModel>
#include <QLabel>
#include "ui_application.h"
#include "DAOmedicament.h"

namespace Ui {
class Application;
}

class Application : public QWidget
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();
    void onListViewClicked(const QModelIndex &index) ;
    void modifMedocSelec(string medocselec) ;

private:
    Ui::Application *ui;
    string recupClic ;
    QLabel* label_2 ;
    QLabel* label_3 ;
};

#endif // APPLICATION_H
