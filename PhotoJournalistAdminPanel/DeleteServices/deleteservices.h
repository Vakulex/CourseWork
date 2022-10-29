#ifndef DELETESERVICES_H
#define DELETESERVICES_H

#include <QMainWindow>
#include <DatabaseManager/databasemanager.h>

namespace Ui {
class DeleteServices;
}

class DeleteServices : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteServices(QWidget *parent = nullptr);
    ~DeleteServices();

private slots:
    void on_DeleteButton_clicked();

private:
    Ui::DeleteServices *ui;
    QSqlTableModel *model;


};

#endif // DELETESERVICES_H
