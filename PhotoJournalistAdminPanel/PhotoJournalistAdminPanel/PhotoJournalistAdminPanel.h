#ifndef PhotoJournalistAdminPanel_H
#define PhotoJournalistAdminPanel_H

#include <QMainWindow>
#include <AdminPanel/adminpanel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class PhotoJournalistAdminPanel; }
QT_END_NAMESPACE

class PhotoJournalistAdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    PhotoJournalistAdminPanel(QWidget *parent = nullptr);
    ~PhotoJournalistAdminPanel();

private slots:
    void on_SignInButton_clicked();

private:
    Ui::PhotoJournalistAdminPanel *ui;
    AdminPanel *adminPanelWindow;
    QString m_login, m_password;

    bool checkInput(QString, QString);

    void createAdminWindow();
};
#endif // PhotoJournalistAdminPanel_H
