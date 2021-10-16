#include "Classic.h"

int main(int argc, char** argv)
{
    // Simulation *sim = new Simulation();
    // sim->runSimulation();
    Classic *test = new Classic();
    int input;
    int width;
    int height;
    double populationDensity;


    cout << "Create Random Grid: Input '1'. Manually Create Grid: Input '2'" << endl;
    cin >> input; //user inputs a number


    if (input == 1){
        test->randomGrid(); //create a random grid
        test->printArray(); //prints array
        test->searchGrid(); 
        cout << "==========CURRENT GRID===========" << endl;
        test->printArray();
        cout << "=========PREVIOUS GRID===========" << endl;
        test->printPrevGrid();
    }
    else if(input == 2){
        test->manuallyCreateGrid(); //manually input information
        test->printArray();
    }
    else{
        cout << "Input the correct number, dumbass";
    }

    delete test;
    return 0;
}
