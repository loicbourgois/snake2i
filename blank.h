#ifndef BLANK_H
#define BLANK_H


#include <QGraphicsItem>

class Scene;

class Blank : public QGraphicsItem
{
public:
    Blank(Scene * scene, int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int step);
private:
    int radius;
    QPolygon polygon;
};

#endif // BLANK_H
