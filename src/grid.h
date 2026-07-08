#pragma once
#include <vector>
#include <raylib.h>
#include "colors.h"
class Grid
{
    public:
        Grid();

        void Draw();
        void initGrid();
        int grid[20][10]; // 假设网格的最大高度为 20，宽度为 10
        int ClearAllRow();//返回完成行数，记录分数
    private:
        int width;
        int height;
        int cellSize;
    
        std::vector<Color> colors;
        bool IsFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row,int numcmp);

};
