#include "Organism.h"


namespace IB{
Organism::Organism(Coord initialPosition){
    position = initialPosition;
    genomeStep = 0;
}

void Organism::SetGenome(int geneSeed, int genomeLength){
    for(int i = 0; i < genomeLength; i++){
        std::string gene = std::to_string(rnGen.GetRandomInt(0,3));
        genome += gene;
    }
}

void Organism::SetGenome(std::string str){
    genome = str;
}

void Organism::Think(Grid* grid){

    char currentIter = genome[genomeStep]; // Get current gene

    switch(currentIter){ // If current gene...
    case '0': // ... is zero then...
        {
            Coord cord{position.x, position.y - 1};
            if((*grid).PositionIsValid(cord)){
                Move(UP, grid); // ... move north.
            }
            break;
        }
    case '1': // ... is one then...
        {
            Coord cord{position.x - 1, position.y};
            if((*grid).PositionIsValid(cord)){
                Move(RIGHT, grid); // ... move east.
            }
            break;
        }
        break;
    case '2': // ... is two, then...
        {
            Coord cord{position.x, position.y + 1};
            if((*grid).PositionIsValid(cord)){
                Move(DOWN, grid); // ... move south.
            }
            break;
        }
        break;
    case '3': // ... is three, then...
        {
            Coord cord{position.x + 1, position.y};
            if((*grid).PositionIsValid(cord)){
                Move(LEFT, grid); // ... move west.
            }
            break;
        }
        break;
    default:
        break;
    }


    if(genomeStep == genome.size() - 1){
        genomeStep = 0;
    } else {
        genomeStep += 1;
    }
}

void Organism::Move(DIR direction, Grid* grid){
    (*grid).data[position.x][position.y] = false;
    switch(direction){
    case UP:
        position.y -= 1;
        break;
    case DOWN:
        position.y += 1;
        break;
    case LEFT:
        position.x += 1;
        break;
    case RIGHT:
        position.x -= 1;
        break;
    }
    (*grid).data[position.x][position.y] = true;
}

std::vector<int> Organism::GetGenomeComposition(){
    std::vector<int> composition = {0, 0, 0, 0};

    for(auto cha : genome){
        composition[((int)cha - 48)] += 1;
    }

    return composition;
}
}
