#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"


void json_dict::put(json_object* key, json_object* val)
{  
    v.push_back({ key, val });
}

int json_dict::find(json_object* key)
{
   std::string findkey = key->to_string();

   for (int i = 0; i < v.size(); i++)
   {
      if (v[i].first->to_string() == findkey)
         return i;
   }
   return -1;
}

json_dict::json_dict(){}


json_object* json_dict::parse(const char* str, int length)
{  

   int number = 0;
   int& index = json_object::_index;
   json_dict *tmp_dict = new json_dict();
   json_object *key = NULL,*val = NULL;
   bool _isKey = true;

   while (index < length) 
   {
      switch (str[index])
      {
      case '\'':
         index++;
	         if (_isKey)
        	    key = String::parse(str, length, '\''); 
       		  else
          		  val = String::parse(str, length, '\''); 
         break;
	 
      case ':':
         _isKey = false;
         break;

      case ',':
         number = tmp_dict->find(key);
		 
         if (number != -1)
            tmp_dict->v[number].second = val;
         else
            tmp_dict->put(key, val);
         _isKey = true;
         break;

      case '[':
         index++;
         val = json_list::parse(str, length);
         break;

      case '{':
         index++;
         val = json_dict::parse(str, length);
         break;

      case '}':
         number = tmp_dict->find(key);
         if (number != -1)
            tmp_dict->v[number].second = val;
         else
            tmp_dict->put(key, val);
         return tmp_dict;

	  
      case ' ':
         break;


      default:
         if (_isKey)
            key = Integer::parse(str, length);
         else
            val = Integer::parse(str, length);
         --index;
         break;
      }
      index++;
   }

   return tmp_dict;
}


json_object* json_dict::operator[](json_object* key) const
{
   if (key->type() == json_object::INT)
   {
      return operator[](atoi(key->to_string().c_str()));
   }
   else if (key->type() == json_object::STRING)
   {
      return operator[](key->to_string());
   }

   return NULL;
}


json_object* json_dict::operator[](const std::string& key) const
{
   std::string _key = '\'' + key + '\'';
   for (std::pair<json_object*, json_object*> _tmp : v)
   {
      if (_tmp.first->to_string() == _key)
         return _tmp.second;
   }
   return NULL;
}

json_object* json_dict::operator[](int key) const
{
   for (std::pair<json_object*, json_object*> _tmp : v)
   {
      int _key = atoi(_tmp.first->to_string().c_str());
      if (_key == key)
         return _tmp.second;
   }
   return NULL;
}

json_object::_type json_dict::type()
{
   return DICT;
}

std::string json_dict::to_string()
{
   if (v.size() == 0)
      return "{}";

   std::string string = "{";
   for (int i = 0; i < v.size() - 1; i++)
   {
      string += v[i].first->to_string() + ": " + v[i].second->to_string();
      string += ", ";
   }
   string += v[v.size() - 1].first->to_string() + ": " + v[v.size() - 1].second->to_string() + '}';
   return string;
}
