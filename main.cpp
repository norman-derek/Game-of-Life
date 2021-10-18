#include "Classic.h"

int main(int argc, char** argv)
{
    Classic *test = new Classic();
    int input;
    int generation = 0;
    Grid* grid = new Grid();
    Grid* curr = new Grid();
    Grid* prev = new Grid();



    cout << "Create Random Grid: Input '1'. Manually Create Grid: Input '2'" << endl;
    cin >> input; //user inputs a number


    if (input == 1){
        grid->randomGrid(); //manually input information
        curr->copyGrid(grid);
        cout << "GENERATION 0" << endl;
        prev->copyGrid(grid);
        prev->printArray();
        cout << "GENERATION 1" << endl;
        test->searchGrid(curr);
        curr->printArray();
        generation += 2;

        cout << "is stable? " << curr->isStable(prev) << endl;
        while(!curr->isStable(prev) && !curr->isEmpty()){
            // prev->copyGrid(curr);
            // cout << "===========GENERATION " << generation << "==============" << endl;
            // prev->printArray();
            // test->searchGrid(curr);
            // cout << "===========GENERATION " << (generation + 1) << "==============" << endl;
            // curr->printArray();
            // generation += 2;
            //curr->copyGrid(grid);
            //cout << "GENERATION " << generation << endl;
            prev->copyGrid(curr);
            //prev->printArray();
            cout << "GENERATION " << (generation) << endl;
            test->searchGrid(curr);
            curr->printArray();
            generation += 1;
        }
        
    }
    else if(input == 2){
        grid->manuallyCreateGrid(); //manually input information
        curr->copyGrid(grid);
        cout << "GENERATION 0" << endl;
        prev->copyGrid(grid);
        prev->printArray();
        cout << "GENERATION 1" << endl;
        test->searchGrid(curr);
        curr->printArray();
        generation += 2;

        cout << "is stable? " << curr->isStable(prev) << endl;
        while(!curr->isStable(prev)){
            cout << "===========GENERATION " << generation << "==============" << endl;
            prev->printArray();
            test->searchGrid(grid);
            cout << "===========GENERATION " << (generation + 1) << "==============" << endl;
            curr->copyGrid(grid);
            curr->printArray();
            generation += 2;
        }
        
    }
    else{
        cout << "Input the correct number, dumbass";
    }

    delete test;
    return 0;
}
