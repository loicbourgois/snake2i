#include "bodypart.h"
#include <QPainter>
#include <QColor>

#include <QDebug>

BodyPart::BodyPart(Scene * scene, int x, int y) : QGraphicsItem(),
    radius(10),
    polygon()
{
    this->setPos(x*radius*2, y*radius*2);
    polygon.append(QPoint(radius, radius));
    polygon.append(QPoint(radius, -radius));
    polygon.append(QPoint(-radius, -radius));
    polygon.append(QPoint(-radius, radius));
}

QRectF BodyPart::boundingRect() const
{
    return QRectF(-radius,-radius,radius*2,radius*2);
}

void BodyPart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option;
    (void)widget;
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(0,192,0));
    QRectF rect(-radius+1,-radius+1,radius*2-2,radius*2-2);
    painter->drawRoundedRect( rect, 4, 4 );
}

void BodyPart::advance(int step)
{
    if (!step)
        return;
}

