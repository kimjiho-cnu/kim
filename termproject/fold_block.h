#ifndef FOLDBLOCK_H
#define FOLDBLOCK_H

#include "block.h"
#include "array_2d.h"
#include "big_block.h"
#include "color_block.h"

using namespace std;

class fold_block : public big_block {
public:
    fold_block();
    void rotate();
};

#endif