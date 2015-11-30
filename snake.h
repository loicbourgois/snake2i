#ifndef SNAKE_H
#define SNAKE_H

#include "bodypart.h"
#include "head.h"
#include "map.h"
#include "scene.h"
#include <vector>

class Snake
{
public:
    Snake();
    Snake(Scene * scene);
    void addHead(int x, int y);
    void addBodyPart(int x, int y);
    void setDirection(char direction);
    void move(Map map);
    Head *getHead();
private:
    Head * head;
    std::vector<BodyPart*> body;
    char direction;
    Scene * scene;
    int xSpeed;
    int ySpeed;
    bool alive;
};

#endif // SNAKE_H
