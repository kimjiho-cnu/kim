#include "array_2d.h"
#include <iostream>

int array_2d::score = 0;
bool array_2d::game_over = false;
block *array_2d::block_array[Y][X] = {0,};

array_2d::array_2d() // 생성자
{
    array_2d::score = 0;
    for(int y = 0; y < Y; y++)
    {
        for(int x = 0; x < X; x++)
        {
            block_array[y][x] = new block(0);
            block_array[y][x]->set_location(x,y);
        }
    }
}

bool array_2d::can_make(int shape) // 만들수 있나?
{
    bool makeOk = false;

    if(shape==1) // fold ㄴ자 모양이므로 그곳에 컬러가 있는지 확인
    {
        if(block_array[0][2]->get_color() == 0 &&
        block_array[1][2]->get_color() == 0 &&
        block_array[1][1]->get_color() == 0)
        {
            makeOk = true;
        }
    }
    if(shape==2) // tree ㅡ 모양이 초기모양 잡고, 비어있는지 확인 
    {
        if(block_array[0][2]->get_color() == 0 &&
        block_array[1][2]->get_color() == 0 &&
        block_array[2][2]->get_color() == 0)
        {
            makeOk = true;
        }
    }
    if(shape==3) // cross + 모양으로 비어있는지 확인
    {
        if(block_array[0][2]->get_color() == 0 &&
        block_array[1][2]->get_color() == 0 &&
        block_array[2][2]->get_color() == 0 &&
        block_array[1][1]->get_color() == 0 &&
        block_array[1][3]->get_color() == 0)
        {
            makeOk = true;
        }
    }
}

void array_2d::delete_block(vector<block *> v) // 블록제거
{
    for(auto& idx : v)
    {
        delete_block(idx->get_x(), idx->get_y());
    }
}

void array_2d::delete_block(int x, int y) // 블록 제거
{
    block_array[y][x]->~block();
}

void array_2d::insert(vector<block *> v) // 블록 삽입
{
    for(auto& idx : v)
    {
        insert(idx->get_x(), idx->get_y(), idx);
    }
}

void array_2d::insert(int x, int y, block *b) // 블록 제거
{
    block_array[y][x] = b;
}

block* array_2d::get_block(int x, int y) // 좌표 리턴
{
    return block_array[y][x];
}

void array_2d::print() // 게임판 출력
{   
    cout << "---------------------\n";
    for(int y = 0; y < Y; y++)
    {   
        cout << "|  " ;
        for(int x = 0; x < X; x++)
        {
            cout << block_array[y][x]->get_color() << "  ";
        }
        cout << "|\n";
    }
    cout << "---------------------\n";
}

int array_2d::get_score() 
{
    return score;
}

// bool array_2d::can_explosion()
// {

// }

// void array_2d::explosion()
// {                        

// }

int array_2d::get_board_X_Size()
{
    return X;
}

int array_2d::get_board_Y_Size()
{
    return Y;
}

