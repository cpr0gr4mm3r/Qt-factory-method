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

private slots:
    void on_startGamePushButton_clicked();

    void on_changeStatePushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
