#include "Classic.h"
#include "Doughnut.h"

int main(int argc, char** argv)
{
    Classic *test = new Classic();
    Doughnut *dough = new Doughnut();
    int input;
    int generation = 0;
    Grid* grid = new Grid();
    Grid* curr = new Grid();
    Grid* prev = new Grid();



    cout << "Create Random Grid: Input '1'. Manually Create Grid: Input '2'" << endl;
    cin >> input; //user inputs a number


    if (input == 1){
        grid->randomGrid(); //manually input information
        cout << "Choose Mode: Classic '1'. Doughnut '2'. Mirror '3'." << endl;
        int mode;
        cin >> mode;
        if(mode == 1){
            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            prev->printArray();
            cout << "GENERATION 1" << endl;
            test->searchGrid(curr);
            curr->printArray();
            generation += 2;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                test->searchGrid(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }
        }
        else if(mode == 2){
            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            prev->printArray();
            cout << "GENERATION 1" << endl;
            dough->searchGrid(curr);
            curr->printArray();
            generation += 2;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                dough->searchGrid(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }
        }
        
    }
    else if(input == 2){
        grid->manuallyCreateGrid(); //manually input information
        cout << "Choose Mode: Classic '1'. Doughnut '2'. Mirror '3'." << endl;
        int mode;
        cin >> mode;
        if(mode == 1){
            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            prev->printArray();
            cout << "GENERATION 1" << endl;
            test->searchGrid(curr);
            curr->printArray();
            generation += 2;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                test->searchGrid(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }
        }
        else if(mode == 2){
            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            prev->printArray();
            cout << "GENERATION 1" << endl;
            dough->searchGrid(curr);
            curr->printArray();
            generation += 2;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                dough->searchGrid(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }
        }
        
    }
    else{
        cout << "Input the correct number, dumbass";
    }

    delete test;
    delete dough;
    return 0;
}
