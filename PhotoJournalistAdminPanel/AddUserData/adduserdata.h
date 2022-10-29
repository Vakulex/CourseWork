#ifndef ADDUSERDATA_H
#define ADDUSERDATA_H

#include <QMainWindow>
#include "qsqlquerymodel.h"
#include "qsqlquery.h"
#include "AddService/addservice.h"
#include <QCloseEvent>

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

    void on_ServiceComboBox_currentIndexChanged(int index);

private:
    Ui::AddUserData *ui;
    void setValidFields();
    void initComboBox();
    bool checkIncorrectFields();
    bool checkIncorrectFields(bool);
    void addUser();
    QString calculatePrice(int);
};

#endif // ADDUSERDATA_H
