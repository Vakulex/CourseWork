#include "AdminPanel/adminpanel.h"
#include "QModelIndex"
#include "QAbstractItemModel"
#include "QDebug"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

    DatabaseManager::GetInstance()->ConnectToDatabase();
    model = new QSqlTableModel();
    createUserModel(model);
    WidgetSettings();
    initResources();
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::initResources()
{
    ui->AddButton->setIcon(QIcon(":/icons/img/b_plus_icon.png"));
    ui->DeleteButton->setIcon(QIcon(":/icons/img/b_minus_icon.png"));
    ui->UpdateButton->setIcon(QIcon(":/icons/img/b_refresh_icon.png"));

    ui->OptionsMenu->setIcon(QIcon(":/icons/img/b_gear_icon.png"));
    ui->ProfileAction->setIcon(QIcon(":/icons/img/b_user_icon.png"));
    ui->OptionsAction->setIcon(QIcon(":/icons/img/b_gear_icon.png"));
}

void AdminPanel::createUserModel(QSqlTableModel *model)
{
    model->setTable("users");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Прізвище"));
    model->setHeaderData(2, Qt::Horizontal, tr("Ім'я"));
    model->setHeaderData(3, Qt::Horizontal, tr("По-батькові"));
    model->setHeaderData(4, Qt::Horizontal, tr("Номер телефону"));

    ui->UsersTable->setModel(model);
}

void AdminPanel::WidgetSettings()
{
    ui->UsersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->UsersTable->horizontalHeader()->setStretchLastSection(true);
}

void AdminPanel::on_AddButton_clicked()
{
    AddUserData *window = new AddUserData;
    window->show();
    if(window->isHidden())
        model->select();
}

void AdminPanel::on_AddService_triggered()
{
    AddService *window = new AddService();
    window->show();
}

void AdminPanel::on_DBOptionsAction_triggered()
{
    DataBaseOptions *window = new DataBaseOptions();
    window->show();
}

void AdminPanel::on_DeleteButton_clicked()
{
    QSqlQuery query;
    QModelIndex index;
    if(QMessageBox::question(this, "Видалення об'єкту", "Ви впевнені, що хочете видалити обраного користувача?",
                                        QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        index = ui->UsersTable->selectionModel()->currentIndex();
        QVariant value = index.sibling(index.row(), 0).data();
        query.prepare("Delete from users where users_ID=" + value.toString());
        query.exec();
    }

    model->select();
}

void AdminPanel::on_UpdateButton_clicked()
{
    model->select();
}

void AdminPanel::on_DeleteService_triggered()
{
    DeleteServices *window = new DeleteServices();
    window->show();
}

void AdminPanel::on_UsersTable_clicked(const QModelIndex &index)
{
    QSqlQueryModel *orderModel = new QSqlQueryModel;
    orderModel->setQuery("SELECT * from order_data WHERE users_ID = " + QString::number(index.row()));
    ui->StartDate->setDate(orderModel->index(index.row(), 1).data().toDate());
    ui->ServiceComboBox->setCurrentText(orderModel->index(index.row(), 4).data().toString());
    ui->AdressLineEdit->setText(orderModel->index(index.row(), 5).data().toString());
    ui->PriceLineEdit->setText(orderModel->index(index.row(), 6).data().toString());
    ui->statusCheckBox->setChecked(orderModel->index(index.row(), 7).data().toBool());

    ui->StartDate->setDate(orderModel->index(index.row(), 2).data().toDate());
    ui->StartDate->setDate(orderModel->index(index.row(), 3).data().toDate());
}
