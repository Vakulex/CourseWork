#ifndef PhotoJournalistAdminPanel_H
#define PhotoJournalistAdminPanel_H

#include <QMainWindow>
#include <AdminPanel/adminpanel.h>
#include <QtSql>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class PhotoJournalistAdminPanel; }
QT_END_NAMESPACE

class PhotoJournalistAdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    PhotoJournalistAdminPanel(QWidget *parent = nullptr);
    ~PhotoJournalistAdminPanel();
    void setCfgPath(QString);
private slots:
    void on_SignInButton_clicked();

private:
    Ui::PhotoJournalistAdminPanel *ui;
    AdminPanel *adminPanelWindow;
    QString m_login, m_password, m_cfgPath;

    bool checkInput(QString, QString);

    void createAdminWindow();
};
#endif // PhotoJournalistAdminPanel_H
