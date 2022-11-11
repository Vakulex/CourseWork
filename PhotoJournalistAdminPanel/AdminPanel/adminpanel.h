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

private slots:
    void on_AddButton_clicked();
    void on_AddService_triggered();
    void on_DBOptionsAction_triggered();
    void on_DeleteButton_clicked();
    void on_UpdateButton_clicked();


    void on_DeleteService_triggered();
    void on_UsersTable_clicked(const QModelIndex &index);

    void on_EditButton_clicked();

    void on_SearchLineEdit_textChanged(const QString &arg1);

private:
    Ui::AdminPanel *ui;
    QSqlQueryModel *model;

    void initResources();
    void updateTable(QString arg);
    void updateTable();
    void initCombobox();
    void WidgetSettings();
    bool linesIsNotEmpty();
};

#endif // ADMINPANEL_H
