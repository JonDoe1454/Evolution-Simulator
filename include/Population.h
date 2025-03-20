#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "Organism.h"
#include "Grid.h"
#include "Restriction.h"
#include "RandomInt.h"

namespace IB{
class Population
{
public:
    int steps = 0;

    Population(int initialPopulation, Grid* grid);
    void GetParentGenomes();
    void SetRestriction(Restriction* res);
    void SetMutationRate(int x);
    void DrawIndivs();
    void Action();
    void CreateChildren();
    Organism GetIndivAt(int it);
    std::vector<Organism*> indivs;
    std::vector<std::string*> survivingIndivs;

private:

    int initialPopulation, mutationRate;

    Grid* grid;
    Restriction* res;
    RandomInt rnGen;

    std::string Mutate(std::string genome);
};
}

#endif // POPULATION_H
