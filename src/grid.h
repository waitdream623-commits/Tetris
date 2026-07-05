#pragma once
#include <vector>
#include <raylib.h>
class Grid
{
    public:
        Grid();

        void Draw();
        void initGrid();
        int grid[20][10]; // 假设网格的最大高度为 20，宽度为 10
    private:
        int width;
        int height;
        int cellSize;
    
        std::vector<Color> colors = {BLACK, GREEN, RED, ORANGE, YELLOW, PURPLE, SKYBLUE, BLUE};
};
