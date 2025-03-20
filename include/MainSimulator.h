#ifndef MAINSIMULATOR_H
#define MAINSIMULATOR_H
#include <raylib.h>
#include <ctime>

#include "Population.h"
#include "Grid.h"
#include "Organism.h"
#include "Restriction.h"
#include "RandomInt.h"

#include <stdlib.h>
#include <time.h>

namespace IB{
class MainSimulator
{
public:
    bool active = false;

    MainSimulator(int generations, int turnsPerGenerations, int initPop, const int gridDim, Restriction* res, int mutationRate, int sampleSize);

    void Start();
    void Update();
    void Render();

private:

    int maxGenerations, turnsPerGeneration, sampleSize;
    int generation = 1;

    Grid* env;
    Population* pops;
    RandomInt rnGen;

    void PrintSamples();


};
}

#endif // MAINSIMULATOR_H
