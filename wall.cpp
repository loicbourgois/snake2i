#include "wall.h"
#include <QPainter>
#include <QColor>

Wall::Wall(Scene *scene, int x, int y) : QGraphicsItem(),
    radius(10),
    polygon()
{
    this->setPos(x*radius*2, y*radius*2);
    polygon.append(QPoint(radius, radius));
    polygon.append(QPoint(radius, -radius));
    polygon.append(QPoint(-radius, -radius));
    polygon.append(QPoint(-radius, radius));
}

QRectF Wall::boundingRect() const
{
    return QRectF(-radius,-radius,radius*2,radius*2);
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(255,0,0));
    painter->drawPolygon(polygon);
}

void Wall::advance(int step)
{
    if (!step)
        return;
}

