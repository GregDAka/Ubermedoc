#ifndef ADMINAPP_H
#define ADMINAPP_H

#include <QWidget>

namespace Ui {
class AdminApp;
}

class AdminApp : public QWidget
{
    Q_OBJECT

public:
    explicit AdminApp(QWidget *parent = nullptr);
    ~AdminApp();

private:
    Ui::AdminApp *ui;
};

#endif // ADMINAPP_H
