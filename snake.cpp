#include "snake.h"

#include <QDebug>

Snake::Snake() :
    xSpeed(0),
    ySpeed(0),
    alive(true)
{

}

Snake::Snake(Scene *scene) :
    scene(scene),
    xSpeed(0),
    ySpeed(0),
    alive(true)
{

}

void Snake::addHead(int x, int y)
{
    this->head = new Head(scene, x, y);
    scene->addItem(head);
    head->setZValue(9999);
}

void Snake::addBodyPart(int x, int y)
{
    if(!body.size())
    {
        this->body.push_back(new BodyPart(scene, x, y));
        scene->addItem(body.back());
    }
    else
    {
        this->body.push_back(new BodyPart(scene, head->pos().x() / 20, head->pos().y() / 20));
        scene->addItem(body.back());
    }
}

void Snake::setDirection(char direction)
{
    this->direction = direction;
    if(direction == 'u')
    {
        xSpeed = 0;
        ySpeed = -1;
    }
    else if(direction == 'd')
    {
        xSpeed = 0;
        ySpeed = 1;
    }
    else if(direction == 'l')
    {
        xSpeed = -1;
        ySpeed = 0;
    }
    else if(direction == 'r')
    {
        xSpeed = 1;
        ySpeed = 0;
    }
}

void Snake::move(Map map)
{
    int radius = 10;
    int step = 2*radius;
    int width = map.getWidth() * step;
    int height = map.getHeight() * step;
    //
    int newx = (int)((head->pos().x() + xSpeed * step)) % (width);
    if(newx < 0)
        newx = width - step;
    int newy = (int)((head->pos().y() + ySpeed * step)) % (height);
    if(newy < 0)
        newy = height - step;
    //
    if(alive)
    {
        for(int i = body.size()-1 ; i > 0 ; i--)
        {
            body[i]->setPos(body[i-1]->pos().x(), body[i-1]->pos().y());
        }
        body[0]->setPos(head->pos().x(), head->pos().y());
        this->head->setPos(newx, newy);
    }
    // Die ?
    if(map.getTile(newx/step, newy/step) == 'w')
    {
        alive = false;
    }
}

Head * Snake::getHead()
{
    return head;
}
