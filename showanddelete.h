#ifndef SHOWANDDELETE_H
#define SHOWANDDELETE_H

#include <QDialog>
#include "datamodel.h"

namespace Ui {
class ShowandDelete;
}

class ShowandDelete : public QDialog
{
    Q_OBJECT

public:
    explicit ShowandDelete(QWidget *parent = nullptr);
    ~ShowandDelete();

private slots:
    void on_BackButton_clicked();

    void on_DeleteButton_clicked();

private:
    Ui::ShowandDelete *ui;
    DataModel *data_model;
};

#endif // SHOWANDDELETE_H
