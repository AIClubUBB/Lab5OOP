#include "showanddelete.h"
#include "ui_showanddelete.h"
#include "usermenu.h"

ShowandDelete::ShowandDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowandDelete)
{
    ui->setupUi(this);
    data_model = new DataModel(this);
    ui->listView->setModel(data_model);
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


void ShowandDelete::on_DeleteButton_clicked()
{
    int index = ui->listView->selectionModel()->selectedIndexes().first().row();
    data_model->remove_data(index);
}
