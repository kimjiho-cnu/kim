#include "big_block.h"

big_block::~big_block() // 소멸자
{
    
}

bool big_block::can_left() // 왼쪽 체크
{
    bool check = true;
    for(auto& idx : this->v)
    {
        if(!idx->can_left()) { check = false; }
    }
    return check;
}

bool big_block::can_right() // 오른쪽 체크
{
    bool check = true;
    for(auto& idx : this->v)
    {
        if(!idx->can_right()) { check = false; }
    }
    return check;
}

bool big_block::can_down() // 아래 체크
{
    bool check = true;
    for(auto& idx : this->v)
    {
        if(!idx->can_down()) { check = false; }
    }
    return check;
}

void big_block::move_left() // 왼쪽 이동
{
    vector<block *> newVec;

        for(auto& idx : this->v)
        {
            block *newBlock = new block(idx->get_color());
            newBlock->set_parent(idx->get_parent());
            newBlock->set_location(idx->get_x()-1, idx->get_y());
            newVec.push_back(newBlock);
        }
        for(auto& idx : this->v)
        {
            array_2d::delete_block(idx->get_x(), idx->get_y());
        }
        this->v.clear();
        this->v = newVec;
        array_2d::insert(this->v);
}

void big_block::move_right() // 오른쪽 이동
{
    vector<block *> parent;
    if(can_right())
    {
        vector<block *> newVec;

        for(auto& idx : this->v)
        {
            block *newBlock = new block(idx->get_color());
            newBlock->set_parent(idx->get_parent());
            newBlock->set_location(idx->get_x()+1, idx->get_y());
            newVec.push_back(newBlock);
        }
        for(auto& idx : this->v)
        {
            array_2d::delete_block(idx->get_x(), idx->get_y());
        }
        this->v.clear();
        this->v = newVec;
        array_2d::insert(this->v);
    }
}

void big_block::move_down() // 아래로 이동
{
    if(can_down())
    {
        vector<block *> newVec;

        for(auto& idx : this->v)
        {
            block *newBlock = new block(idx->get_color());
            newBlock->set_parent(idx->get_parent());
            newBlock->set_location(idx->get_x(), idx->get_y()+1);
            newVec.push_back(newBlock);
        }
        for(auto& idx : this->v)
        {
            array_2d::delete_block(idx->get_x(), idx->get_y());
        }
        this->v.clear();
        this->v = newVec;
        array_2d::insert(this->v);
    }
}

void big_block::move_down_all() 
{
 if(can_down()){
     move_down();
     move_down_all(); // 재귀 호출
 }   
}