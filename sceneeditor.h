#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QGraphicsScene>

class SceneEditor : public QGraphicsScene
{
public:
    SceneEditor(QObject * parent);
private:
    void mouseReleaseEvent( QGraphicsSceneMouseEvent * event );
};

#endif // SCENEEDITOR_H
