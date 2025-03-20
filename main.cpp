#include <thread>
#include <chrono>
#include <iostream>

#include "raylib.h"
#include "MainSimulator.h"
#include "Grid.h"
#include "Restriction.h"

int generations, stepsPerGeneration, initPopulation, gridDim, mutationRate, sampleSize ; // Basic variables
int resMinX = 0, resMaxX = 9999, resMinY = 0, resMaxY = 9999; // Specific Restriction variables

using namespace IB;

void IntroOptions(){
    std::cout << "============================================" << "\n";
    std::cout << "| Biology Natural Selection Simulator V. 1 |" << "\n";
    std::cout << "============================================" << "\n";

    std::cout << "[ # of generations to simulate? ]>: ";
    std::cin >> generations;
    std::cout << "[ # of turns for each generation? ]>: ";
    std::cin >> stepsPerGeneration;
    std::cout << "[ Grid Dimension (Y) -> Y by Y]>: ";
    std::cin >> gridDim;
    std::cout << "[ # of initial organisms ]>: ";
    std::cin >> initPopulation;
    std::cout << "[ # of sample population ]>: ";
    std::cin >> sampleSize;
    std::cout << "[ Mutation rate (# of indivs that might mutate) ]>: ";
    std::cin >> mutationRate;

    char input;
    std::cout << "[ Change restriction? (y/n) ]>: ";
    std::cin >> input;

    if(input == 'n') return;

    std::cout << "[ minimum X position? ]>: ";
    std::cin >> resMinX;
    std::cout << "[ maximum X position? ]>: ";
    std::cin >> resMaxX;
    std::cout << "[ minimum Y position? ]>: ";
    std::cin >> resMinY;
    std::cout << "[ maximum Y position? ]>: ";
    std::cin >> resMaxY;

    return;

}
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    IntroOptions();
    Restriction* res = new Restriction(resMinX, resMaxX, resMinY, resMaxY);

    const int screenWidth = 1000;
    const int screenHeight = 1000;
    const int constDim = gridDim;
    MainSimulator* simulator = new MainSimulator(generations, stepsPerGeneration, initPopulation, constDim, res, mutationRate, sampleSize);

    InitWindow(screenWidth, screenHeight, "Evolution Simulator");

    SetTargetFPS(120);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    simulator->Start();

    // Main game loop
    while (!WindowShouldClose() && simulator->active)    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        simulator->Update();

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            simulator->Render();

        EndDrawing();
        //----------------------------------------------------------------------------------

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

