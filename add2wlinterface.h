#ifndef ADD2WLINTERFACE_H
#define ADD2WLINTERFACE_H

#include <QDialog>

namespace Ui {
class Add2WLInterface;
}

class Add2WLInterface : public QDialog
{
    Q_OBJECT

public:
    explicit Add2WLInterface(QWidget *parent = nullptr);
    ~Add2WLInterface();

private slots:
    void on_BackButton_clicked();

private:
    Ui::Add2WLInterface *ui;
};

#endif // ADD2WLINTERFACE_H
