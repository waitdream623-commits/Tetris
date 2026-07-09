#include <raylib.h>
#include <cstdio>
#include "game.h"
int main() 
{
    InitWindow(500, 600, "Tetris");
    SetTargetFPS(60);
   game game; // 创建游戏对象
   Font font = LoadFontEx("font/monofram.ttf",64,0,0);
    while (!WindowShouldClose())
    { 
        game.UpdateMusic();
        BeginDrawing();
        
        ClearBackground(DARKGRAY);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameover)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

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