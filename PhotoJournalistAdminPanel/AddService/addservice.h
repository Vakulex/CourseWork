#ifndef ADDSERVICE_H
#define ADDSERVICE_H

#include "qsqlquery.h"
#include "DatabaseManager/databasemanager.h"
#include <QMainWindow>

namespace Ui {
class AddService;
}

class AddService : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddService(QWidget *parent = nullptr);
    ~AddService();

private slots:
    void on_AddServiceButton_clicked();

private:
    Ui::AddService *ui;
    void initCombobox();
    bool CheckFields();
};

#endif // ADDSERVICE_H
