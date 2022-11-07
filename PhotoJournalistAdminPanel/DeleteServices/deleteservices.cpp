#include "deleteservices.h"
#include "ui_deleteservices.h"

DeleteServices::DeleteServices(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteServices)
{
    ui->setupUi(this);

    DatabaseManager::GetInstance()->ConnectToDatabase();
    model = new QSqlTableModel();
    model->setTable("services");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Назва"));
    model->setHeaderData(2, Qt::Horizontal, tr("Тип"));
    model->setHeaderData(3, Qt::Horizontal, tr("Ціна"));
    model->setHeaderData(4, Qt::Horizontal, tr("Коментар"));

    ui->ServicesTableView->setModel(model);
    ui->DeleteButton->setIcon(QIcon(":/icons/img/b_minus_icon.png"));
}

DeleteServices::~DeleteServices()
{
    delete ui;
}

void DeleteServices::on_DeleteButton_clicked()
{
    if(QMessageBox::question(this, "Видалення об'єкту", "Ви впевнені, що хочете видалити обрану послугу?",
                                        QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        QModelIndex index = ui->ServicesTableView->selectionModel()->currentIndex();
        QVariant value = index.sibling(index.row(), 0).data();
        QSqlQuery query("Delete from services where service_id = " + value.toString());
        query.exec();

        model->select();
    }
}
