#ifndef _BlockManagerh_
#define _BlockManagerh_

#include "im360/util/Singleton.h"
#include "im360/util/Debug.h"
#include "im360/util/Thread.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace video {

	class I3DAPI BlockManager : virtual public util::Singleton<BlockManager>
	{
    friend class util::Singleton<BlockManager>;
	public:
		struct Block
		{
			float			time;
			bool			isKey;
			unsigned char *	data;
			unsigned int	dataSize;
			unsigned int	availableSize;
#ifdef DEBUG
			int				refCount;
#endif
		};

		virtual ~BlockManager();
        virtual std::string getClassName() const;

		Block * requestBlock(unsigned int size);
		void returnBlock(Block * block);
		unsigned long getBytesAllocated();
		unsigned long getBlocksAllocated();
		unsigned long getBlocksInUse();
		unsigned long getFreeBlocks();
		void setMinBlockSize(unsigned int size);
		unsigned int getMinBlockSize();

    protected:
        BlockManager();

	private:
		typedef std::list<Block*>	BlockList;
		typedef BlockList::iterator	BlockListIterator;

        BlockList       _available;
        async::Mutex	_availableMutex;

        BlockList       _inUse;
        async::Mutex	_inUseMutex;

		unsigned int	_minDataSize;
		unsigned long	_bytesAllocated;
		unsigned int	_maxBlockSize;

		void freeList(BlockList & list);
		bool contains(BlockList & list, Block * block);

	};

}}
#endif
#endif
