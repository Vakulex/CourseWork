#include "AdminPanel/adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

    DatabaseManager::GetInstance()->ConnectToDatabase();
    model = new QSqlTableModel();

    updateTable();
    WidgetSettings();
    initResources();
    initCombobox();
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

void AdminPanel::updateTable()
{
    model->setTable("users");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Прізвище"));
    model->setHeaderData(2, Qt::Horizontal, tr("Ім'я"));
    model->setHeaderData(3, Qt::Horizontal, tr("По-батькові"));
    model->setHeaderData(4, Qt::Horizontal, tr("Номер телефону"));

    ui->UsersTable->setModel(model);
    ui->UsersTable->hideColumn(0);
    initCombobox();
}

void AdminPanel::WidgetSettings()
{
    ui->UsersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->UsersTable->horizontalHeader()->setStretchLastSection(true);
}

void AdminPanel::on_AddButton_clicked()
{
    AddUserData window;
    window.setModal(true);
    window.exec();

    updateTable();
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
    if(QMessageBox::question(this, "Видалення об'єкту", "Ви впевнені, що хочете видалити обраного користувача?",
                                        QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        QModelIndex index = ui->UsersTable->selectionModel()->currentIndex();
        QString id = index.sibling(index.row(), 0).data().toString();
        QSqlQuery query;

        query.exec("Delete from order_data where users_ID = " + id);
        query.exec("Delete from users where users_ID = " + id);

        updateTable();
    }
}

void AdminPanel::on_UpdateButton_clicked()
{
    updateTable();
}

void AdminPanel::on_DeleteService_triggered()
{
    DeleteServices *window = new DeleteServices();
    window->show();
}

void AdminPanel::initCombobox()
{
    QStringList status;

    QSqlQuery query;
    query.exec("select * from services");
    while (query.next())
    {
        QSqlRecord recorder = query.record();
        status.append(recorder.value("name_service").toString());
    }

    ui->ServiceComboBox->clear();
    ui->ServiceComboBox->addItems(status);
}

void AdminPanel::on_UsersTable_clicked(const QModelIndex &index)
{
    QSqlQuery query;
    query.prepare("select * from order_data INNER JOIN services ON order_data.service_ID = services.service_ID where users_ID = " + ui->UsersTable->model()->index(index.row(),0).data().toString());
    query.exec();
    query.next();

    QSqlRecord record = query.record();

    ui->StartDate->setDate(QDate::fromString(record.value("creation_date").toString(), "yyyy-MM-dd"));
    ui->ServiceComboBox->setCurrentText(record.value("name_service").toString());
    ui->AdressLineEdit->setText(record.value("adress").toString());
    ui->PriceLineEdit->setText(record.value("order_price").toString());
    ui->statusCheckBox->setChecked(record.value("order_status").toBool());

    if(ui->statusCheckBox->isChecked())
    {
        ui->EndDate->setEnabled(true);
        ui->PhotoPathLineEdit->setEnabled(true);
        ui->EndDate->setDate(QDate::fromString(record.value("finalization_date").toString(), "yyyy-MM-dd"));
        ui->PhotoPathLineEdit->setText(record.value("img").toString());
    }
    else
    {
        ui->EndDate->setEnabled(false);
        ui->PhotoPathLineEdit->setEnabled(false);
    }
}

bool AdminPanel::linesIsNotEmpty()
{
    return !ui->StartDate->text().isEmpty() &&
           !ui->EndDate->text().isEmpty() &&
           !ui->PriceLineEdit->text().isEmpty() &&
           !ui->PhotoPathLineEdit->text().isEmpty() &&
           !ui->AdressLineEdit->text().isEmpty() &&
           !ui->ServiceComboBox->itemText(-1).contains("Послуги") &&
           !ui->EndDate->date().isNull() &&
           !ui->PhotoPathLineEdit->text().isEmpty();
}

void AdminPanel::on_EditButton_clicked()
{
    if(linesIsNotEmpty())
    {
        int serviceId = 0;
        int userId = 0;

        QSqlQuery query;
        query.exec("SELECT service_ID from services where type_service = " + ui->ServiceComboBox->currentText());
        while(query.next())
        {
            QSqlRecord recorder = query.record();
            serviceId = recorder.value("service_ID").toInt();
        }

        QModelIndex index = ui->UsersTable->selectionModel()->currentIndex();
        userId = index.sibling(index.row(), 0).data().toInt();


        QString request = "UPDATE order_data SET creation_date = '%1', finalization_date = '%2', img = '%3', adress = '%4', order_price = '%5', service_ID = %6 where users_ID = %7";
        request = request.arg(ui->StartDate->text(), ui->EndDate->text(), ui->PhotoPathLineEdit->text(), ui->AdressLineEdit->text(), ui->PriceLineEdit->text(), QString::number(serviceId), QString::number(userId));

        if(query.exec(request))
            QMessageBox::warning(this, "Вдало", "Данні були змінені!");
        else
            QMessageBox::warning(this, "Помилка", "Помилка запросу!");
    }
    else
    {
        QMessageBox::warning(this, "Помилка", "Впищіть всі значення!");
    }
}

