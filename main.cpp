#include "Classic.h"
#include "Doughnut.h"
#include "Mirror.h"

int main(int argc, char** argv)
{
    Classic *c = new Classic();
    Doughnut *d = new Doughnut();
    Mirror *m = new Mirror();
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
            curr->printArray();
            cout << "GENERATION 2" << endl;
            c->searchGridClassic(curr);
            curr->printArray();

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                c->searchGridClassic(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }

        } else if (mode == 2){
            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            prev->printArray();
            cout << "GENERATION 1" << endl;
            curr->printArray();
            cout << "GENERATION 2" << endl;
            d->searchGridDoughnut(curr);
            curr->printArray();

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                d->searchGridDoughnut(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }

        } else if (mode == 3){
            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            prev->printArray();
            cout << "GENERATION 1" << endl;
            curr->printArray();
            cout << "GENERATION 2" << endl;
            m->searchGridMirror(curr);
            curr->printArray();

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                m->searchGridMirror(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }

        }else {
            cout << "INVALID CHOICE" << endl;
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
            curr->printArray();
            cout << "GENERATION 2" << endl;
            c->searchGridClassic(curr);
            curr->printArray();

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                c->searchGridClassic(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }

        } else if (mode == 2){
            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            prev->printArray();
            cout << "GENERATION 1" << endl;
            curr->printArray();
            cout << "GENERATION 2" << endl;
            d->searchGridDoughnut(curr);
            curr->printArray();

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                d->searchGridDoughnut(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }

        } else if (mode == 3){
            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            prev->printArray();
            cout << "GENERATION 1" << endl;
            curr->printArray();
            cout << "GENERATION 2" << endl;
            m->searchGridMirror(curr);
            curr->printArray();

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                m->searchGridMirror(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                generation += 1; //increments generation
            }

        }else {
            cout << "INVALID CHOICE" << endl;
        }
        
    }
    else{
        cout << "Input the correct number, dumbass";
    }

    delete c;
    delete d;
    delete m;
    delete curr;
    delete prev;
    delete grid;
    return 0;
}
