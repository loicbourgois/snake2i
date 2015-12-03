#ifndef ERASER_H
#define ERASER_H


#include <QGraphicsItem>

class Scene;

class Eraser : public QGraphicsItem
{
public:
    Eraser(Scene * scene, int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int step);
private:
    float radius;
    QPolygon polygon;
};
#endif // ERASER_H
