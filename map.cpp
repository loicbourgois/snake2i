#include "map.h"
#include <fstream>

#include <QDebug>
#include <QVector>

Map::Map(std::string filename) :
    width(0),
    height(0)
{
    std::ifstream file(filename.c_str());
    file >> direction;
    file >> width;
    file >> height;
    std::string line;
    getline(file, line); // needed to go to the next line
    for(int i = 0 ; i < height ; i++)
    {
        map.push_back(std::vector<char>(width));

    }
    for(int j = 0 ; j < height ; j++)
    {
        getline(file, line);
        for(int i = 0 ; i < width ; i++)
        {
            map[i][j] = line[i];
        }
    }
}

char Map::getTile(int x, int y)
{
    if(x >= 0 && x < width && y >= 0 && y < height)
    {
        return map[x][y];
    }
    else
        return -1;
}

int Map::getWidth()
{
    return width;
}

int Map::getHeight()
{
    return height;
}

char Map::getDirection()
{
    return direction;
}