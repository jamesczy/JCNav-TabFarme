/*
 *  TypeList.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _TypeList_h_
#define _TypeList_h_

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace util {

	template <typename T> class TypeList
	{
	public:
        typedef typename std::list<T> TypeListList;
        typedef typename std::list<T>::iterator ListIterator;
        typedef typename std::list<T>::const_iterator ConstListIterator;

        ListIterator begin()
		{            
			return _list.begin();
		}

        ListIterator end()
		{
			return _list.end();
		}

        ConstListIterator cbegin() const
        {
#if defined(I3d_WINDOWS)
            return _list.cbegin();
#else
            return _list.begin();
#endif
        }

        ConstListIterator cend() const
        {
#if defined(I3d_WINDOWS)
            return _list.cend();
#else
            return _list.end();
#endif
        }
        
        ListIterator erase(ListIterator it)
        {
            onItemRemoved(*it);
            return _list.erase(it);
        }

        void addItem(T item)
		{			
			_list.push_back(item);
			onItemAdded(item);
		}

		void removeItem(T item)
		{
            ListIterator it = find(_list.begin(), _list.end(), item);
            if( it==_list.end() ) return;
            _list.erase(it);
			onItemRemoved(item);
		}

        void removeAllItems()
        {
            ListIterator it = _list.begin();
            while( it!=_list.end() )
            {
                onItemRemoved(*it);
                it = _list.erase(it);
            }
        }

		T getItem(unsigned int index)
		{
			int count=0;
            ListIterator it = _list.begin();
			while(it!=_list.end())
			{
				if( index==count ) return *it;

				++count;
				++it;
			}

			return NULL;
		}
        
        T firstItem()
        {
            return _list.front();
        }

        T lastItem()
        {
            return _list.back();
        }

        bool hasItem(T item)
        {
            return find(_list.begin(), _list.end(), item)!=_list.end();
        }

		unsigned int size()
		{
			return _list.size();
		}

        unsigned int size() const
        {
            return _list.size();
        }

    protected:
		virtual void onItemAdded(T item){}
		virtual void onItemRemoved(T item){}

	private:
        TypeListList    _list;

	};

}}
#endif
#endif
