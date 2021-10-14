#include "Simulation.h"

Simulation::Simulation(){
    Grid *test = new Grid(); //this will be classic, doughnut, or mirror, but will have access to everything that grid can access
    /*the reason there is one here and one in runSimulation() is because I plan on creating a virtual method that will run in 
    the Classic, Donut, or Mirror classes, but those don't exist right now :(

    */
}

Simulation::~Simulation(){

}

void Simulation::runSimulation(){
    Grid *test = new Grid(); //this will be classic, doughnut, or mirror, but will have access to everything that grid can access

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
        test->manuallyCreateGrid(); //manually input information
    }
    else{
        cout << "Input the correct number, dumbass";
    }
    

    delete test;
}