#ifndef BODYPART_H
#define BODYPART_H

#include "scene.h"
#include <QGraphicsItem>

class BodyPart : public QGraphicsItem
{
public:
    BodyPart(Scene * scene, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int step);
private:
    int radius;
    QPolygon polygon;
};

#endif // BODYPART_H
