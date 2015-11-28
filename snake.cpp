#include "snake.h"

Snake::Snake()
{

}

Snake::Snake(Scene *scene) :
    scene(scene)
{

}

void Snake::addHead(int x, int y)
{
    this->head = new Head(scene, x, y);
    scene->addItem(head);
}

void Snake::addBodyPart(int x, int y)
{
    this->body.push_back(BodyPart(x, y));
}

void Snake::setDirection(char direction)
{
    this->direction = direction;
}
