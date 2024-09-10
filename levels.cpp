#include "levels.h"
Levels::Levels() {
    // first level 

    std::vector<Brick> bricks = BuildSquare(5,20,0,0,45,20,1);
    levels[0] = bricks;
    
    bricks.clear();// to clear bricks for reuse
    // level 2 
    bricks = BuildSquare(3, 20, 0, 0, 45, 20, 4);//build block of bricks
    std::vector<Brick> bricks2= BuildSquare(5, 3, 0, 75, 45, 20, 4);// new vector to mix shapes 
    bricks.insert(end(bricks), begin(bricks2), end(bricks2));// inserts elements of bricks2 at the end of bricks
    bricks2.clear();// to clear bricks for reuse

    bricks2 = BuildSquare(5, 3, 850, 75, 45, 20, 4);//build block of bricks
    bricks.insert(end(bricks), begin(bricks2), end(bricks2));// inserts elements of bricks2 at the end of bricks
    bricks2.clear();

    levels[1] = bricks;
    
    bricks.clear();// to clear bricks for reuse
    //level 3 

    bricks = BuildSquare(15, 3, 0, 0, 45, 20,5);//build block of bricks

    bricks2 = BuildSquare(15, 3, 300, 0, 45, 20, 5);//build block of bricks
    bricks.insert(end(bricks), begin(bricks2), end(bricks2));// inserts elements of bricks2 at the end of bricks
    bricks2.clear();// to clear bricks for reuse

    bricks2 = BuildSquare(15, 3, 600, 0, 45, 20, 5);//build block of bricks
    bricks.insert(end(bricks), begin(bricks2), end(bricks2));// inserts elements of bricks2 at the end of bricks
    bricks2.clear();// to clear bricks 

    levels[2] = bricks;

    bricks.clear();// to clear bricks 
}

bool Levels::CheckLevel(int i)// function checks every brick in level i, returns true only if all bricks are destroyed
{
    for (Brick item : levels[i]) {
        if (!item.destroyed) return false;
    }
    return true;
}

std::vector<Brick> Levels::GetLevels(int level)// returns level at index level from levels
{
    return levels[level];
}

std::vector<Brick> Levels::BuildSquare(int numRows, int numCols, int startx, int starty, int brickWidth, int brickHeight,int hp)// helper function to create square of bricks from parametars
{// returns vector of bricks in position 
    std::vector<Brick> bricks;
    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5)+ startx;
        int posY = (a / numCols) * (brickHeight + 5)+starty;
        Brick br = Brick(posX, posY, brickWidth, brickHeight, hp);
        bricks.emplace_back(br);
    }
    return bricks;
}


