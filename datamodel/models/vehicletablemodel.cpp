#include "vehicletablemodel.h"
#include "vehicle.h"
#include <QFont>
#include <QBrush>

VehicleTableModel::VehicleTableModel(QObject *parent, std::vector<Vehicle*> vehicles)
    : QAbstractTableModel(parent)
    , m_vehicles(vehicles)
{
}

int VehicleTableModel::rowCount(const QModelIndex & /*parent*/) const
{
    return m_vehicles.size();
}

int VehicleTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return COLUMNS;
}

QVariant VehicleTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::DisplayRole)
    {
        if (col == 0)
        {
            return QString("%1").arg(QString::fromStdString(m_vehicles.at(row)->getIdentifier()));
        }
        else
        {
            return QString("%1").arg(m_vehicles.at(row)->isRunning() ? QString("running") : QString("stopped"));
        }
    }
    return QVariant();
}
