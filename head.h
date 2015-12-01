#ifndef HEAD_H
#define HEAD_H

#include <QGraphicsItem>


class Scene;
class Snake;

class Head : public QGraphicsItem
{
public:
    Head(Scene * scene, int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int step);
    void setDirection(char direction);
private:
    int radius;
    QPolygon polygon;
    char direction;
};

#endif // HEAD_H
