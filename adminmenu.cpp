#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "mainwindow.h"

AdminMenu::AdminMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMenu)
{
    ui->setupUi(this);
}

AdminMenu::~AdminMenu()
{
    delete ui;
}

void AdminMenu::on_BackButton_clicked()
{
    MainWindow *mainW=new MainWindow(this);
    mainW->show();
    hide();
}
