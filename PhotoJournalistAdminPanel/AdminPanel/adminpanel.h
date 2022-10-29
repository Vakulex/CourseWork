#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>

#include "DatabaseManager/databasemanager.h"
#include "AdminPanel/adminpanel.h"
#include "AddUserData/adduserdata.h"
#include "AddService/addservice.h"
#include "DBOptions/databaseoptions.h"
#include "DatabaseManager/databasemanager.h"
#include <DeleteServices/deleteservices.h>

#include "qsqltablemodel.h"
#include "ui_adminpanel.h"
#include "qsqlquery.h"
#include "qdebug.h"

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();
    QSqlTableModel *model;
private slots:
    void on_AddButton_clicked();
    void on_AddService_triggered();
    void on_DBOptionsAction_triggered();
    void on_DeleteButton_clicked();
    void on_UpdateButton_clicked();


    void on_DeleteService_triggered();
    void on_UsersTable_clicked(const QModelIndex &index);
private:
    Ui::AdminPanel *ui;
    void initResources();
    void createUserModel(QSqlTableModel*);
    void WidgetSettings();
};

#endif // ADMINPANEL_H
