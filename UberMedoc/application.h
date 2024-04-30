#ifndef APPLICATION_H
#define APPLICATION_H
#include <QWidget>
#include <QLabel>
#include "client.h"
#include <QPushButton>
#include <QStringListModel>
#include <QLabel>
#include "ui_application.h"
#include <string>

namespace Ui {
class Application;
}

class Application : public QWidget
{
    Q_OBJECT

public:
    explicit Application(Client* client, QWidget *parent = nullptr);
    ~Application();
    void onListViewClicked(const QModelIndex &index) ;
    void modifMedocSelec(std::string medocselec) ;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Application *ui;

    Client* m_client;
    QLabel* nomLabel;
    QLabel* prenomLabel;

    QPushButton* pushButton;
    QPushButton* pushButton_2;
    QPushButton* pushButton_3;
    QPushButton* pushButton_4;
    std::string recupClic ;
    QLabel* label_2 ;
    QLabel* label_3 ;
};

#endif // APPLICATION_H
