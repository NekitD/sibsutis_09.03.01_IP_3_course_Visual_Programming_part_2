/**
 * Copyright 2022 naracanto <https://naracanto.github.io>.
 *
 * This file is part of QTabelo <https://github.com/beletalabs/qtabelo>.
 *
 * QTabelo is an open source table editor written in C++ using the
 * Qt framework.
 *
 * QTabelo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * QTabelo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QTabelo.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "table_document.h"
#include "document_widget.h"
#include "chart_builder.h"

#include <QSettings>
#include <QTabBar>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QMenu>
#include <algorithm>
#include "table_model.h"
#include <QGraphicsView>

using std::sort;


TableDocument::TableDocument(QWidget *parent)
    : QWidget(parent)
    , m_tabs{new QTabWidget}
    , m_tabBarVisible{true}
{
    m_tabs->setDocumentMode(true);
    m_tabs->setMovable(true);
    m_tabs->setTabPosition(QTabWidget::South);
    m_tabs->setTabBarAutoHide(true);
    connect(m_tabs, &QTabWidget::tabCloseRequested, this, &TableDocument::slotCloseTab);

    loadSettings();

    // Main layout
    auto *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_tabs);
    setLayout(mainLayout);

}


void TableDocument::loadSettings()
{
    QSettings settings;

    // Sheet Tab Bar Visible
    const bool visible = settings.value(QStringLiteral("Document/SheetTabBarVisible"), true).toBool();
    setTabBarVisible(visible);

    // Sheet Tab Bar Position
    const int value = settings.value(QStringLiteral("Document/SheetTabBarPosition"), QTabWidget::South).toInt();
    const QList<int> values = {QTabWidget::North, QTabWidget::South};
    const QTabWidget::TabPosition position = values.contains(value) ? static_cast<QTabWidget::TabPosition>(value) : QTabWidget::South;
    setTabBarPosition(position);

    // Sheet Tab Bar Auto Hide
    const bool enabled = settings.value(QStringLiteral("Document/SheetTabBarAutoHide"), true).toBool();
    setTabBarAutoHide(enabled);
}


void TableDocument::saveSettings()
{
    QSettings settings;

    // Sheet Tab Bar Visible
//    const bool visible = isTabBarVisible();
//    settings.setValue(QStringLiteral("Document/SheetTabBarVisible"), visible);

    // Sheet Tab Bar Position
//    const QTabWidget::TabPosition position = tabBarPosition();
//    settings.setValue(QStringLiteral("Document/SheetTabBarPosition"), position);

    // Sheet Tab Bar Auto Hide
//    const bool enabled = isTabBarAutoHide();
//    settings.setValue(QStringLiteral("Document/SheetTabBarAutoHide"), enabled);
}


//
// Property: tabBarVisible
//

bool TableDocument::isTabBarVisible() const
{
    return m_tabBarVisible;
}


void TableDocument::setTabBarVisible(const bool visible)
{
    if (visible != isTabBarVisible()) {
        m_tabBarVisible = visible;
        _setTabBarVisible(isTabBarVisible());
        emit tabBarVisibleChanged(isTabBarVisible());
    }
}


void TableDocument::resetTabBarVisible()
{
    m_tabBarVisible = true;
    _setTabBarVisible(isTabBarVisible());
    emit tabBarVisibleChanged(isTabBarVisible());
}


void TableDocument::initTabBarVisible()
{
    _setTabBarVisible(isTabBarVisible());
    emit tabBarVisibleChanged(isTabBarVisible());
}


void TableDocument::_setTabBarVisible(const bool visible)
{
    if (!(m_tabs->count() <= 1 && m_tabs->tabBarAutoHide()))
        m_tabs->tabBar()->setVisible(visible);
}


//
// Property: tabBarPosition
//

QTabWidget::TabPosition TableDocument::tabBarPosition() const
{
    return m_tabs->tabPosition();
}


void TableDocument::setTabBarPosition(const QTabWidget::TabPosition position)
{
    if (position != tabBarPosition()) {
        m_tabs->setTabPosition(position);
        emit tabBarPositionChanged(tabBarPosition());
    }
}


void TableDocument::resetTabBarPosition()
{
    m_tabs->setTabPosition(QTabWidget::South);
    emit tabBarPositionChanged(tabBarPosition());
}


void TableDocument::initTabBarPosition()
{
    emit tabBarPositionChanged(tabBarPosition());
}


//
// Property: tabBarAutoHide
//

bool TableDocument::isTabBarAutoHide() const
{
    return m_tabs->tabBarAutoHide();
}


void TableDocument::setTabBarAutoHide(const bool enabled)
{
    if (enabled != isTabBarAutoHide()) {
        m_tabs->setTabBarAutoHide(enabled);
        emit tabBarAutoHideChanged(isTabBarAutoHide());
    }
}


void TableDocument::resetTabBarAutoHide()
{
    m_tabs->setTabBarAutoHide(true);
    emit tabBarAutoHideChanged(isTabBarAutoHide());
}


void TableDocument::initTabBarAutoHide()
{
    emit tabBarAutoHideChanged(isTabBarAutoHide());
}


//
// Slots
//

void TableDocument::slotAddTab(const int count)
{
    if (!m_tabs->count()) {

        for (int i = 1; i <= count; ++i) {
              QTableView* tableView = new QTableView(this);
              SimpleTableModel* model = new SimpleTableModel(15, 5, tableView);
              tableView->setModel(model);

              tableView->setContextMenuPolicy(Qt::CustomContextMenu);
              connect(tableView, &QTableView::customContextMenuRequested, this,
                      [this, tableView](const QPoint &pos){
                            showTableContextMenu(tableView, pos);
                      });

              connect(model, &QAbstractItemModel::dataChanged,
                      this, [this](...) {
                          emit contentModified(true);
                      });

                m_tabs->addTab(tableView, QString("Sheet %1").arg(i));
        }
        m_tabs->setTabsClosable(m_tabs->count() > 1);
    }
}


void TableDocument::slotCloseTab(const int index)
{
    if (m_tabs->count() > 1) {

        auto widget = m_tabs->widget(index);
        if (widget) {
            widget->close();
            m_tabs->removeTab(index);
        }

        m_tabs->setTabsClosable(m_tabs->count() > 1);
    }
}

void TableDocument::showTableContextMenu(QTableView* table, const QPoint &pos){

//    QList selectedItems = table->selectedItems();

    QMenu* contextMenu = new QMenu;
    QAction* addRow = contextMenu->addAction("Добавить строку");
    QAction* delRow = contextMenu->addAction("Удалить строку");
    QAction* addCol = contextMenu->addAction("Добавить столбец");
    QAction* delCol = contextMenu->addAction("Удалить столбец");
    QAction* diagram = contextMenu->addAction("Диаграмма");

    QAction* selectedAction = contextMenu->exec(table->mapToGlobal(pos));

    if(!selectedAction){
        return;
    }

    auto model = qobject_cast<SimpleTableModel*>(table->model());

    if (selectedAction == addRow) {
        model->insertRowAt(model->rowCount());
        emit contentModified(true);
    }
    if (selectedAction == delRow) {

        QModelIndexList sel = table->selectionModel()->selectedIndexes();
        QSet<int> uniqueRows;
        for (const QModelIndex &index : sel) {
            uniqueRows.insert(index.row());
        }
        QList<int> rows = uniqueRows.values();
        std::sort(rows.begin(), rows.end(), std::greater<int>());

        for (int row : rows) {
            model->removeRowAt(row);
        }
        emit contentModified(true);
    }

    if (selectedAction == addCol) {
        model->insertColumnAt(model->columnCount());
        emit contentModified(true);
    }
    if (selectedAction == delCol) {

        QModelIndexList sel = table->selectionModel()->selectedIndexes();
        QSet<int> uniqueCols;
        for (const QModelIndex &index : sel) {
            uniqueCols.insert(index.column());
        }
        QList<int> cols = uniqueCols.values();
        sort(cols.begin(), cols.end(), std::greater<int>());

        for (int col : cols) {
            model->removeColumnAt(col);
        }
        emit contentModified(true);
    }

    if (selectedAction == diagram) {
        auto* chart = new ChartBuilder(table);
        QModelIndexList currentSelected = table->selectionModel()->selectedIndexes();
        connect(table->model(), &QAbstractItemModel::dataChanged, this, [chart, currentSelected](){
            chart->buildBarChart(currentSelected);
        });
        chart->buildBarChart(currentSelected);
        QGraphicsView* chartView = new QGraphicsView(chart);
        int tabIndex = m_tabs->addTab(chartView, tr("Диаграмма"));
        m_tabs->setCurrentIndex(tabIndex);
        emit contentModified(true);
    }

}
