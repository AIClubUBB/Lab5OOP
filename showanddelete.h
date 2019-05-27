#ifndef SHOWANDDELETE_H
#define SHOWANDDELETE_H

#include <QDialog>

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

private:
    Ui::ShowandDelete *ui;
};

#endif // SHOWANDDELETE_H
