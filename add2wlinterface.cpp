#include "add2wlinterface.h"
#include "ui_add2wlinterface.h"
#include "usermenu.h"
#include <QStringListModel>
#include <QStringList>
#include <QString>
#include "datamodeladd.h"
#include <QDebug>;

Add2WLInterface::Add2WLInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add2WLInterface)
{
    ui->setupUi(this);
    data_model = new datamodeladd(this);
    data_model->WL.readFromFileUser();
    qDebug()<<qint8(data_model->WL.movieList.size());
    for(int i=0;i<data_model->WL.movieList.size();i++)
        qDebug() <<QString(data_model->WL.movieList[i].getTitle().c_str());
    ui->listView->setModel(data_model);
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

void Add2WLInterface::on_SearchButton_clicked()
{
    //data_model->data(ui->lineEdit->text().toStdString());
    ui->lineEdit->clear();
}
