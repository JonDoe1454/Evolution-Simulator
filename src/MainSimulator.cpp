#include "MainSimulator.h"

namespace IB{

MainSimulator::MainSimulator(int generations, int turnsPerGenerations, int initPop, const int gridDim, Restriction* res, int mutationRate, int sampleSize){
    maxGenerations = generations;
    turnsPerGeneration = turnsPerGenerations;

    env = new Grid(gridDim, gridDim);
    pops = new Population(initPop, env);

    pops->SetRestriction(res);
    pops->SetMutationRate(mutationRate);

    this->sampleSize = sampleSize;
    PrintSamples();

    active = true;
}

void MainSimulator::Start(){
    env->SetWindowConstants(1000, 1000);

}
void MainSimulator::Update(){
    pops->Action();
    if(pops->steps == turnsPerGeneration){
        pops->steps = 0;
        env->ResetData();
        pops->GetParentGenomes();

        std::cout << "Generation: " << generation << " | Survivors: " << pops->survivingIndivs.size() << "\n";

        pops->CreateChildren();
        if(generation == maxGenerations){
            PrintSamples();
            active = false;
        }
        generation += 1;
    }
}
void MainSimulator::Render(){
    env->Draw();
    pops->DrawIndivs();
}

void MainSimulator::PrintSamples(){
    std::cout << "<<GENERATION " << generation << " SAMPLES>>"<< "\n";
    std::vector<Organism*> notPickedOrgs;
    std::vector<Organism*> PickedOrgs;
    notPickedOrgs = pops->indivs;
    for(int i = 0; i < sampleSize; i++){
        int randomOrgAtPosition = rnGen.GetRandomInt(0, notPickedOrgs.size() - 1);
        Organism* org = notPickedOrgs[randomOrgAtPosition];
        PickedOrgs.push_back(org);
        notPickedOrgs.erase(notPickedOrgs.begin()+randomOrgAtPosition);
        std::vector<int> composition = org->GetGenomeComposition();
        std::cout << ">> UP: " << composition[0] << " >> LEFT:" << composition[1] << " >> DOWN: " << composition[2] << " >> RIGHT: " << composition[3] << "\n";

    }
}

}
