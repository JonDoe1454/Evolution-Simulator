#include "Restriction.h"

namespace IB{
Restriction::Restriction(int MinX, int MaxX, int MinY, int MaxY){
    rangeX[0] = MinX;
    rangeX[1] = MaxX;
    rangeY[0] = MinY;
    rangeY[1] = MaxY;
}

bool Restriction::PosInRange(Coord pos){
    bool InX = (pos.x >= rangeX[0] && pos.x <= rangeX[1]);
    bool InY = (pos.y >= rangeY[0] && pos.y <= rangeY[1]);
    return (InX && InY);
}
}
