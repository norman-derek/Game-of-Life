#include "Grid.h"

Grid::Grid(){ //Constructor
    width = -1;
    height = -1;
    populationDensity = -1.0;
}

Grid::~Grid(){ //Destructor

}

void Grid::createGrid(int width, int height, double populationDensity){
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Population Density: " << populationDensity << endl;
    cout << "Ok to place cell: " << placeCell(populationDensity) << endl; //1 means true, 0 means false.
}
=======
>>>>>>> Stashed changes

void Grid::randomGrid(int width, int height, double populationDensity){
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

bool Grid::placeCell(double populationDensity){
    srand(time(NULL));
    return ((rand() % 10 + 1) * 0.1 <= populationDensity);
}