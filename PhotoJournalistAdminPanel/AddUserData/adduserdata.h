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

    void on_ServiceComboBox_textActivated(const QString &arg1);

private:
    Ui::AddUserData *ui;
    void setValidFields();
    void initComboBox();
    bool checkIncorrectFields();
    void addUser();
    QString calculatePrice(int);

    int service_id = 0;
};

#endif // ADDUSERDATA_H
