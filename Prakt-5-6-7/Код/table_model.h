#ifndef SIMPLETABLEMODEL_H
#define SIMPLETABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>

class SimpleTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit SimpleTableModel(int rows = 15, int cols = 5, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void insertRowAt(int pos);
    void removeRowAt(int pos);
    void insertColumnAt(int pos);
    void removeColumnAt(int pos);

    void setAllData(const QVector<QVector<QVariant>> &data);

private:
    QVector<QVector<QVariant>> m_cells;
};

#endif
