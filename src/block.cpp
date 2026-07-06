#include "block.h"

Block::Block()
{
    this->rotationState = 0;
    this->cellSize = 30; // 设置方块单元格的大小为 30 像素
    this->colors = GetCellColors(); // 获取颜色列表
}
void Block::Draw()
{
    // 绘制方块的逻辑
    // 可以根据当前旋转状态和方块形状来绘制方块
    // 例如，使用 DrawRectangle 或其他绘图函数来绘制每个单元格
    std::vector<Position> currentShape = cells[rotationState];
    for (const Position& pos : currentShape)
    {
        int x = pos.column * cellSize;
        int y = pos.row * cellSize;
        DrawRectangle(x+1, y+1, cellSize-1, cellSize-1, colors[id]);
    }


}