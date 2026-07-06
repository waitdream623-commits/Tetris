#include "block.h"
class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1;
        cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        move(0, 3); // 将 LBlock 移动到网格的顶部中央位置
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
       move(0, 3); // 将 JBlock 移动到网格的顶部中央位置
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        move(-1, 3); // 将 IBlock 移动到网格的顶部中央位置
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};// O 形状在所有旋转状态下都是相同的
        move(0, 4); // 将 OBlock 移动到网格的顶部中央位置
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
        cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        move(0, 3); // 将 SBlock 移动到网格的顶部中央位置
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        move(0, 3); // 将 TBlock 移动到网格的顶部中央位置
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        move(0, 3); // 将 ZBlock 移动到网格的顶部中央位置
    }
};