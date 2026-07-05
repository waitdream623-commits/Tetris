#include <raylib.h>
#include "grid.h"

Grid::Grid()//初始化
{
    this->width = 10;
    this->height = 20;
    this->cellSize = 30; // 设置每个单元格的大小为 30 像素
    initGrid(); // 初始化网格
}
void Grid::Draw()
{
    // int ox = (300 - width * cellSize) / 2;
    // int oy = (600 - height * cellSize) / 2;

    // for (int r = 0; r <= height; r++)
    //     DrawLine(ox, oy + r * cellSize, ox + width * cellSize, oy + r * cellSize, DARKGRAY);
    // for (int c = 0; c <= width; c++)
    //     DrawLine(ox + c * cellSize, oy, ox + c * cellSize, oy + height * cellSize, DARKGRAY);
    for(int row = 0; row < height; ++row)
    {
        for(int col = 0; col < width; ++col)
        {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize+1, row * cellSize+1, cellSize - 1, cellSize - 1, colors[cellValue]);
           
        }
    }
}

void Grid::initGrid()//初始化网格
{
    // 初始化网格数据结构，例如创建一个二维数组来表示网格
    // 这里可以根据需要进行具体的实现
    for(int row = 0; row < height; ++row)
    {
        for(int col = 0; col < width; ++col)
        {
            // 初始化每个单元格的状态，例如设置为空
            grid[row][col] = 0;
        }
    }

}

