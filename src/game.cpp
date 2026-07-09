#include "game.h"
#include <random>
game::game()
{
    // 初始化网格
    grid=Grid();//自动初始化网格
    blocks = getAllBlocks(); // 获取所有方块的指针
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    lasttime=0;
    gameover=false;
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
void game::movedown()//操作和固定需要用到
{
      currentBlock.move(1, 0); // 向下移动
         if(IsBlockOutside()||LockFits()==false)
        {
            currentBlock.move(-1,0);
            LockBlock();
        
        }
}
void game::handleInput()
{
    if (IsKeyPressed(KEY_LEFT))//不能在此处判空，应该判断移动后位置
    {
        currentBlock.move(0, -1); // 向左移动
        if(IsBlockOutside()||LockFits()==false)
        {
            currentBlock.move(0,1);
        }
    }
    else if (IsKeyPressed(KEY_RIGHT))
    {
        currentBlock.move(0, 1); // 向右移动
         if(IsBlockOutside()||LockFits()==false)
        {
            currentBlock.move(0,-1);
        }
    }
    else if (IsKeyPressed(KEY_DOWN))
    {
       movedown();
    }
    else if (IsKeyPressed(KEY_UP))
    {
        currentBlock.rotate();
         if(IsBlockOutside()||LockFits()==false)
        {
            currentBlock.undorotate();
        }

    }
}
bool game::IsBlockOutside()
{
    // 检查当前方块是否超出网格边界
    std::vector<Position> currentShape = currentBlock.GetPositions();
    for (const Position& pos : currentShape)
    {
        int newRow = pos.row;
        int newCol = pos.column;
        if (newRow < 0 || newRow >= 20 || newCol < 0 || newCol >= 10)
        {
            return true; // 超出边界
        }
    }
    return false; // 没有超出边界
}
void game::AutoMoveDown()
{
    if(EventTriggered(0.2))
    {
        movedown();
    }
}
bool game::EventTriggered(double interval)
{
    currenttime=GetTime();
    if(currenttime-lasttime>=interval)
    {
        lasttime=currenttime;
        return true;
    }
    return false;
}

void game::Reset()
{
    grid.initGrid();
    blocks = getAllBlocks(); // 获取所有方块的指针
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

void game::LockBlock()
{
    std::vector<Position>tiles=currentBlock.GetPositions();
    for(auto item: tiles)
    {
        grid.grid[item.row][item.column]=currentBlock.id;
    }
    currentBlock=nextBlock;
    if(LockFits()==false)//新生成方块没有位置放置
    {
        gameover=true;
    }
    nextBlock=GetRandomBlock();
    grid.ClearAllRow();
}
bool game::LockFits()//该区域没有其他颜色
{
       std::vector<Position>tiles=currentBlock.GetPositions();
    for(auto item: tiles)
    {
        if(grid.grid[item.row][item.column]!=0)return false;

    }
    return true;
}