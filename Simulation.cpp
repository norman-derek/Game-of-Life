#include "Simulation.h"

Simulation::Simulation(){

}

Simulation::~Simulation(){

}

void Simulation::runSimulation(){
    Grid *test = new Grid();

    int input;
    int width;
    int height;
    double populationDensity;


    cout << "Create Random Grid: Input '1'. Manually Create Grid: Input '2'" << endl;
    cin >> input; //user inputs a number


    if (input == 1){
        test->randomGrid(); //create a random grid
        test->printArray(); //prints array
    }
    else if(input == 2){
        test->manuallyCreateGrid(width, height, populationDensity); //manually input information
    }
    else{
        cout << "Input the correct number, dumbass";
    }
    

    delete test;
}