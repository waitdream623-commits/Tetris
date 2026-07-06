#include "game.h"
#include <random>
game::game()
{
    // 初始化网格
    grid=Grid();//自动初始化网格
    blocks = getAllBlocks(); // 获取所有方块的指针
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
std::vector<Block> game::getAllBlocks()
{
    std::vector<Block> blocks;
    blocks.push_back(LBlock());
    blocks.push_back(JBlock());
    blocks.push_back(IBlock());
    blocks.push_back(OBlock());
    blocks.push_back(SBlock());
    blocks.push_back(TBlock());
    blocks.push_back(ZBlock());
    return blocks;
}
Block game::GetRandomBlock()//保证一轮每个方块都出现
{
    if(blocks.empty())
    {
        blocks = getAllBlocks(); // 如果 blocks 为空，则重新获取所有方块
    }
    int randomIndex = rand() % blocks.size();
    Block randomBlock = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex); // 从 blocks 中移除已选中的方块
    return randomBlock;
}
void game::Draw()
{
    grid.Draw(); // 绘制网格
    currentBlock.Draw(); // 绘制当前方块
}