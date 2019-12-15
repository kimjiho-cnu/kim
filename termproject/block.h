#ifndef BLOCK_H
#define BLOCK_H

#include "color_block.h"
#include "big_block.h"

class block{
private:
    int x,y;
    int color;
    long parent;
public :
    block(int color);
    ~block();
    int get_x();
    int get_y();
    int get_color();
    long get_parent();
    
    void set_color(int color);
    void set_location(int y, int x);
    void set_parent(long par);

    bool can_left();
    bool can_right();
    bool can_down();

    void move_right();
    void move_left();
    void move_down();
    void move_down_all();

    bool can_merge(block *b);
    bool can_explosion(block *b);
    void merge(block *b);
    void find_merge();
};

#endif