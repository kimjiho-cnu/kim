#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

json_list::json_list()
{
   v = std::vector<json_object*>();
}


json_object* json_list::parse(const char* str, int length)
{
   int& index = json_object::_index;


   json_object* val = NULL;
   json_list* list = new json_list();


   while (index < length)
   {
      switch (str[index]) 
      {
      case '\'':
         ++index;
         val = String::parse(str, length, '\'');
         break;
      case ',':
         if (val != NULL) 
         {
            list->v.push_back(val);
            val = NULL;
         }
         break;
      case '[':
         index++;
         val = json_list::parse(str, length);
         break;
      case ']':
         if (val != NULL)
            list->v.push_back(val);
         return list;
      case '{':
         val = json_dict::parse(str, length);
         break;
      case ' ':
         break;
      default:
         val = Integer::parse(str, length);
         --index;
         break;
      }
      ++index;
   }
   return NULL;
}


json_object* json_list::operator[](int key) const
{
   return v[key];

}
json_object::_type json_list::type()
{
   return json_object::LIST;
}


std::string json_list::to_string(){
   std::string string = "[";
   if (v.size() == 0)
      return "[]";

   for (int i = 0; i < v.size() - 1; i++)
   {
      string += v[i]->to_string() + ", ";
   }

   string += v[v.size() - 1]->to_string() + "]";
   return string;
}
