#ifndef CHART_BUILDER_H
#define CHART_BUILDER_H


#include <QGraphicsScene>
#include <QTableView>
#include "table_model.h"

class ChartBuilder : public QGraphicsScene{

public:
    explicit ChartBuilder(QTableView* sourceTable, QObject* parent = nullptr);
    void buildBarChart(const QModelIndexList& selectedCells);
    void exportToPng(const QString &path);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event);


private:
    QTableView* m_sourceTable;
    QMap<QString, double> m_data;
    double curSize;
    double max;
    QBrush* curBrush;
    void updateOutput();

    QAction* red;
    QAction* blue;
    QAction* yellow;
    QAction* green;
    QAction* quarter;
    QAction* half;
    QAction* halfquarter;
    QAction* one;
    QAction* onequarter;
    QAction* onehalf;
    QAction* onehalfquarter;
    QAction* two;
};



#endif // CHART_BUILDER_H
