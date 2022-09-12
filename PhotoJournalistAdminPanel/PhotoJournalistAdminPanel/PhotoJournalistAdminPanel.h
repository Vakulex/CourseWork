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
    std::string m_login = "admin", m_password = "123123";

    bool checkInput(std::string, std::string);

    void createAdminWindow();
};
#endif // PhotoJournalistAdminPanel_H
