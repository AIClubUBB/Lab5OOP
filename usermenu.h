#ifndef USERMENU_H
#define USERMENU_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class UserMenu;
}

class UserMenu : public QDialog
{
    Q_OBJECT

public:
    explicit UserMenu(QWidget *parent = nullptr);
    ~UserMenu();

private slots:
    void on_BackButton_clicked();

    void on_ShowWL_clicked();

    void on_DeleteFromWL_clicked();

    void on_Add2WL_clicked();

private:
    Ui::UserMenu *ui;
};

#endif // USERMENU_H
