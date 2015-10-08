#ifndef _FreeTree_h_
#define _FreeTree_h_

#include "Debug.h"
#include "Pointer.h"
#define TEST

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace util {

	template <typename T> class FreeTree
	{
    public:
        typedef typename std::list<FreeTree<T>*>            freeTreeList;
        typedef typename std::list<FreeTree<T>*>::iterator  freeTreeListIterator;

		FreeTree<T>()
		{
			_parent = NULL;
		}
		
		virtual ~FreeTree()
		{
			remove();
		}		

        virtual std::string getClassName() const
        {
            return CLASS_NAME("util.FreeTree);
        }

        FreeTree<T> * getParent()
		{
			return _parent;
		}
		
		void bringToFront(){
			if( !_parent ) return;
			
            freeTreeListIterator it = _parent->_nodes.begin();
			while(it!=_nodes.end())
			{
				if(*it==this)
				{
					_parent->_nodes.erase(it);
					break;
				}
				it++;
			}
			
			_parent->_nodes.push_back(this);
		}
				
        FreeTree<T> * addChild(FreeTree<T> * node, int atPos=-1)
		{
			if( !node ) return NULL;

			if( node->getParent() )
			{
				I3d_debug(im360::util::DBG_WARNING,"trying to add a node who already has a parent.");
				return NULL; // node already has a parent
			}

			node->_parent = this;
			if( atPos<0 || _nodes.size()==0 )
				_nodes.push_back(node);
			else
			{
				int index=0;
                freeTreeListIterator it = _nodes.begin();
				while(it!=_nodes.end())
				{
					if(atPos==index)
					{
						_nodes.insert(it,node);
						break;
					}
					index++;
					it++;
				}
			}


			childNodeAdded(node);
			node->addedToParent();

			return node;
		}
		
		void removeFromParent()
		{
			if( !_parent ) return;			
			_parent->removeChild(this);
		}

        FreeTree<T> * removeChild(FreeTree<T> * node)
		{
			if( !node ) return NULL;

            freeTreeListIterator it = _nodes.begin();
			while(it!=_nodes.end())
			{
				if( *it==node )
				{
					erase(it);
					return node;
				}
				else
				{
					it++;
				}
			}
			return NULL;
		}

        bool hasChild(FreeTree<T> * node)
		{
			if( !node ) return false;
			return node->_parent==this;
		}

        FreeTree<T> * getChild(unsigned long index)
		{
			unsigned long count=0;
            for(freeTreeListIterator it = _nodes.begin();it!=_nodes.end();it++,count++)
			{
				if( count==index ) return *it;
			}

			return NULL;

		}
		
		void deleteChildren(bool recursive=false)
		{
            freeTreeListIterator it = _nodes.begin();

			while(it!=_nodes.end())
			{
				FreeTree<T> * node = *it;

				if( recursive )
					node->deleteChildren(recursive);
				
				it = erase(it);
				delete node;
			}
		}

		void removeChildren(bool recursive=false)
		{
            freeTreeListIterator it = _nodes.begin();
			
			while(it!=_nodes.end())
			{
				FreeTree<T> * node = *it;
				
				if( recursive )
					node->deleteChildren(recursive);
				
				it = erase(it);
			}
		}

		unsigned long getChildCount()
		{
			return _nodes.size();
		}

        freeTreeListIterator begin()
		{
			return _nodes.begin();
		}

        freeTreeListIterator end()
		{
			return _nodes.end();
		}

        freeTreeListIterator erase(freeTreeListIterator it)
		{
			FreeTree<T> * node = *it;
			assert( node->_parent==this );

			node->_parent = NULL;
		
            freeTreeListIterator next = _nodes.erase(it);
			
			node->removedFromParent();
			childNodeRemoved(node);

			return next;
		}

	protected:
		FreeTree<T> *	_parent;
        freeTreeList	_nodes;
		
		virtual void addedToParent(){}
		virtual void childNodeAdded(FreeTree<T> * node){ node=node; }
		virtual void childNodeRemoved(FreeTree<T> * node){ node=node; }
		virtual void removedFromParent(){}
	};

}}
#endif
#endif
