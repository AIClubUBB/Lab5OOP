#include "showanddelete.h"
#include "ui_showanddelete.h"
#include "usermenu.h"

ShowandDelete::ShowandDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowandDelete)
{
    ui->setupUi(this);
}

ShowandDelete::~ShowandDelete()
{
    delete ui;
}

void ShowandDelete::on_BackButton_clicked()
{
    UserMenu *user=new UserMenu(this);
    user->show();
    hide();
}
