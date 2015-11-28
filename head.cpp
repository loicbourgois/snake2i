#include "head.h"
#include <QPainter>
#include <QColor>

Head::Head(Scene * scene, int x, int y) : QGraphicsItem(),
    radius(10),
    polygon()
{
    this->setPos(x*radius*2, y*radius*2);
    polygon.append(QPoint(radius, radius));
    polygon.append(QPoint(radius, -radius));
    polygon.append(QPoint(-radius, -radius));
    polygon.append(QPoint(-radius, radius));
}

QRectF Head::boundingRect() const
{
    return QRectF(-radius,-radius,radius*2,radius*2);
}

void Head::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(0,200,0));
    painter->drawPolygon(polygon);
}

void Head::advance(int step)
{
    if (!step)
        return;
}

