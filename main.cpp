/*
1)  
    a) Derek Norman, Michael Woodward
    b) 2364922, 2340070
    c) norman@chapman.edu, mwoodward@chapman.edu
    d) CPSC-350-03, CPSC-350-02
    e) Assignment 3
2)
    Main method
3)
    a) int main
        - run everything!
        - neturns 0
        - takes in main parameters
        - N/A
*/

#include "Classic.h"
#include "Doughnut.h"
#include "Mirror.h"
#include <cstdlib>
#include <unistd.h>


int main(int argc, char** argv)
{
    Classic *c = new Classic();
    Doughnut *d = new Doughnut();
    Mirror *m = new Mirror();
    int input;
    int generation = 0;
    bool briefPause = false;
    bool pressEnter = false;
    bool outputToFile = false;
    ofstream output;
    Grid* grid = new Grid();
    Grid* curr = new Grid();
    Grid* prev = new Grid();



    cout << "Create Random Grid: Input '1'. Manually Create Grid: Input '2' " << endl;
    cin >> input; //user inputs a number

    if(input == 1){
        grid->randomGrid(); //create grid with random information
        cout << "Choose Mode: Classic '1'. Doughnut '2'. Mirror '3'." << endl; //prompts user to choose a mode
        int mode; //holds user input
        cin >> mode; //reads user input

        if (mode == 1){
            cout << "Would you like a breif pause in between generations, press enter key between generations, or ouput to a file? Brief Pause '1'. Enter Key between generations '2'. Output to a File '3'." << endl;
            int pause; //user response
            cin >> pause; //reads user response
            if(pause == 1){ //choice brief pause between generations
                briefPause = true; //sets bool that determines if there is a brief pause to true;
            } else if (pause == 2){ //choice of enter key between generations
                pressEnter = true; //sets bool that determines whether or not to press enter key between generations to true;
            } else if (pause == 3){ //choice to ouput to a file
                outputToFile = true; //sets bool outputToFile to true;
            }else { //invalid choice ends program and makes user rerun it
                cout << "Please input a valid choice!" << endl;
            }

            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output.open("assign3-classic.txt"); //opens file for writing for classic mode
                output << "GENERATION 0" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                cin.ignore();
            }
            cout << "GENERATION 1" << endl;
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 1" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            cout << "GENERATION 2" << endl;
            c->searchGridClassic(curr);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 2" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                if(briefPause){ //brief pause in between generations
                usleep(2000000);
                }
                if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                c->searchGridClassic(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION " << generation << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                        }
                    output << endl;
                    }   
                }
                generation += 1; //increments generation
                
            }

            output.close(); //closes file for writing if opened






        } else if (mode == 2){
            cout << "Would you like a breif pause in between generations, press enter key between generations, or ouput to a file? Brief Pause '1'. Enter Key between generations '2'. Output to a File '3'." << endl;
            int pause; //user response
            cin >> pause; //reads user response
            if(pause == 1){ //choice brief pause between generations
                briefPause = true; //sets bool that determines if there is a brief pause to true;
            } else if (pause == 2){ //choice of enter key between generations
                pressEnter = true; //sets bool that determines whether or not to press enter key between generations to true;
            } else if (pause == 3){ //choice to ouput to a file
                outputToFile = true; //sets bool outputToFile to true;
            }else { //invalid choice ends program and makes user rerun it
                cout << "Please input a valid choice!" << endl;
            }

            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output.open("assign3-doughnut.txt"); //opens file for writing for classic mode
                output << "GENERATION 0" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                cin.ignore();
            }
            cout << "GENERATION 1" << endl;
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 1" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            cout << "GENERATION 2" << endl;
            d->searchGridDoughnut(curr);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 2" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                if(briefPause){ //brief pause in between generations
                usleep(2000000);
                }
                if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                d->searchGridDoughnut(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION " << generation << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                        }
                    output << endl;
                    }   
                }
                generation += 1; //increments generation
                
            }

            output.close(); //closes file for writing if opened



        } else if (mode == 3){
            cout << "Would you like a breif pause in between generations, press enter key between generations, or ouput to a file? Brief Pause '1'. Enter Key between generations '2'. Output to a File '3'." << endl;
            int pause; //user response
            cin >> pause; //reads user response
            if(pause == 1){ //choice brief pause between generations
                briefPause = true; //sets bool that determines if there is a brief pause to true;
            } else if (pause == 2){ //choice of enter key between generations
                pressEnter = true; //sets bool that determines whether or not to press enter key between generations to true;
            } else if (pause == 3){ //choice to ouput to a file
                outputToFile = true; //sets bool outputToFile to true;
            }else { //invalid choice ends program and makes user rerun it
                cout << "Please input a valid choice!" << endl;
            }

            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output.open("assign3-mirror.txt"); //opens file for writing for classic mode
                output << "GENERATION 0" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                cin.ignore();
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                cin.ignore();
            }
            cout << "GENERATION 1" << endl;
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 1" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            cout << "GENERATION 2" << endl;
            m->searchGridMirror(curr);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 2" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                if(briefPause){ //brief pause in between generations
                usleep(2000000);
                }
                if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                m->searchGridMirror(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION " << generation << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                        }
                    output << endl;
                    }   
                }
                generation += 1; //increments generation
                
            }

            output.close(); //closes file for writing if opened



        } else {
            cout << "Please input a valid choice!" << endl;
        }

    } else if (input == 2){
        grid->manuallyCreateGrid(); //manually input information
        cout << "Choose Mode: Classic '1'. Doughnut '2'. Mirror '3'." << endl;
        int mode;
        cin >> mode;

        if (mode == 1){
            cout << "Would you like a breif pause in between generations, press enter key between generations, or ouput to a file? Brief Pause '1'. Enter Key between generations '2'. Output to a File '3'." << endl;
            int pause; //user response
            cin >> pause; //reads user response
            if(pause == 1){ //choice brief pause between generations
                briefPause = true; //sets bool that determines if there is a brief pause to true;
            } else if (pause == 2){ //choice of enter key between generations
                pressEnter = true; //sets bool that determines whether or not to press enter key between generations to true;
            } else if (pause == 3){ //choice to ouput to a file
                outputToFile = true; //sets bool outputToFile to true;
            }else { //invalid choice ends program and makes user rerun it
                cout << "Please input a valid choice!" << endl;
            }

            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output.open("assign3-classic.txt"); //opens file for writing for classic mode
                output << "GENERATION 0" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                cin.ignore();
            }
            cout << "GENERATION 1" << endl;
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 1" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            cout << "GENERATION 2" << endl;
            c->searchGridClassic(curr);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 2" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                if(briefPause){ //brief pause in between generations
                usleep(2000000);
                }
                if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                c->searchGridClassic(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION " << generation << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                        }
                    output << endl;
                    }   
                }
                generation += 1; //increments generation
                
            }

            output.close(); //closes file for writing if opened


        } else if (mode == 2){
            cout << "Would you like a breif pause in between generations, press enter key between generations, or ouput to a file? Brief Pause '1'. Enter Key between generations '2'. Output to a File '3'." << endl;
            int pause; //user response
            cin >> pause; //reads user response
            if(pause == 1){ //choice brief pause between generations
                briefPause = true; //sets bool that determines if there is a brief pause to true;
            } else if (pause == 2){ //choice of enter key between generations
                pressEnter = true; //sets bool that determines whether or not to press enter key between generations to true;
            } else if (pause == 3){ //choice to ouput to a file
                outputToFile = true; //sets bool outputToFile to true;
            }else { //invalid choice ends program and makes user rerun it
                cout << "Please input a valid choice!" << endl;
            }

            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output.open("assign3-doughnut.txt"); //opens file for writing for classic mode
                output << "GENERATION 0" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                cin.ignore();
            }
            cout << "GENERATION 1" << endl;
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 1" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            cout << "GENERATION 2" << endl;
            d->searchGridDoughnut(curr);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 2" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                if(briefPause){ //brief pause in between generations
                usleep(2000000);
                }
                if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                d->searchGridDoughnut(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION " << generation << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                        }
                    output << endl;
                    }   
                }
                generation += 1; //increments generation
                
            }

            output.close(); //closes file for writing if opened


        } else if (mode == 3){
            cout << "Would you like a breif pause in between generations, press enter key between generations, or ouput to a file? Brief Pause '1'. Enter Key between generations '2'. Output to a File '3'." << endl;
            int pause; //user response
            cin >> pause; //reads user response
            if(pause == 1){ //choice brief pause between generations
                briefPause = true; //sets bool that determines if there is a brief pause to true;
            } else if (pause == 2){ //choice of enter key between generations
                pressEnter = true; //sets bool that determines whether or not to press enter key between generations to true;
            } else if (pause == 3){ //choice to ouput to a file
                outputToFile = true; //sets bool outputToFile to true;
            }else { //invalid choice ends program and makes user rerun it
                cout << "Please input a valid choice!" << endl;
            }

            curr->copyGrid(grid);
            cout << "GENERATION 0" << endl;
            prev->copyGrid(grid);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output.open("assign3-mirror.txt"); //opens file for writing for classic mode
                output << "GENERATION 0" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                cin.ignore();
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                cin.ignore();
            }
            cout << "GENERATION 1" << endl;
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 1" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }
            if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
            if(briefPause){ //brief pause in between generations
                usleep(2000000);
            }
            cout << "GENERATION 2" << endl;
            m->searchGridMirror(curr);
            curr->printArray();
            if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION 2" << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                    }
                    output << endl;
                }   
            }

            generation += 3;
        
            while(!curr->isStable(prev) && !curr->isEmpty()){
                if(briefPause){ //brief pause in between generations
                usleep(2000000);
                }
                if(pressEnter){ //if the user wants to press enter for next generation this code executes that
                    cin.ignore();
                }
                prev->copyGrid(curr); //sets previous to curr in order to check isStable in loop
                cout << "GENERATION " << (generation) << endl;
                m->searchGridMirror(curr); //computes next grid from the current grid
                curr->printArray(); //prints the next grid
                if(outputToFile){ //if the user wants to output to a file
                output << "GENERATION " << generation << endl;
                for(int i = 0; i < grid->getHeight(); ++i){
                    for (int j = 0; j < grid->getWidth(); ++j){
                        output << curr->loc(i, j);
                        }
                    output << endl;
                    }   
                }
                generation += 1; //increments generation
                
            }

            output.close(); //closes file for writing if opened


        } else {
            cout << "Please input a valid choice!" << endl;
        }
    } else {
        cout << "Please input a valid choice!" << endl;
    }
    

    cout << "Press ENTER to exit program." << endl;
    cin.ignore();
    cin.ignore();

    delete c;
    delete d;
    delete m;
    delete curr;
    delete prev;
    delete grid;
    return 0;
}
