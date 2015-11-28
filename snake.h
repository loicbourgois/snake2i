#ifndef SNAKE_H
#define SNAKE_H

#include "head.h"
#include "scene.h"
#include <vector>

class BodyPart{
public:
    BodyPart(){}
    BodyPart(int x, int y){this->x = x; this->y = y;}
    int x;
    int y;
};

class Snake
{
public:
    Snake();
    Snake(Scene * scene);
    void addHead(int x, int y);
    void addBodyPart(int x, int y);
    void setDirection(char direction);
private:
    Head * head;
    std::vector<BodyPart> body;
    char direction;
    Scene * scene;
};

#endif // SNAKE_H
