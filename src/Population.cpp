#include "Population.h"

namespace IB{
Population::Population(int initialPopulation, Grid* grid){
    this->grid = grid;
    this->initialPopulation = initialPopulation;
    for(int i = 0; i < initialPopulation; i++){
        srand(i * i *time(NULL));
        Coord validCoord;
        int x;
        int y;
        while(true){
            x = rnGen.GetRandomInt(0, (*grid).x-1);
            y = rnGen.GetRandomInt(0, (*grid).y-1);
            Coord newCoord(x, y);
            if((*grid).PositionIsValid(newCoord)){
                validCoord = newCoord;
                break;
            }
        }
        (*grid).data[x][y] = true;
        Organism* org = new Organism(validCoord);
        (*org).SetGenome(i);
        indivs.push_back(org);

    }
}

void Population::GetParentGenomes(){
    for(auto i : indivs){ // for each indiv...
        if(!res->PosInRange(i->position)) continue; // If they aren't in the surviving zone then move on to the next organism
        survivingIndivs.push_back(&i->genome); // If they are, add their genome into the survivors pile

    }
}

void Population::SetRestriction(Restriction* res){
    this->res = res;
}

void Population::SetMutationRate(int x){
    /*  the variable x represents the amount of indivs within the population
        that can mutate. x will be divided by the population in order to get
        a probability value.
    */
    mutationRate = x;
}

void Population::DrawIndivs(){
    /*  Converts each organism's "position" variable into coordinates on the
        window.
    */
    for(auto j : indivs){
        Organism i = (*j);
        int PixelsPerXPosition = ((*grid).lengthOfCellX);
        int PixelsPerYPosition = ((*grid).lengthOfCellY);
        DrawCircle((PixelsPerXPosition * i.position.x) - (PixelsPerXPosition/2), (PixelsPerYPosition * i.position.y)-(PixelsPerXPosition/2), (*grid).lengthOfCellX/2, GREEN);
    }
}

void Population::Action(){
    /*  Gets each organism to do their respective action according to their
        genome.
    */
    for(auto i : indivs){
        (*i).Think(grid);
    }

    steps += 1;
}

/**
    Go threw each surviving member of the last generation and replicate its genome.
    This process is repeated until the new generation reach the initial population value.
*/
void Population::CreateChildren(){
    indivs.clear(); //Clear the list of individuals from the last generation
    int j = 0;
    for(int i = 0; i < this->initialPopulation; i++){
        srand(i * i *time(NULL)); // Changes the pseudo-random seed

        //Get valid position in the environment
        Coord validCoord;
        int x;
        int y;
        while(true){
            x = rnGen.GetRandomInt(0, (*grid).x-1);
            y = rnGen.GetRandomInt(0, (*grid).y-1);
            Coord newCoord(x, y);
            if(grid->PositionIsValid(newCoord)){
                validCoord = newCoord;
                break;
            }
        }
        grid->data[x][y] = true;
        Organism* org = new Organism(validCoord);
        //Creates organism using the found position
        if(survivingIndivs.size() == 0){
            org->SetGenome(i);
        } else {
            org->SetGenome(Mutate(*survivingIndivs[j]));
            if(j < survivingIndivs.size()-1){
                j++;
            } else {
                j = 0;
            }
        }


        // push new organism into generation pool
        indivs.push_back(org);
    }

    // clear list of survivors
    survivingIndivs.clear();
}

Organism Population::GetIndivAt(int it){
    return *indivs[it];
}

std::string Population::Mutate(std::string genome){
    int chance = rnGen.GetRandomInt(0, initialPopulation); // Get a number between 0 to the # of organisms
    std::string possibleGenome = genome;
    if(chance <= mutationRate){ // if chance is less than the mutation rate...
        // Mutation -> Replace one digit of a genome sequence with a random digit
        return possibleGenome.replace(rnGen.GetRandomInt(0, genome.size()-1), 1, std::to_string(rnGen.GetRandomInt(0, 3)));
    } else {
        // Nothing -> return the genome as it was
        return possibleGenome;
    }
}
}
