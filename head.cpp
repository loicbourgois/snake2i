#include "head.h"
#include <QPainter>
#include <QColor>

#include <QDebug>

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
    painter->setBrush(QColor(0,128,0));
    QRectF rect(-radius+1,-radius+1,radius*2-2,radius*2-2);
    painter->drawRoundedRect( rect, 4, 4 );
}

void Head::advance(int step)
{
    if (!step)
        return;
}

