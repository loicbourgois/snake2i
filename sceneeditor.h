#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QGraphicsScene>
#include <QObject>

class SceneEditor : public QGraphicsScene
{
    Q_OBJECT
    //Emit lorsqu'on delete un item puis dans le forme on le detecte et on en met un autre à cette position
public:
    SceneEditor(QObject * parent);
private:
    void mouseReleaseEvent( QGraphicsSceneMouseEvent * event );
signals:
    void deleted(double x,double y);
};

#endif // SCENEEDITOR_H
