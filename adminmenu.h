#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>

namespace Ui {
class AdminMenu;
}

class AdminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    ~AdminMenu();

private slots:
    void on_BackButton_clicked();

private:
    Ui::AdminMenu *ui;
};

#endif // ADMINMENU_H
