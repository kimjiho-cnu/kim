#include "cross_block.h"

cross_block::cross_block() // +모양으로 
{
    srand((unsigned int)time(NULL));

    block *block_1 = new block( rand() % 4 + 1 ); // 색은 무작위로
    block *block_2 = new block( rand() % 4 + 1 );
    block *block_3 = new block( rand() % 4 + 1 );
    block *block_4 = new block( rand() % 4 + 1 );
    block *block_5 = new block( rand() % 4 + 1 );

    block_1->set_location(2, 0);    // 초기 위치
    block_2->set_location(2, 1);
    block_3->set_location(2, 2);
    block_4->set_location(1, 1);
    block_5->set_location(3, 1);

    block_1->set_parent((long)&v);  // vector
    block_2->set_parent((long)&v);
    block_3->set_parent((long)&v);
    block_4->set_parent((long)&v);
    block_5->set_parent((long)&v);

    big_block::v.push_back(block_1);    
    big_block::v.push_back(block_2);
    big_block::v.push_back(block_3);
    big_block::v.push_back(block_4);
    big_block::v.push_back(block_5);

    array_2d::insert(big_block::v); 
    this->shape = 3;    
}
