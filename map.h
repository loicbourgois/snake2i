#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Map
{
public:
    Map(std::string filename);
    char getTile(int x, int y);
    int getWidth();
    int getHeight();
private:
    std::vector< std::vector<char> > map;
    int width;
    int height;
};

#endif // MAP_H
