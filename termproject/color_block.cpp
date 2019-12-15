#include "color_block.h"

using namespace std;

set<block *> color_block::s;
void color_block::insert(vector<block *> v) // 삽입
{
    for (auto& idx : v)
    {
        s.insert(idx);
    }
}
set<block *> color_block::get_set()
{
    return s;
}
int color_block::get_set_size() 
{
    return this->s.size();
}
void color_block::explosion()
{
}