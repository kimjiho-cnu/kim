#include <iostream>
#include "array_2d.h"
#include "big_block.h"
#include "tree_block.h"
#include "fold_block.h"
#include "cross_block.h"
#include "color_block.h"

using namespace std;

array_2d *game_board = new array_2d();
big_block *block_fold;
big_block *block_tree;
big_block *block_cross;
big_block *userInput_block;
bool newblockchekcing;

void startgame() {
    game_board->print();
}

bool blockchecking()
{   
    bool check = false;
    srand((unsigned int)time(0));
    int block_shape = rand() % 3 + 1;
    if(block_shape==1 && game_board->can_make(1))   // fold
    {
        block_fold = new fold_block();
        userInput_block = block_fold;
        check = true;
    }
    else if(block_shape==2 && game_board->can_make(2))  // tree
    {
        block_tree = new tree_block();
        userInput_block = block_tree;
        check = true;
    }
    else if(block_shape==3 && game_board->can_make(3))  // cross
    {
        block_cross = new cross_block();
        userInput_block = block_cross;
        check = true;
    }
    return check;
}


void input()
{
    cout << "input : ";
    string userInput;
    userInput = getchar();
    // getchar(cin, userInput);

    if(userInput=="a" && userInput_block->can_left() )
    {
        cout << "main_test1" << endl;
        userInput_block->move_left();
    }
    if(userInput=="d" && userInput_block->can_right() )
    {
        cout << "main_test2" << endl;
        userInput_block->move_right();
    }
    if(userInput=="s")
    {
        cout << "main_test3" << endl;
        if(userInput_block->can_down()) {
            userInput_block->move_down();
            if(!userInput_block->can_down())
            {
                newblockchekcing = true;
            }
        }
    }
    if(userInput == "x")
    {
        if(userInput_block->can_down()) {
            userInput_block->move_down_all();
            newblockchekcing = true;
        }
    }
    // if(userInput =="e")
    // {
    //     userInput_block->rotate();
    // }

    if(newblockchekcing)
    {
        userInput_block->~big_block();
    }
}


void playgame()
{
    while(1)
    {
        if(!blockchecking()) { break; }
        newblockchekcing = false;
        while(1)
        {
            startgame();
            input();
            if(newblockchekcing) { break; }
        }
    }
}

int main()
{
    {
        playgame();
    }
    return 0;
}