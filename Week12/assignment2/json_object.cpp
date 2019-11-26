#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0; 


json_object* json_object::parse(const char* str, int length){
   json_object* T = NULL;
   while (_index < length)
   {
      switch (str[_index]) 
      {
      case '{':
         _index++;
         T = json_dict::parse(str, length);
         break;
      case '[':
         _index++;
         T = json_list::parse(str, length);
         break;
      case '\'':
         _index++;
         T = String::parse(str, length, '\'');
         break;
      default:
         if (str[_index] > '0' && str[_index] < '9')
            T = Integer::parse(str, length);
         break;
      }
      _index++;
   }

   _index = 0;
   return T;
}

json_object* json_object::parse(const std::string& str)
  {
	  
     return parse(str.c_str(), str.length());
  }

