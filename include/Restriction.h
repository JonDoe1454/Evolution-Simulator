#ifndef RESTRICTION_H
#define RESTRICTION_H
#include <array>
#include <Coord.h>


namespace IB{

class Restriction
{
public:
    Restriction(int MinX, int MaxX, int MinY, int MaxY);
    bool PosInRange(Coord pos);

private:
    std::array<int, 2> rangeX, rangeY;
};
}

#endif // RESTRICTION_H
