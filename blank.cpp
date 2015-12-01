#include "blank.h"
#include <QPainter>
#include <QColor>

Blank::Blank(Scene *scene, int x, int y) : QGraphicsItem(),
    radius(10),
    polygon()
{
    this->setPos(x*radius*2, y*radius*2);
    polygon.append(QPoint(radius, radius));
    polygon.append(QPoint(radius, -radius));
    polygon.append(QPoint(-radius, -radius));
    polygon.append(QPoint(-radius, radius));
}

QRectF Blank::boundingRect() const
{
    return QRectF(-radius,-radius,radius*2,radius*2);
}

void Blank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(170,204,153));
    painter->drawPolygon(polygon);
}

void Blank::advance(int step)
{
    if (!step)
        return;
}
