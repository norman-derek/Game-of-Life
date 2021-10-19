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

/*
* This method is called createGrid and it creates a grid with given width, height, and populationDensity.
* This method has three parameters. Width which is the width of the grid. Height which is hieght of grid. populationDensity which is how filled the grid will be with 'alive' cells.
*/
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

/*
*This method is called randomGrid and it generates random parameters for a grid
*/
void Grid::randomGrid(){
    srand(time(NULL));
    width = (rand() % 10 + 1) + 1; // random width, add 1 to avoid a grid with width of 1
    height = (rand() % 10 + 1) + 1; // random height, add 1 to avoid grid with height of 1
    populationDensity = (rand() % 10 + 1) * 0.1; //random population Density
    createGrid(width, height, populationDensity); //creates grid with the generated paramters
}

/*
* This method is called manuallyCreateGrid, it takes an input txt file which has a grid on it and converts it into a grid object
*/
void Grid::manuallyCreateGrid(){ //method to manually input data (is this useful?)

    cout << "Please provide file path" << endl;
    string filePath;
    cin >> filePath;
    if(filePath.length() < 4) { //checks if file name length is 3 or less which is not possible with .txt extension
        cout << "please use a valid file name with .txt" << endl;
        manuallyCreateGrid(); //recalls function so user can input correct file
    }
    else if(filePath.substr(filePath.length() - 4) != ".txt"){ //check if file has .txt extension
        cout << "please input a .txt file for the input" << endl;

        manuallyCreateGrid();
    }
    
    ifstream inputTextFile; //you're doing great! i'm proud :D
    inputTextFile.open(filePath, ios::out);
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

/*
* This method is called getGrid
* This method returns the grid 
*/
char** Grid::getGrid(){ //returns the grid
    return grid;
}

/*
* This method is called alive and changes a location on a grid to be 'alive'
* This method has two parameters h and w. h is the row, and w is the col.
*/
void Grid::alive(int h, int w){ //set a cell to be alive
    grid[h][w] = 'X';
}

/*
* This method is called dead and changes the cell at the location to 'dead'
* This method has two parameters h and w. h is the row, and w is the col which corresponds with a location on the grid.
*/
void Grid::dead(int h, int w){ //sets a cell to be dead
    grid[h][w] = '-';
}

/*
* This method is called isAlive and returns whether or not a location on the grid is alive or not
* This method has two parameters h and w. h is the row, and w is the col which corresponds with a location on the grid.
* This method returns a bool indicating if a location on the grid is alive or not
*/
bool Grid::isAlive(int h, int w){ //check to see if a cell is alive
    return (grid[h][w] == 'X');
}

/*
* This method is called copyGrid it copys a grid to the current grid
* This method has one parameter called other which is a grid object. 
*/
void Grid::copyGrid(Grid* other){
    this->height = other->getHeight();
    this->width = other->getWidth();
    this->grid = new char*[other->getHeight()];
    for(int i = 0; i < other->getHeight(); ++i){
        grid[i] = new char[other->getWidth()];
    }

    for(int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            if(other->isAlive(i, j)){
                grid[i][j] = 'X';
            } else {
                grid[i][j] = '-';
            }
        }
    }
}

/*
* This method is called isStable and tells whether or not a grid is equal to another grid
* This method takes a single paramter of a Grid* and checks to see if it equal to current grid.
* This method returns a bool indicating if a grid is equal to another grid or not
*/
bool Grid::isStable(Grid* other){
    for (int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if(grid[i][j] != other->grid[i][j]){
                return false;
            }
        }
    }
    

    return true;
}

/*
* This method is called isEmpty and checks if a grid is empty (no alive cells in grid) or not
* This method returns a bool indicating if the grid is empty (has no alive cells)
*/
bool Grid::isEmpty(){    
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if(isAlive(i, j)){
                return false;
            }
        }
    }

    return true; 
}

/*
* This method is called getHeight and returns the hieght of grid
* This method returns an int indicating the hieght of the grid
*/
int Grid::getHeight(){ //returns the height of grid
    return height;
}

/*
* This method is called getWidth
* This method returns an int indicating the width of the grid
*/
int Grid::getWidth(){ //returns the width of grid
    return width;
}

/*
* This method is called loc
* This method takes two parameters h and w. h represents the row, w represents the col.
* This method returns a char indicating the char at a given location
*/
char Grid::loc(int h, int w){ //returns char at given location
    char c;
    c = grid[h][w];
    return c;
}

/*
* this method is called printArray and prints the grid out to a readable form
*/
void Grid::printArray(){
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            cout << "[" << grid[i][j] << "], ";
        }
        cout << endl;
    } //prints out grid filled with populated spots
}
