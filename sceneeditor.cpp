#include "sceneeditor.h"
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "wall.h"

SceneEditor::SceneEditor(QObject * parent) : QGraphicsScene(parent)
{

}

void SceneEditor::mouseReleaseEvent( QGraphicsSceneMouseEvent * event )
{
     QGraphicsItem *item;
     QTransform test;
     item = itemAt(event->scenePos(),test); //Get the item at the position
     if (item) //If there is an item at that position
     {
         emit deleted(item->x(),item->y());
         removeItem(item);
     }
}

