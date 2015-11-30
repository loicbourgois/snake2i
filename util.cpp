#include "util.h"

/*#include <QApplication>
#include "ui/main-window.hpp"
#include "core/util.hpp"*/
#include <time.h>
#include <QTime>

Util::Util()
{

}

void Util::inite()
{
    QTime time = QTime::currentTime();
    unsigned int seed = time.msec();
    qsrand(seed);
}

float Util::getRandomFloat(const float &min, const float &max)
{
    return ((static_cast <float>(qrand()))
            * (max - min)
            / (static_cast<float>(RAND_MAX)))
            + min;
}

int Util::getRandomInt(const int &min, const int &max)
{
    int r = getRandomFloat(min-1, max+1);
    if(r < min || r > max)
        r = getRandomInt(min, max);
    return r;
}
