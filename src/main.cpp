#include <raylib.h>
#include "grid.h"

int main() 
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid;   // 创建 Grid 对象
    grid.grid[0][0] = 1; // 设置网格的第一个单元格为红色
    while (!WindowShouldClose())
    { 
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.Draw();     // 调用成员函数——用 . 操作符
        
        EndDrawing();
    }
    CloseWindow();
}