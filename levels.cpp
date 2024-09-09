#include "levels.h"
Levels::Levels() {
    // first level 

    std::vector<Brick> bricks = BuildSquare(5,20,0,0,45,20,3);
    levels[0] = bricks;
    clears[0] = false;
    bricks.clear();// to clear bricks for reuse

    bricks = BuildSquare(3, 20, 0, 0, 45, 20, 4);
    std::vector<Brick> bricks2= BuildSquare(5, 3, 0, 75, 45, 20, 4);
    bricks.insert(end(bricks), begin(bricks2), end(bricks2));
    bricks2.clear();
    bricks2 = BuildSquare(5, 3, 850, 75, 45, 20, 4);
    bricks.insert(end(bricks), begin(bricks2), end(bricks2));
    bricks2.clear();
    levels[1] = bricks;
    clears[1] = false;
    bricks.clear();// to clear bricks for reuse

    bricks = BuildSquare(15, 3, 0, 0, 45, 20,5);
    bricks2 = BuildSquare(15, 3, 300, 0, 45, 20, 5);
    bricks.insert(end(bricks), begin(bricks2), end(bricks2));
    bricks2 = BuildSquare(15, 3, 600, 0, 45, 20, 5);
    bricks.insert(end(bricks), begin(bricks2), end(bricks2));
    levels[2] = bricks;
    clears[2] = false;
    bricks.clear();// to clear bricks for reuse
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

std::vector<Brick> Levels::BuildSquare(int numRows, int numCols, int startx, int starty, int brickWidth, int brickHeight,int hp)
{
    std::vector<Brick> bricks;
    for (int a = 0; a < numRows * numCols; a++) {
        int posX = (a % numCols) * (brickWidth + 5)+ startx;
        int posY = (a / numCols) * (brickHeight + 5)+starty;
        Brick br = Brick(posX, posY, brickWidth, brickHeight, hp);
        bricks.emplace_back(br);
    }
    return bricks;
}
