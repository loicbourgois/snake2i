#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QGraphicsScene>
#include <QObject>
#include <QMouseEvent>

class EditorForm;

class SceneEditor : public QGraphicsScene
{
    Q_OBJECT
    //Emit lorsqu'on delete un item puis dans le forme on le detecte et on en met un autre à cette position
public:
    SceneEditor(QWidget *parent);
private:
    void mouseReleaseEvent( QGraphicsSceneMouseEvent * event );
    void mouseMoveEvent(QGraphicsSceneMouseEvent*e);
    QGraphicsItem *cursor;
    EditorForm * parent;
signals:
    void deleted(double x,double y);
};

#endif // SCENEEDITOR_H
