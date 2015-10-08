//
//  TypeMap.h
//  libim360
//
//  Created by Ben Siroshton on 10/3/13.
//  Copyright (c) 2013 Immersive Ventures. All rights reserved.
//

#ifndef libim360_TypeMap_h
#define libim360_TypeMap_h

#include "im360/core/i3dObject.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <map>
namespace im360 {
    namespace util {

        template <typename T1, typename T2> class TypeMap
        {
        private:
            typedef typename std::map<T1, T2> KeyMap;
            typedef typename std::map<T1, T2>::iterator KeyIterator;
            typedef typename std::map<T2, T1> ValueMap;
            typedef typename std::map<T2, T1>::iterator ValueIterator;

            KeyMap      _keys;
            ValueMap    _values;

        public:
            TypeMap()
            {

            }

            virtual ~TypeMap()
            {
                clear();
            }

            void add(T1 key, T2 value)
            {
                _keys[key] = value;
                _values[value] = key;
            }

            bool findValueByKey(T1 key, T2 & value)
            {
                KeyIterator it = _keys.find(key);
                if( it==_keys.end() ) return false;

                value = it->second;
                return true;
            }

            bool findKeyByValue(T2 value, T1 & key)
            {
                ValueIterator it = _values.find(value);
                if( it==_values.end() ) return false;

                key = it->second;
                return true;
            }

            void removeByKey(T1 key)
            {
                KeyIterator it = _keys.find(key);
                if( it!=_keys.end() )
                {
                    _values.erase( it->second );
                    _keys.erase( it );
                }
            }

            void removeByValue(T2 value)
            {
                ValueIterator it = _values.find(value);
                if( it!=_values.end() )
                {
                    _keys.erase( it->second );
                    _values.erase( it );
                }
            }

            void clear()
            {
                _keys.clear();
                _values.clear();
            }

        };
        
    }}
#endif
#endif

