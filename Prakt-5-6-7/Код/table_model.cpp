#include "table_model.h"

SimpleTableModel::SimpleTableModel(int rows, int cols, QObject *parent)
    : QAbstractTableModel(parent)
{
    m_cells.resize(rows);
    for (auto &row : m_cells)
        row.resize(cols);
}

int SimpleTableModel::rowCount(const QModelIndex &) const {
    return m_cells.size();
}

int SimpleTableModel::columnCount(const QModelIndex &) const {
    return m_cells.isEmpty() ? 0 : m_cells[0].size();
}

QVariant SimpleTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return {};

    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return m_cells[index.row()][index.column()];

    return {};
}

bool SimpleTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole) return false;

    m_cells[index.row()][index.column()] = value;
    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags SimpleTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsDropEnabled;

    return Qt::ItemIsEnabled |
           Qt::ItemIsSelectable |
           Qt::ItemIsEditable;
}


void SimpleTableModel::insertRowAt(int pos)
{
    beginInsertRows(QModelIndex(), pos, pos);
    m_cells.insert(pos, QVector<QVariant>(columnCount()));
    endInsertRows();
}

void SimpleTableModel::removeRowAt(int pos)
{
    if (pos < 0 || pos >= rowCount()) return;
    beginRemoveRows(QModelIndex(), pos, pos);
    m_cells.removeAt(pos);
    endRemoveRows();
}

void SimpleTableModel::insertColumnAt(int pos)
{
    beginInsertColumns(QModelIndex(), pos, pos);
    for (auto &row : m_cells)
        row.insert(pos, QVariant());
    endInsertColumns();
}

void SimpleTableModel::removeColumnAt(int pos)
{
    beginRemoveColumns(QModelIndex(), pos, pos);
    for (auto &row : m_cells)
        row.removeAt(pos);
    endRemoveColumns();
}

void SimpleTableModel::setAllData(const QVector<QVector<QVariant>> &data)
{
    beginResetModel();
    m_cells = data;
    endResetModel();
}
