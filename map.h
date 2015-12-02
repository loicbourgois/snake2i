#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <QString>

class Map
{
public:
    Map(std::string filename);
    Map();
    char getTile(int x, int y);
    void setTile(char value,int x,int y);
    int getWidth();
    int getHeight();
    char getDirection();
    QString getPosition(char c);
private:
    std::vector< std::vector<char> > map;
    int width;
    int height;
    char direction;
};

#endif // MAP_H
