/* 
Derek Norman, Michael Woodward
2364922, 
norman@chapman.edu, 
CPSC-350-03, 
Assignment 3
*/

#ifndef MIRROR_H
#define MIRROR_H

#include "Grid.h"
#include <iostream>
#include <exception>

using namespace std;

class Mirror {                       
    public:
        Mirror();
        ~Mirror();
        void searchGridMirror(Grid* grid); //searches grid and looks for alive locations

};

#endif