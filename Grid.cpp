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

void Grid::createGrid(int width, int height, double populationDensity){
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Population Density: " << populationDensity << endl;
    this->grid = new char*[height];
    for(int i = 0; i < height; ++i){
        grid[i] = new char[width];
    }

    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            cout << "[" << grid[i][j] << "], ";
        }
        cout << endl;
    }

    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            if(((rand() % 10 + 1) * 0.1) <= populationDensity){
                grid[i][j] = 'x';
            } else {
                grid[i][j] = '-';
            }
        }
    }

    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            cout << "[" << grid[i][j] << "], ";
        }
        cout << endl;
    }

}

void Grid::randomGrid(){
    srand(time(NULL));
    width = rand() % 10 + 1; // random width
    height = rand() % 10 + 1; // random height
    populationDensity = (rand() % 10 + 0) * 0.1; //random population Density
    createGrid(width, height, populationDensity);
}

void Grid::manuallyCreateGrid(int width, int height, double populationDensity){ //method to manually input data (is this useful?)
    cout << "Input Width: " << endl;
    cin >> width;
    cout << "Input Height: " << endl;
    cin >> height;
    cout << "Input Population Density: " << endl;
    cin >> populationDensity;
    createGrid(width, height, populationDensity);
}

void Grid::printArray(){

}
