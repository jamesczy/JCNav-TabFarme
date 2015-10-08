/*
 *  DataBuffer.h
 *  player
 *
 *  Created by Ben Siroshton on 8/10/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _DataBuffer_h_
#define _DataBuffer_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace mesh {

    // TODO: convert this to a template where buffer is of type <T>
	class I3DAPI DataBuffer : virtual public core::I3dObject
	{
	public:
        typedef core::SharedPointer<DataBuffer>::pointer pointer;

        static DataBuffer::pointer create();
        static DataBuffer::pointer create(unsigned int size);
        
		virtual ~DataBuffer();
        virtual std::string getClassName() const;

		unsigned char * getBuffer();

		unsigned int getUsedSizeBytes();
		void setUsedSizeBytes(unsigned int size);

		unsigned int getBufferSizeBytes();
		
		virtual void resize(unsigned int sizeBytes, bool copy=false);

		virtual void destroy();
    
	protected:
        DataBuffer();
        virtual bool init();
		virtual bool init(unsigned int size);

		unsigned char * _buffer;
		unsigned int	_size;
		unsigned int	_usedSize;

	};

}}
#endif
#endif
