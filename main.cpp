#include "Classic.h"

int main(int argc, char** argv)
{
    Classic *test = new Classic();
    int input;
    int generation = 0;
    Grid* grid = new Grid();
    Grid* next = new Grid();
    Grid* prev = new Grid();



    cout << "Create Random Grid: Input '1'. Manually Create Grid: Input '2'" << endl;
    cin >> input; //user inputs a number


    if (input == 1){
        grid->randomGrid(); //manually input information
        cout << "GENERATION " << generation << endl;
        grid->printArray();

        while(generation < 5){
        test->searchGrid(grid);
        cout << "GENERATION " << (generation + 1) << endl;
        grid->printArray();
        generation += 1;

        }
        
    }
    else if(input == 2){
        grid->manuallyCreateGrid(); //manually input information
        next->copyGrid(grid);
        cout << "GENERATION 0" << endl;
        grid->printArray();

        test->searchGrid(next);
        cout << "GENERATION 1" << endl;
        next->printArray();
        
    }
    else{
        cout << "Input the correct number, dumbass";
    }

    delete test;
    return 0;
}
