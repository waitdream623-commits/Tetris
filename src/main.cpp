#include <raylib.h>
#include "game.h"
int main() 
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
   game game; // 创建游戏对象
    while (!WindowShouldClose())
    { 
        BeginDrawing();
        
        ClearBackground(DARKGRAY);
        game.Draw(); // 绘制游戏内容，包括网格和当前方块
        if(game.gameover==false)
        {
            game.handleInput(); // 处理用户输入 
            game.AutoMoveDown();
        }
        if(game.gameover&&GetKeyPressed()!=0)
        {
            
            game.gameover=false;
            game.Reset();
        }
        EndDrawing();
    }
    CloseWindow();
}