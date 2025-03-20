#ifndef ORGANISM_H
#define ORGANISM_H
#include <array>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <random>

#include "Grid.h"
#include "Coord.h"
#include "RandomInt.h"

namespace IB{
// Create an enum of possible directions
enum DIR{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Organism
{
public:

    Coord position{3,3}; // Current position of organism
    std::string genome; //

    // Constructor, takes in an initial position
    Organism(Coord initialPosition);

    // Public Methods

    void SetGenome(int geneSeed, int genomeLength = 5);
    // Function takes in random gene seed, and takes in a set genome length

    void SetGenome(std::string str = ""); // Takes string and turns it into genome
    void Think(Grid* grid); // Process next step indiv will take
    int genomeStep; // Current section of genome indiv is processing

    std::vector<int> GetGenomeComposition(); // Get the amount of each type of genome

private:

    RandomInt rnGen; // random number generator
    void Move(DIR direction, Grid* grid); // Moves organisms with respect to direction that is inputted

};
}

#endif // ORGANISM_H
