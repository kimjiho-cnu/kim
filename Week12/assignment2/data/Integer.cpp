#include "Integer.h"

Integer::Integer(int value)
{
   _val = value;
}

int Integer::val()
{
   return _val;
}

void Integer::set_val(const int& value)
{
   _val = value;
}

json_object::_type Integer::type()
{
   return INT;
}

std::string Integer::to_string()
{
   return std::to_string(_val);
}

json_object* Integer::parse(const char * a, int length)
{
   int in = _index;
   while (a[_index] >= '0' && a[_index] <= '9') {
      _index++;
   }
   std::string str = std::string(a);
   return new Integer(std::stoi(str.substr(in, _index - in)));
}
