#ifndef VEHICLETABLEMODEL_H
#define VEHICLETABLEMODEL_H


#include <QAbstractTableModel>
#include <vector>

class Vehicle;

class VehicleTableModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    std::vector<Vehicle*> m_vehicles;
public:
    static const unsigned int COLUMNS = 2;
public:
    explicit VehicleTableModel(QObject *parent = nullptr, std::vector<Vehicle*> vehicles = {});

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // VEHICLETABLEMODEL_H
