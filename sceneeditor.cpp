#include "sceneeditor.h"
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "wall.h"
#include <QMouseEvent>
#include <QWidget>
#include "eraser.h"
#include "editor-form.h"

SceneEditor::SceneEditor(QWidget * parent) : QGraphicsScene(parent)
{
    cursor = new Wall(NULL,0,0);
    cursor->setZValue(9999);
    this->parent = (EditorForm*)parent;
}

void SceneEditor::mouseReleaseEvent( QGraphicsSceneMouseEvent * event )
{
    emit deleted(cursor->x(),cursor->y());
}

void SceneEditor::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    int x = event->scenePos().x();
    int y = event->scenePos().y();
    this->removeItem(cursor);
    switch(parent->choice)
    {
    case 0 :
        cursor = new Eraser(NULL,x/20,y/20);
        break;
    case 1 :
        cursor = new Wall(NULL,x/20,y/20);
        break;
    case 2:
        cursor = new Head(NULL,x/20,y/20);
        break;
    case 3:
        cursor = new BodyPart(NULL,x/20,y/20);
        break;
    }


    this->addItem(cursor);
}



