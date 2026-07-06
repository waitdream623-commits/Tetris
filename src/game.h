#pragma once
#include "block.h"
#include "grid.h"  
#include "blocks.cpp" // 包含所有方块类的实现文件
#include <vector>
class game
{
    public:
        game();
        std::vector<Block> getAllBlocks(); // 获取所有方块的指针
        Block GetRandomBlock(); // 获取随机方块
        void Draw();
    private:
        Grid grid;
        std::vector<Block> blocks; // 存储所有方块
        Block currentBlock; // 当前方块
        Block nextBlock; // 下一个方块
};