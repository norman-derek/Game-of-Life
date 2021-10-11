#include "Grid.h"

Grid::Grid(){

    srand(time(NULL));
    width = rand() % 10 + 1; // random width
    height = rand() % 10 + 1; // random height
    populationDensity = (rand() % 10 + 0) * 0.1; //random population Density
    createGrid(width, height, populationDensity);
}

void Grid::createGrid(int width, int height, double populationDensity){
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Population Density: " << populationDensity << endl;
    cout << "Ok to place cell: " << placeCell(populationDensity) << endl; //1 means true, 0 means false.
    // vector<vector<char>> grid (height, vector<int> (width));
    // for(int i = 0; i < height; ++i){
    //     for(int j = 0; j < width; ++j){
    //         if(placeCell(populationDensity)){
    //             grid[i][j] = 'x';
    //         }
    //     }
    // }

}

bool Grid::placeCell(double populationDensity){
    srand(time(NULL));
    return ((rand() % 10 + 1) * 0.1 <= populationDensity);
}