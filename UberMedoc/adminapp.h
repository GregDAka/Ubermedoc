#ifndef ADMINAPP_H
#define ADMINAPP_H
#include <QWidget>
#include <qlabel.h>

namespace Ui {
class AdminApp;
}

class AdminApp : public QWidget
{
    Q_OBJECT

public:
    explicit AdminApp(QWidget *parent = nullptr);
    ~AdminApp();
    void onListViewClicked(const QModelIndex &index) ;
    void modifMedocSelec(std::string medocselec) ;

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdminApp *ui;
    std::string recupClic ;
    QLabel* label_3 ;
    QLabel* label_4 ;
};

#endif // ADMINAPP_H
