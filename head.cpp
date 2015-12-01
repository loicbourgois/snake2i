#include "head.h"
#include "snake.h"
#include <QPainter>
#include <QColor>

#include <QDebug>

Head::Head(Scene * scene, int x, int y) : QGraphicsItem(),
    radius(10),
    polygon(),
    direction(' ')
{
    this->setPos(x*radius*2, y*radius*2);
    polygon.append(QPoint(radius, radius));
    polygon.append(QPoint(radius, -radius));
    polygon.append(QPoint(-radius, -radius));
    polygon.append(QPoint(-radius, radius));
}

QRectF Head::boundingRect() const
{
    return QRectF(-radius*2,-radius*2,radius*2*2,radius*2*2);
}

void Head::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(0,128,0));
    QRectF rect(-radius+1,-radius+1,radius*2-2,radius*2-2);
    //QRectF rect(-radius,-radius,radius*2,radius*2);
    painter->drawRoundedRect(rect, 4, 4);
    //
    painter->setBrush(Qt::white);
    painter->drawEllipse(QPointF(-radius/2,-radius), radius/2, radius/2);
    painter->drawEllipse(QPointF(+radius/2,-radius), radius/2, radius/2);
    painter->setBrush(Qt::black);
    painter->drawEllipse(QPointF(-radius/2,-radius), radius/5, radius/5);
    painter->drawEllipse(QPointF(+radius/2,-radius), radius/5, radius/5);
    //
    if(direction == 'u')
    {
        this->setRotation(0);
    }
    else if(direction == 'd')
    {
        this->setRotation(180);
    }
    else if(direction == 'l')
    {
        this->setRotation(90*3);
    }
    else if(direction == 'r')
    {
        this->setRotation(90);
    }
}

void Head::advance(int step)
{
    if (!step)
        return;
}

void Head::setDirection(char direction)
{
    this->direction = direction;
}

