#include "String.h"
#include "Object.h"

String::String(const std::string& str)
{
   _val = str;
}


std::string String::val()
{
   return _val;
}

void String::set_val(const std::string& str)
{
   this->_val = str;
}

json_object::_type String::type()
{
   return STRING;
}

std::string String::to_string()
{
   return '\'' + this->_val + '\'';
}


json_object* String::parse(const char* str, int length, char base)
{	
   int& index = json_object::_index;
   std::string temp = "";
    while (index < length)
   {
    switch (str[index])
      {
      case '\'':
         return new String(temp);
      default:
         temp += str[index];
         break;
      }
      ++index;
   }

   return NULL;
}

