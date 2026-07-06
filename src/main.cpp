#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"
int main() 
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    //Lblock block;
    IBlock iblock;
    Grid grid;   // 创建 Grid 对象
    while (!WindowShouldClose())
    { 
        BeginDrawing();
        ClearBackground(DARKGRAY);
        grid.Draw();     // 调用成员函数——用 . 操作符
        iblock.Draw();    // 调用成员函数——用 . 操作符
        EndDrawing();
    }
    CloseWindow();
}