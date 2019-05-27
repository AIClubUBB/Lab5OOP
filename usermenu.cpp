#include "usermenu.h"
#include "ui_usermenu.h"
#include "mainwindow.h"
#include "showanddelete.h"
#include "add2wlinterface.h"

UserMenu::UserMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserMenu)
{
    ui->setupUi(this);
}

UserMenu::~UserMenu()
{
    delete ui;
}

void UserMenu::on_BackButton_clicked()
{
    MainWindow *mainW=new MainWindow(this);
    mainW->show();
    hide();
}

void UserMenu::on_ShowWL_clicked()
{
    ShowandDelete *elem=new ShowandDelete;
    elem->show();
    hide();
}

void UserMenu::on_DeleteFromWL_clicked()
{
    ShowandDelete *elem=new ShowandDelete;
    elem->show();
    hide();
}

void UserMenu::on_Add2WL_clicked()
{
    Add2WLInterface *elem=new Add2WLInterface;
    elem->show();
    hide();
}
