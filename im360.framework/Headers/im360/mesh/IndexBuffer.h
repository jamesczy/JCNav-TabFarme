/*
 *  IndexBuffer.h
 *  player
 *
 *  Created by Ben Siroshton on 8/6/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _IndexBuffer_h_
#define _IndexBuffer_h_

#include "im360/core/MarbleConfig.h"
#include "RenderElement.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace mesh {
	
	class I3DAPI IndexBuffer : virtual public RenderElement
	{		
	public:
        typedef core::SharedPointer<IndexBuffer>::pointer pointer;

        static IndexBuffer::pointer create();
        static IndexBuffer::pointer create(unsigned int count);
        
		virtual ~IndexBuffer();
        virtual std::string getClassName() const;
		
		unsigned short * indices();
		
	protected:
		IndexBuffer();
        virtual bool init();
		virtual bool init(unsigned int count);

	};

}}
#endif
#endif
