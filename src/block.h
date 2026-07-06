#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
class Block//父类，
{
    public:
        Block();
        int id;//后续对应每一种方块
        std::map<int, std::vector<Position>> cells; // 存储不同旋转状态下的方块形状，mp[0]表示旋转状态0的方块形状，mp[1]表示旋转状态1的方块形状，依此类推
        void Draw();//绘制方块,外部调用
        void move(int row, int column);//移动方块，外部调用
    private:
        int rotationState; // 当前旋转状态，记录上一个状态
        int cellSize; // 方块单元格的大小
        std::vector<Color> colors; // 当前方块的颜色列表
        int rowoffset; // 方块在网格中的行偏移量
        int columnoffset; // 方块在网格中的列偏移量
};