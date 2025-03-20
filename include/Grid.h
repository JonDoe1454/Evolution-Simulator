#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <raylib.h>
#include <cmath>
#include <vector>
#include <string>

#include "Coord.h"

#define GRID std::vector<std::vector<bool>>
#define ROW std::vector<bool>

namespace IB{
class Grid
{
public:

    //Init Methods
    Grid(const int x=0, const int y=0);
    void SetWindowConstants(const int x, const int y);

    // Tool Methods
    void Draw();
    void ResetData();
    bool PositionIsValid(Coord pos);

    int WindowX, WindowY, x, y;
    double lengthOfCellX,lengthOfCellY;

    GRID data;
private:
};
}

#endif // GRID_H
