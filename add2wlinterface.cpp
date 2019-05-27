#include "add2wlinterface.h"
#include "ui_add2wlinterface.h"
#include "usermenu.h"

Add2WLInterface::Add2WLInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add2WLInterface)
{
    ui->setupUi(this);
}

Add2WLInterface::~Add2WLInterface()
{
    delete ui;
}

void Add2WLInterface::on_BackButton_clicked()
{
    UserMenu *user=new UserMenu(this);
    user->show();
    hide();
}
