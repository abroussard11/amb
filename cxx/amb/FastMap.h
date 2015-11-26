/**
 * amb/FastMap.h
 */

#ifndef AMB_FASTMAP_H_
#define AMB_FASTMAP_H_

#include <iostream>
#include <vector>

namespace amb {

template <typename Key, typename Value>
class FastMap
{
public:
   void push_back(Key key, Value value)
   {
      _keys.push_back(key);
      _values.push_back(value);
   }

   Value find(Key searchKey)
   {
      Value retVal;
      for (auto i = std::size_t(0); i < _keys.size(); ++i)
      {
         if (_keys.at(i) == searchKey)
         {
            retVal = _values.at(i);
            break;
         }
      }

      return retVal;
   }

   void printString()
   {
      std::cout << "Keys:" << std::endl;
      for (auto& key : _keys)
      {
         std::cout << "   " << key << std::endl;
      }

      std::cout << "Values:" << std::endl;
      for (auto& value : _values)
      {
         std::cout << "   " << value << std::endl;
      }
   }

private:
   std::vector<Key> _keys;
   std::vector<Value> _values;
};

} // End namespace amb

#endif //FASTMAP_H_
