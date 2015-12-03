#include "eraser.h"
#include <QPainter>
#include <QColor>
#include <QPointF>

Eraser::Eraser(Scene *scene, int x, int y) : QGraphicsItem(),
    radius(10),
    polygon(),
    polygon2()
{
    setPos(x*radius*2, y*radius*2);
    polygon.append(QPoint(radius/5, radius));
    polygon.append(QPoint(radius/5, -radius));
    polygon.append(QPoint(-radius/5, -radius));
    polygon.append(QPoint(-radius/5, radius));

    polygon2.append(QPoint(radius, radius/5));
    polygon2.append(QPoint(radius, -radius/5));
    polygon2.append(QPoint(-radius, -radius/5));
    polygon2.append(QPoint(-radius, radius/5));
    this->setRotation(45);
}

QRectF Eraser::boundingRect() const
{
    return QRectF(-radius,-radius,radius*2,radius*2);
}

void Eraser::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(192,0,0));
    painter->drawPolygon(polygon);
    painter->drawPolygon(polygon2);
    //painter->drawLine(QPointF(0,radius), QPointF(0, -radius));
    //painter->dra
}

void Eraser::advance(int step)
{
    if (!step)
        return;
}
