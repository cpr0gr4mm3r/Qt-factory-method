#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller/gamelauncher.h"
#include "datamodel/models/VehicleTableModel.h"
#include "utilities.h"
#include <QMessageBox>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_gameLauncher(new GameLauncher())
{
    ui->setupUi(this);
    ui->changeStatePushButton->setEnabled(false);
    connect(ui->userNameLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(onUserNameLineEditTextChanged(const QString &)));
    connect(ui->userAgeLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(onUserAgeLineEditTextChanged(const QString &)));
    connect(ui->carLicenseCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onCarLicenseCheckBoxStateChanged(int)));
    connect(ui->motorcycleLicenseCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onMotorcycleLicenseCheckBoxStateChanged(int)));
    connect(ui->boatLicenseCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onBoatLicenseCheckBoxStateChanged(int)));
    connect(ui->planeLicenseCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onPlaneLicenseCheckBoxStateChanged(int)));
    //connect(ui->startGamePushButton, &QPushButton::clicked, this, &MainWindow::onStartGamePushButtonClicked);
    connect(ui->startGamePushButton, SIGNAL(clicked()), this, SLOT(onStartGamePushButtonClicked()));
    connect(ui->changeStatePushButton, SIGNAL(clicked()), this, SLOT(onChangeStatePushButtonClicked()));
    connect(this, SIGNAL(sendNameToGameLauncher(const std::string &)), m_gameLauncher, SLOT(receiveNameFromGui(const std::string &)));
    connect(this, SIGNAL(sendAgeToGameLauncher(const std::string &)), m_gameLauncher, SLOT(receiveAgeFromGui(const std::string &)));
    connect(m_gameLauncher, SIGNAL(sendModelToGui(VehicleTableModel*)), this, SLOT(receiveModelFromGameLauncher(VehicleTableModel*)));
    connect(m_gameLauncher, SIGNAL(sendLogsModelToGui(QStringListModel*)), this, SLOT(receiveLogsModelFromGameLauncher(QStringListModel*)));
    connect(m_gameLauncher, SIGNAL(sendVehiclesToGui(std::vector<Vehicle*>)), this, SLOT(refreshVehiclesTableWidget(std::vector<Vehicle*>)));
    connect(this, SIGNAL(sendCarLicenseToGameLauncher(const bool &)), m_gameLauncher, SLOT(receiveCarLicenseFromGui(const bool &)));
    connect(this, SIGNAL(sendMotorbikeLicenseToGameLauncher(const bool &)), m_gameLauncher, SLOT(receiveMotorbikeLicenseFromGui(const bool &)));
    connect(this, SIGNAL(sendBoatLicenseToGameLauncher(const bool &)), m_gameLauncher, SLOT(receiveBoatLicenseFromGui(const bool &)));
    connect(this, SIGNAL(sendPlaneLicenseToGameLauncher(const bool &)), m_gameLauncher, SLOT(receivePlaneLicenseFromGui(const bool &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshVehiclesTableWidget(std::vector<Vehicle*> vehicles)
{
    ui->vehiclesTableWidget->clear();
    ui->vehiclesTableWidget->setRowCount(vehicles.size());
    ui->vehiclesTableWidget->setColumnCount(VehicleTableModel::COLUMNS);
    int row = 0;
    for (std::vector<Vehicle*>::iterator vehicleIterator = vehicles.begin(); vehicleIterator != vehicles.end(); vehicleIterator++)
    {
        ui->vehiclesTableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString((*vehicleIterator)->getIdentifier())));
        ui->vehiclesTableWidget->setItem(row++, 1, new QTableWidgetItem((*vehicleIterator)->isRunning() ? QString("running") : QString("stopped")));
    }
}


void MainWindow::processInformation()
{
    if (Utilities::ageIsValid(ui->userAgeLineEdit->text()))
    {
        ui->startGamePushButton->setEnabled(false);
        ui->changeStatePushButton->setEnabled(true);
        if (!m_gameLauncher->isInitializated())
        {
            m_gameLauncher->initGame();
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Driver & Vehicles"),
                             tr("The age is not valid.\n"
                                "Please provide a valid value."),
                             QMessageBox::Ok);
    }
}

void MainWindow::onStartGamePushButtonClicked()
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

void MainWindow::onChangeStatePushButtonClicked()
{
    try
    {
        m_gameLauncher->updateState(ui->userNameLineEdit->text().toStdString(), ui->vehicleIdentifierLineEdit->text().toStdString());
    }
    catch (const std::out_of_range&)
    {
        QMessageBox::warning(this, tr("Driver & Vehicles"),
                             tr("The user was not found.\n"
                                "Please provide a valid value."),
                             QMessageBox::Ok);
    }
}

void MainWindow::onUserNameLineEditTextChanged(const QString &arg1)
{
    emit sendNameToGameLauncher(arg1.toStdString());
}

void MainWindow::onUserAgeLineEditTextChanged(const QString &arg1)
{
    emit sendAgeToGameLauncher(arg1.toStdString());
}

void MainWindow::receiveModelFromGameLauncher(VehicleTableModel* model)
{
    ui->vehiclesTableView->setModel(model);
}

void MainWindow::receiveLogsModelFromGameLauncher(QStringListModel* model)
{
    ui->logListView->setModel(model);
}

void MainWindow::onCarLicenseCheckBoxStateChanged(int arg1)
{
    emit sendCarLicenseToGameLauncher(arg1);
}

void MainWindow::onMotorcycleLicenseCheckBoxStateChanged(int arg1)
{
    emit sendMotorbikeLicenseToGameLauncher(arg1);
}

void MainWindow::onBoatLicenseCheckBoxStateChanged(int arg1)
{
    emit sendBoatLicenseToGameLauncher(arg1);
}

void MainWindow::onPlaneLicenseCheckBoxStateChanged(int arg1)
{
    emit sendPlaneLicenseToGameLauncher(arg1);
}
