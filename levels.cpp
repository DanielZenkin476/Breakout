#include "levels.h"
Levels::Levels() {
    // first level 
    std::vector<Brick> bricks;
    int numRows = 5;
    int numCols = 20;
    int brickWidth = 45;
    int brickHeight = 20;
    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5);
        int posY = (a / numCols) * (brickHeight + 5);
        Brick br = Brick(posX, posY, brickWidth, brickHeight, 3);
        bricks.emplace_back(br);
    }
    levels[0]  =bricks;
    clears[0]  = false;
    
    bricks.clear();// to clear bricks for reuse
   

    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5);
        int posY = (a / numCols) * (brickHeight + 5);
        Brick br = Brick(posX, posY, brickWidth, brickHeight, 4);
        bricks.emplace_back(br);
    }
    levels[1] = bricks;
    clears[1] = false;

    bricks.clear();// to clear bricks for reuse

    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5);
        int posY = (a / numCols) * (brickHeight + 5);
        Brick br = Brick(posX, posY, brickWidth, brickHeight, 5);
        bricks.emplace_back(br);
    }
    levels[2] = bricks;
    clears[2] = false;
}

bool Levels::CheckLevel(int i)
{
    for (Brick item : levels[i]) {
        if (!item.destroyed) return false;
    }
    return true;
}

std::vector<Brick> Levels::GetLevels(int level)
{
    return levels[level];
}
