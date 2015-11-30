#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>

class Scene;

class Food : public QGraphicsItem
{
public:
    Food(Scene * scene, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int step);
private:
    int radius;
    QPolygon polygon;
};

#endif // FOOD_H
