#ifndef WALL_H
#define WALL_H

#include <QGraphicsItem>

class Scene;

class Wall : public QGraphicsItem
{
public:
    Wall(Scene * scene, int x, int y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int step);
private:
    int radius;
    QPolygon polygon;
};

#endif // WALL_H
