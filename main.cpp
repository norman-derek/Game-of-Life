#include "Grid.h"

int main(int argc, char** argv)
{
    Grid *test = new Grid();

    int input;
    int width;
    int height;
    double populationDensity;


    cout << "Create Random Grid: Input '1'. Manually Create Grid: Input '2'" << endl;
    cin >> input; //user inputs a number


    if (input == 1){
        test->randomGrid(width, height, populationDensity); //create a random grid
    }
    else if(input == 2){
        test->manuallyCreateGrid(width, height, populationDensity); //manually input information
    }
    else{
        cout << "Input the correct number, dumbass";
    }
    

    delete test;
    return 0;
}
