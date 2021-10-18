#include "Classic.h"

Classic::Classic(){
}

Classic::~Classic(){
}

void Classic::searchGridClassic(Grid* grid){ //search the grid, checking each individual cell to see what is alive and what isn't
    int count = 0;
    Grid* temp = new Grid();
    temp->copyGrid(grid);
        for(int i = 0; i < grid->getHeight(); ++i){ //rows
            for(int j = 0; j < grid->getWidth(); ++j){ //columns
                //Search each neighbor around (i,j)
                if (i == 0 && j == 0){ //checks if location is top left corner
                    if(temp->isAlive(i, j + 1)){  //checks cell to the right of it
                        count += 1;
                    } 
                    if (temp->isAlive(i + 1, j + 1)){ //checks cell diagonally bottom right to it
                        count += 1;
                    } 
                    if (temp->isAlive(i + 1, j)){ //checks cell under it
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == 0 && j == grid->getWidth() - 1){ //checks if location is top right corner
                    if(temp->isAlive(i + 1, j)){ //checks cell under it
                        count += 1;
                    } 
                    if (temp->isAlive(i + 1, j - 1)){ //checks cell diagonally bottom left of it
                        count += 1;
                    } 
                    if (temp->isAlive(i, j - 1)){ //checks cell to the left of it
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == grid->getHeight() - 1 && j == 0) { //checks if location is a bottom left corner
                    if(temp->isAlive(i - 1, j)){ //checks cell above it
                        count += 1;
                    } 
                    if (temp->isAlive(i - 1, j + 1)){ //checks cell diagonally up right 
                        count += 1;
                    } 
                    if (temp->isAlive(i, j + 1)){ //checks cell to the right
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == grid->getHeight() - 1 && j == grid->getWidth() - 1){ //checks if location is bottom right corner
                    if(temp->isAlive(i - 1, j)){ //checks cell above it
                        count += 1;
                    } 
                    if (temp->isAlive(i - 1, j - 1)){ //checks cell diagonally up left 
                        count += 1;
                    } 
                    if (temp->isAlive(i, j - 1)){ //checks cell to the left of it
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;
                }
                else if ((i == 0) && (j != 0 || j != grid->getWidth() - 1)){ //checks if current location is on the top edge of grid
                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j-1)){ //checks cell diagonally down left 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ // checks cell under 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j+1)){ //checks cell diagonally down right
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (i == grid->getHeight() - 1 && (j != 0 || j != grid->getWidth() - 1)) { // checks if current location is on bottom edge of grid
                    if(temp->isAlive(i-1, j-1)){ //checks cell diagonally up left
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j)){ //checks cell above 
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j+1)){ //cehcks cell diagonally up right
                        count += 1;
                    }
                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }


                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if (j == 0 && (i != 0 || i != grid->getHeight() - 1)){ //checks if current location is on left edge of grid
                    if(temp->isAlive(i-1, j)){ //checks cell above 
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j+1)){ //checks cell diagonally up right 
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ //checks cell under
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j+1)){ //checks cell diagonally down right
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;
                } else if (j == grid->getWidth() - 1 && (i != 0 || i != grid->getHeight() - 1)){ //checks if current location is on right edge of grid
                    if(temp->isAlive(i-1, j-1)){ //checks cell diagonally up left
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j)){ //checks cell above 
                        count += 1;
                    }
                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j-1)){ //checks cell diagonally down left 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ // checks cell under 
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                } else if ((i > 0) && (j > 0) && (i < grid->getHeight() - 1) && (j < grid->getWidth() - 1)) { //checks if not in corner and not on edge
                    if(temp->isAlive(i-1, j-1)){ //checks cell diagonally up left
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j)){ //checks cell above 
                        count += 1;
                    }
                    if(temp->isAlive(i-1, j+1)){ //cehcks cell diagonally up right
                        count += 1;
                    }
                    if(temp->isAlive(i, j-1)){ //checks cell to the left
                        count += 1;
                    }
                    if(temp->isAlive(i, j+1)){ //checks cell to the right
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j-1)){ //checks cell diagonally down left 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j)){ // checks cell under 
                        count += 1;
                    }
                    if(temp->isAlive(i+1, j+1)){ //checks cell diagonally down right
                        count += 1;
                    }

                    if(count <= 1){
                        grid->dead(i, j);
                    } else if (count == 3){
                        grid->alive(i, j);
                    } else if (count >= 4){
                        grid->dead(i, j);
                    }
                    
                    count = 0;

                }
            }
        }

    delete temp;
}

