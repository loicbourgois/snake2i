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

Map::Map() : width(16) ,height(16)
{
    for(int i = 0 ; i < height ; i++)
    {
        map.push_back(std::vector<char>(width));
    }
    for(int j = 0 ; j < height ; j++)
    {
        for(int i = 0 ; i < width ; i++)
        {
            map[i][j] = '.';
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

void Map::setTile(char value, int x, int y)
{
    if(x < width && y < height && x >= 0 && y >=0)
        map[x][y] = value;
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

QString Map::getPosition(char c)
{
    for(int j = 0 ; j < height ; j++)
    {
        for(int i = 0 ; i < width ; i++)
        {
            if(c == map[j][i])
                return QString::number(j) + "|" + QString::number(i);
        }
    }
    return QString();
}
