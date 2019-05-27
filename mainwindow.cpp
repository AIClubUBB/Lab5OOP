#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usermenu.h"
#include "adminmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
    close();
}

void MainWindow::on_UserButton_clicked()
{
    UserMenu *user=new UserMenu(this);
    user->show();
    hide();
}

void MainWindow::on_AdminButton_clicked()
{
    AdminMenu *admin=new AdminMenu(this);
    admin->show();
    hide();
}
