#ifndef ADD2WLINTERFACE_H
#define ADD2WLINTERFACE_H

#include <QDialog>
#include "datamodeladd.h"

namespace Ui {
class Add2WLInterface;
}

class Add2WLInterface : public QDialog
{
    Q_OBJECT

public:
    explicit Add2WLInterface(QWidget *parent = nullptr);
    ~Add2WLInterface();
    datamodeladd *data_model;

private slots:
    void on_BackButton_clicked();

    void on_SearchButton_clicked();

private:
    Ui::Add2WLInterface *ui;
};

#endif // ADD2WLINTERFACE_H
