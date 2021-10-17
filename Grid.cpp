#include "Grid.h"

Grid::Grid(){ //Constructor
    width = -1;
    height = -1;
    populationDensity = -1.0;

}

Grid::~Grid(){ //Destructor
    for(int i = 0; i < height; ++i){
        delete[] grid[i];
    }

    delete[] grid;
}

void Grid::createGrid(int width, int height, double populationDensity){ //method to create the grid
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;
    cout << "Population Density: " << populationDensity << endl;
    this->height = height;
    this->width = width;
    this->grid = new char*[height];
    for(int i = 0; i < height; ++i){
        grid[i] = new char[width];
    }

    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            if(((rand() % 10 + 1) * 0.1) <= populationDensity){
                grid[i][j] = 'X';
            } else {
                grid[i][j] = '-';
            }
        }
    } //populates grid randomly, 'x' = filled spot, '-' = empty spot

} 

void Grid::randomGrid(){
    srand(time(NULL));
    width = rand() % 10 + 1; // random width
    height = rand() % 10 + 1; // random height
    populationDensity = (rand() % 10) * 0.1; //random population Density
    createGrid(width, height, populationDensity);
}

void Grid::manuallyCreateGrid(){ //method to manually input data (is this useful?)


    ifstream inputTextFile; //you're doing great! i'm proud :D
    inputTextFile.open("input.txt", ios::out);
    if (inputTextFile.is_open()){
        string temp;
        getline(inputTextFile, temp); //reads first line and puts it to temp
        this->height = stoi(temp); //converts a string into an integer
        getline(inputTextFile, temp); //reads second line and puts it to temp
        this->width = stoi(temp); //converts a string into an integer

        grid = new char* [height];
        for(int i = 0; i < height; ++i){
            grid[i] = new char[width];
        }


        for(int i = 0; i < height; ++i){
            getline(inputTextFile, temp);
            for(int j = 0; j < width; ++j){
                grid[i][j] = toupper(temp[j]); //fills row with the corresponding column info. Also changes lowercase x to X if needed
            }
        }   
    }
    else{
        //try catch error
    }

    
    inputTextFile.close();
}

char** Grid::getGrid(){ //returns the grid
    return grid;
}

int Grid::getHeight(){ //returns the height of grid
    return height;
}

int Grid::getWidth(){ //returns the width of grid
    return width;
}

void Grid::printArray(){
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            cout << "[" << grid[i][j] << "], ";
        }
        cout << endl;
    } //prints out grid filled with populated spots
}
