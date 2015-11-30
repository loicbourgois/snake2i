#ifndef UTIL_H
#define UTIL_H


class Util
{
public:
    Util();
    static int getRandomInt(const int &min, const int &max);
    static float getRandomFloat(const float &min, const float &max);
    static void inite();
};

#endif // UTIL_H
