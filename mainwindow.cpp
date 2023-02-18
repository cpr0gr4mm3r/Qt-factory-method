#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model/gamelauncher.h"
#include "utilities.h"
#include "logger.h"
#include "model/vehicle.h"
#include <QMessageBox>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_model(new QStringListModel(this))
{
    ui->setupUi(this);
    ui->changeStatePushButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addLogs()
{
    std::vector<Vehicle*> vehicles = m_gameLauncher->getVehicles();
    for (std::vector<Vehicle*>::iterator vehicleIterator = vehicles.begin(); vehicleIterator != vehicles.end(); vehicleIterator++)
    {
        std::vector<std::string> lines = (*vehicleIterator)->getLogger()->getLines();
        for (std::vector<std::string>::iterator lineIterator = lines.begin(); lineIterator != lines.end(); lineIterator++)
        {
            m_list << QString::fromStdString(*lineIterator);
        }
        (*vehicleIterator)->getLogger()->clearLines();
    }
    m_model->setStringList(m_list);
    ui->listView->setModel(m_model);
}

void MainWindow::refreshTable()
{
    std::vector<Vehicle*> vehicles = m_gameLauncher->getVehicles();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(vehicles.size());
    ui->tableWidget->setColumnCount(2);
    int row = 0;
    for (std::vector<Vehicle*>::iterator vehicleIterator = vehicles.begin(); vehicleIterator != vehicles.end(); vehicleIterator++)
    {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString((*vehicleIterator)->getIdentifier())));
        ui->tableWidget->setItem(row++, 1, new QTableWidgetItem((*vehicleIterator)->isRunning() ? QString("running") : QString("stopped")));
    }
}


void MainWindow::processInformation()
{
    if (Utilities::ageIsValid(ui->userAgeLineEdit->text()))
    {
        m_gameLauncher = new GameLauncher();
        ui->startGamePushButton->setEnabled(false);
        ui->changeStatePushButton->setEnabled(true);
        addLogs();
        refreshTable();
    }
    else
    {
        QMessageBox::warning(this, tr("Driver & Vehicles"),
                             tr("The age is not valid.\n"
                                "Please provide a valid value."),
                             QMessageBox::Ok);
    }
}

void MainWindow::on_startGamePushButton_clicked()
{
    if (ui->userNameLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Driver & Vehicles"),
                             tr("The user name is empty.\n"
                                "Please provide a valid value."),
                             QMessageBox::Ok);
    }
    else if (ui->userAgeLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Driver & Vehicles"),
                             tr("The age is empty.\n"
                                "Please provide a valid value."),
                             QMessageBox::Ok);
    }
    else
    {
        processInformation();
    }
}

void MainWindow::on_changeStatePushButton_clicked()
{
    Vehicle* returnedVehicle;
    std::vector<Vehicle*> vehicles = m_gameLauncher->getVehicles();
    for (std::vector<Vehicle*>::iterator vehicleIterator = vehicles.begin(); vehicleIterator != vehicles.end(); vehicleIterator++)
    {
        if (QString::fromStdString((*vehicleIterator)->getIdentifier()).contains(ui->vehicleIdentifierLineEdit->text()))
        {
            returnedVehicle = *vehicleIterator;
            break;
        }
    }
    if (returnedVehicle->isRunning())
    {
        returnedVehicle->stop();
    }
    else
    {
        returnedVehicle->start();
    }
    refreshTable();
    addLogs();
}

