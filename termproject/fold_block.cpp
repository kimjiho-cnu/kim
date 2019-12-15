#include "fold_block.h"

fold_block::fold_block() // ㄴ 반대 모양
{
    srand((unsigned int)time(NULL));

    block *block_1 = new block( rand() % 4 + 1 );   // 색은 랜덤
    block *block_2 = new block( rand() % 4 + 1 );
    block *block_3 = new block( rand() % 4 + 1 );

    block_1->set_location(2, 0);    // 초기 위치
    block_2->set_location(2, 1);
    block_3->set_location(1, 1);

    block_1->set_parent((long)&v);  // vector
    block_2->set_parent((long)&v);
    block_3->set_parent((long)&v);

    big_block::v.push_back(block_1);    
    big_block::v.push_back(block_2);
    big_block::v.push_back(block_3);

    array_2d::insert(big_block::v);
    this->shape = 1;
}
