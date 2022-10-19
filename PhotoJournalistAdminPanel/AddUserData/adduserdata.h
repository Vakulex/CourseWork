#ifndef ADDUSERDATA_H
#define ADDUSERDATA_H

#include <QMainWindow>
#include "qsqlquery.h"

namespace Ui {
class AddUserData;
}

class AddUserData : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddUserData(QWidget *parent = nullptr);
    ~AddUserData();

private slots:
    void on_StatusCheckBox_toggled(bool checked);

    void on_AddUserButton_clicked();

private:
    Ui::AddUserData *ui;
    bool CheckNulls();
    bool CheckFields();
    bool CheckFieldsAfterCheckBox();
};

#endif // ADDUSERDATA_H
