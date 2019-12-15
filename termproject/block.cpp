#include "block.h"
#include "array_2d.h"

block::block(int color) // 생성자
{
    this->color = color;
}

block::~block() // 소멸자 color 0
{
    this->color = 0;
    this->parent = NULL;
}

int block::get_color()
{
    return this->color;
}

long block::get_parent() // block vector
{
    return this->parent;
}

int block::get_x()
{
    return this->x;
}

int block::get_y()
{
    return this->y;
}

void block::set_location(int x, int y)
{
    this-> y = y;
    this-> x = x;
}

void block::set_color(int color)
{
    this->color = color;
}

void block::set_parent(long par)
{
    this->parent = par;
}

bool block::can_left()
{
    block *left_block = array_2d::get_block(this->x - 1, this->y);
    if( this-> x-1 < 0 ) { return false; }
    else if( this->parent != left_block->parent && left_block->get_color()!=0 )
    { 
        return false;
    }
    else
    {
        return true;
    }
}

bool block::can_right()
{
    block *right_block = array_2d::get_block(this->x + 1, this->y);
    if( this-> x+1 >= array_2d::get_board_X_Size() ) { return false; }
    else if( this->parent != right_block->parent && right_block->get_color()!=0 )
    { 
        return false;
    }
    else
    {
        return true;
    }
}

bool block::can_down()
{
    block *down_block = array_2d::get_block(this->x, this->y + 1);
    if( this-> y == array_2d::get_board_Y_Size()-1 ) { return false; }
    else if( this->parent != down_block->parent && down_block->get_color()!=0 )
    { 
        return false;
    }
    else
    {
        return true;
    }
}

void block::move_right()
{
    block *right_block = array_2d::get_block(this->x+1, this->y); // 오른쪽 이므로 x+1
    right_block->set_color(this->color);
    right_block->set_parent(this->parent);
    this->color = 0;
    this->parent  = NULL;
}

void block::move_left()
{
    block *left_block = array_2d::get_block(this->x-1, this->y); // 왼쪽이므로 x-1
    left_block->set_color(this->color);
    left_block->set_parent(this->parent);
}

void block::move_down()
{
    block *down_block = array_2d::get_block(this->x, this->y+1); // 아래로 y+1
    down_block->set_color(this->color);
    down_block->set_parent(this->parent);
}

void block::move_down_all()
{
    if(can_down())
    {   
        move_down(); 
        return array_2d::get_block(this->x, this->y+1)->move_down(); // 재귀적으로 호출
    }
    else
    {
        return;
    }
}