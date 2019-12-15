#ifndef COLORBLOCK_H
#define COLORBLOCK_H

#include <vector>
#include <set>
#include "block.h"

using namespace std;
class block;
class color_block {
private:
    static set<block *> s;
public:
    color_block(block *b);
    static void insert(vector<block *> v);
    set<block *> get_set();
    int get_set_size();
    void explosion();
};

#endif