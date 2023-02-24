#ifndef VEHICLETABLEMODEL_H
#define VEHICLETABLEMODEL_H


#include <QAbstractTableModel>
#include <vector>

class Vehicle;

/**
 * @brief The VehicleTableModel class is a QAbstractTableModel class used to generate the model that will be interpreted by a table view to display the information in the main window.
 */
class VehicleTableModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    /**
     * @brief m_vehicles. The vehicles list with the information to be shown in the table view.
     */
    std::vector<Vehicle*> m_vehicles;
public:
    /**
     * @brief COLUMNS. Constant used to set the number of columns.
     */
    static const unsigned int COLUMNS = 2;
public:
    /**
     * @brief VehicleTableModel. Constructor.
     * @param parent. The object used to invoke all the ascendant contructors of ascendant classes.
     * @param vehicles. Vector with the information that will be displayed in the table view cells.
     */
    explicit VehicleTableModel(QObject *parent = nullptr, std::vector<Vehicle*> vehicles = {});

    /**
     * @brief rowCount. Override method used to set the number of rows that will be displayed in the table view.
     * @param parent. The model index object. Usually is not used.
     * @return The number of rows that will be displayed in the table view.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @brief columnCount. Override method used to set the number of columns that will be displayed in the table view.
     * @param parent. The model index object. Usually is not used.
     * @return The number of columns that will be displayed in the table view.
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @brief data. Displays in the cells the vehicle information.
     * @param index. Model index used to get the column and the row for get the table view cell for display the data.
     * @param role. The display role used to discriminate the fact of the display or not.
     * @return. A variant data with the information to be shown. This is interpreted by a table view to display the information in the proper cell.
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // VEHICLETABLEMODEL_H
