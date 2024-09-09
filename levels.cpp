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
    levels.emplace_back(bricks);
    
    bricks.clear();// to clear bricks for reuse

    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5);
        int posY = (a / numCols) * (brickHeight + 5);
        Brick br = Brick(posX, posY, brickWidth, brickHeight, 4);
        bricks.emplace_back(br);
    }
    levels.emplace_back(bricks);

    bricks.clear();// to clear bricks for reuse

    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5);
        int posY = (a / numCols) * (brickHeight + 5);
        Brick br = Brick(posX, posY, brickWidth, brickHeight, 5);
        bricks.emplace_back(br);
    }
    levels.emplace_back(bricks);
}