#ifndef HEAD_H
#define HEAD_H


#include <QGraphicsItem>

class Scene;

class Head : public QGraphicsItem
{
public:
    Head(Scene * scene, int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int step);
private:
    int radius;
    QPolygon polygon;
};

#endif // HEAD_H
