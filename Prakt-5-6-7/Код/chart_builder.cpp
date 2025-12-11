#include "chart_builder.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneContextMenuEvent>
#include <QRectF>
#include <QPen>
#include <QMenu>
#include <QFileDialog>
#include <QTableView>
#include <QPainter>
#include <QImage>



ChartBuilder::ChartBuilder(QTableView* sourceTable, QObject* parent):
    QGraphicsScene(parent),
    m_sourceTable(sourceTable)
{
    curBrush = new QBrush(Qt::green);
    curSize = 1.0;

    red = new QAction("Красный");
    blue = new QAction("Синий");
    yellow = new QAction("Жёлтый");
    green = new QAction("Зелёный");


    red->setCheckable(true);
    blue->setCheckable(true);
    yellow->setCheckable(true);
    green->setCheckable(true);
    red->setChecked(false);
    blue->setChecked(false);
    green->setChecked(true);
    yellow->setChecked(false);


    quarter = new QAction("0.25");
    half = new QAction("0.5");
    halfquarter = new QAction("0.75");
    one = new QAction("1.0");
    onequarter = new QAction("1.25");
    onehalf = new QAction("1.5");
    onehalfquarter = new QAction("1.75");
    two = new QAction("2.0");

    quarter->setCheckable(true);
    half->setCheckable(true);
    halfquarter->setCheckable(true);
    one->setCheckable(true);
    one->setChecked(true);
    onequarter->setCheckable(true);
    onehalf->setCheckable(true);
    onehalfquarter->setCheckable(true);
    two->setCheckable(true);

};


void ChartBuilder::buildBarChart(const QModelIndexList& selectedCells){

    //clear();
    m_data.clear();


    max = 0;
    for(int i = 0; i < selectedCells.size() - 1; i+=2){
        QString label = selectedCells[i].data().toString();
        double value = selectedCells[i+1].data().toDouble();
        if(value > max) max = value;
        m_data.insert(label, value);
    }

    updateOutput();
}


void ChartBuilder::updateOutput(){
    clear();

    double maxHeigth = 300;
    double width = 60 * curSize;
    double space = 20 * curSize;

    double x = 0;
    QGraphicsRectItem* beginSpace = this->addRect(QRectF(x, -30, width/2, 30), QPen(Qt::white), QBrush(Qt::white));
    x += width/2 + space;
    QGraphicsLineItem* axisY = this->addLine(QLine(QPoint(int(x), 0), QPoint(int(x), int(-maxHeigth))),QPen(Qt::black));

    for(int y = -int(maxHeigth), v = max; y <= 0; y+=50, v-=max/6){
        QGraphicsLineItem* div = this->addLine(QLine(QPoint(int(x)-2, y), QPoint(int(x)+2, y)),QPen(Qt::black));
        QGraphicsTextItem* div_t = this->addText(QString("%1").arg(v));
        div_t->setPos(x - 40*curSize, y - 10*curSize);
    }
    QGraphicsLineItem* axisXb = this->addLine(QLine(QPoint(x, 0), QPoint(int(x)+int(width+space), 0)));
    x += width/2 + space;
    for(auto d = m_data.begin(); d != m_data.end(); d++){
        double normH = (d.value()/max) * maxHeigth;
        QGraphicsRectItem* column = this->addRect(QRectF(x, -normH, width, normH), QPen(Qt::black), *curBrush);
        QGraphicsTextItem* text;
        if(d.key().length() > 7){
            QString n_label;
            n_label = d.key().left(6) + "...";
            text = this->addText(n_label);
        } else {
            text = this->addText(d.key());
        }
        text->setPos(x + 8*curSize, 10);
        QGraphicsTextItem* valte = this->addText(QString::number(d.value()));
        valte->setPos(x, -normH - 20);
        QGraphicsLineItem* axisXn = this->addLine(QLine(QPoint(x, 0), QPoint(int(x)+int(width+space), 0)));
        x += width + space;
    }
    QGraphicsLineItem* axisXend = this->addLine(QLine(QPoint(x, 0), QPoint(int(x)+int(width+space), 0)));
    x += width + space;
    QGraphicsRectItem* endSpace = this->addRect(QRectF(x, -30, width/2, 30), QPen(Qt::white), QBrush(Qt::white));
}


void ChartBuilder::contextMenuEvent(QGraphicsSceneContextMenuEvent* event){

    QMenu* menu = new QMenu;
    QMenu* color = menu->addMenu("Цвет");
    color->addAction(red);
    color->addAction(blue);
    color->addAction(green);
    color->addAction(yellow);


    QMenu* size = menu->addMenu("Размер");
    size->addAction(quarter);
    size->addAction(half);
    size->addAction(halfquarter);
    size->addAction(one);
    size->addAction(onequarter);
    size->addAction(onehalf);
    size->addAction(onehalfquarter);
    size->addAction(two);


    QAction* savePng = menu->addAction("Экспортировать в PNG");
    QAction* selectedAction = menu->exec(event->screenPos());

    if(selectedAction == red){
        red->setChecked(true);
        blue->setChecked(false);
        green->setChecked(false);
        yellow->setChecked(false);
        delete curBrush;
        curBrush = new QBrush(Qt::red);
        updateOutput();

    }

    if(selectedAction == blue){
        red->setChecked(false);
        blue->setChecked(true);
        green->setChecked(false);
        yellow->setChecked(false);
        delete curBrush;
        curBrush = new QBrush(Qt::blue);
        updateOutput();
    }

    if(selectedAction == green){
        red->setChecked(false);
        blue->setChecked(false);
        green->setChecked(true);
        yellow->setChecked(false);
        delete curBrush;
        curBrush = new QBrush(Qt::green);
        updateOutput();
    }

    if(selectedAction == yellow){
        red->setChecked(false);
        blue->setChecked(false);
        green->setChecked(false);
        yellow->setChecked(true);
        delete curBrush;
        curBrush = new QBrush(Qt::yellow);
        updateOutput();
    }

    if(selectedAction == quarter){
        quarter->setChecked(true);
        half->setChecked(false);
        halfquarter->setChecked(false);
        one->setChecked(false);
        onequarter->setChecked(false);
        onehalf->setChecked(false);
        onehalfquarter->setChecked(false);
        two->setChecked(false);
        curSize = 0.25;
        updateOutput();
    }

    if(selectedAction == half){
        quarter->setChecked(false);
        half->setChecked(true);
        halfquarter->setChecked(false);
        one->setChecked(false);
        onequarter->setChecked(false);
        onehalf->setChecked(false);
        onehalfquarter->setChecked(false);
        two->setChecked(false);
        curSize = 0.5;
        updateOutput();
    }

    if(selectedAction == halfquarter){
        quarter->setChecked(false);
        half->setChecked(false);
        halfquarter->setChecked(true);
        one->setChecked(false);
        onequarter->setChecked(false);
        onehalf->setChecked(false);
        onehalfquarter->setChecked(false);
        two->setChecked(false);
        curSize = 0.75;
        updateOutput();
    }

    if(selectedAction == one){
        quarter->setChecked(false);
        half->setChecked(false);
        halfquarter->setChecked(false);
        one->setChecked(true);
        onequarter->setChecked(false);
        onehalf->setChecked(false);
        onehalfquarter->setChecked(false);
        two->setChecked(false);
        curSize = 1.0;
        updateOutput();
    }

    if(selectedAction == onequarter){
        quarter->setChecked(false);
        half->setChecked(false);
        halfquarter->setChecked(false);
        one->setChecked(false);
        onequarter->setChecked(true);
        onehalf->setChecked(false);
        onehalfquarter->setChecked(false);
        two->setChecked(false);
        curSize = 1.25;
        updateOutput();
    }

    if(selectedAction == onehalf){
        quarter->setChecked(false);
        half->setChecked(false);
        halfquarter->setChecked(false);
        one->setChecked(false);
        onequarter->setChecked(false);
        onehalf->setChecked(true);
        onehalfquarter->setChecked(false);
        two->setChecked(false);
        curSize = 1.5;
        updateOutput();
    }

    if(selectedAction == onehalfquarter){
        quarter->setChecked(false);
        half->setChecked(false);
        halfquarter->setChecked(false);
        one->setChecked(false);
        onequarter->setChecked(false);
        onehalf->setChecked(false);
        onehalfquarter->setChecked(true);
        two->setChecked(false);
        curSize = 1.75;
        updateOutput();
    }

    if(selectedAction == two){
        quarter->setChecked(false);
        half->setChecked(false);
        halfquarter->setChecked(false);
        one->setChecked(false);
        onequarter->setChecked(false);
        onehalf->setChecked(false);
        onehalfquarter->setChecked(false);
        two->setChecked(true);
        curSize = 2.0;
        updateOutput();
    }

    if(selectedAction == savePng){
        QString fileName = QFileDialog::getSaveFileName(nullptr, tr("Сохранить в PNG"), "C:\\Users\\Danik\\Desktop\\STUDY_SIBSUTIS_DOROGIN\\Visual.p2\\Prakt5\\docs", "*.png");

        if (fileName.isEmpty()) return;

        QRectF rect = itemsBoundingRect();

        QImage image(rect.size().toSize(), QImage::Format_ARGB32);
        image.fill(Qt::white);

        QPainter painter(&image);
        painter.setRenderHint(QPainter::Antialiasing);

        render(&painter, QRectF(), rect);

        image.save(fileName, "PNG");
    }
}
