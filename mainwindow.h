#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GameLauncher;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    GameLauncher* m_gameLauncher;
    QStringListModel* m_model;
    QStringList m_list;

private:
    void addLogs();
    void refreshTable();
    void processInformation();

signals:
    void transmit_name_to_object(std::string value);
    void transmit_age_to_object(std::string value);

private slots:
    void on_startGamePushButton_clicked();
    void on_changeStatePushButton_clicked();

    void on_userNameLineEdit_textChanged(const QString &arg1);

    void on_userAgeLineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
