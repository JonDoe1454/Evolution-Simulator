#include "Grid.h"


namespace IB{
Grid::Grid(const int x, const int y){
    this->x = x;
    this->y = y;

    for(int i = 0; i < x+1; i++){
        ROW row;
        for(int j = 0; j < y+1; j++){
            row.push_back(false);
        }
        data.push_back(row);
    }
}

void Grid::SetWindowConstants(int x, int y){
    WindowX = x;
    WindowY = y;

    lengthOfCellX = round((double)WindowX/this->x);
    lengthOfCellY = round((double)WindowY/this->y);
}

void Grid::Draw(){
    for(int i = 0; i < x; i++){
        DrawLine(lengthOfCellX * i, 0, lengthOfCellX * i, WindowY, BLACK);
    }
    for(int j = 0; j < y; j++){
        DrawLine(0, lengthOfCellY * j, WindowX, lengthOfCellY* j, BLACK);
    }
}
void Grid::ResetData(){
    for(int i = 0; i < x+1; i++){
        for(int j = 0; j < y+1; j++){
            data[i][j] = false;
        }
    }
}

bool Grid::PositionIsValid(Coord pos){
    if(pos.x < 1 || pos.x> x){
        return false;
    }
    if(pos.y < 1 || pos.y> y){
        return false;
    }
    return (!data[pos.x][pos.y]);
}
}
