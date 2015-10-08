/*
 *  UVBuffer.h
 *  player
 *
 *  Created by Ben Siroshton on 8/6/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _UVBuffer_h_
#define _UVBuffer_h_

#include "im360/core/MarbleConfig.h"
#include "RenderElement.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace mesh {

	struct UV
	{
		float u;
		float v;
	};
	
	class I3DAPI UVBuffer : virtual public RenderElement
	{	
	public:
        typedef core::SharedPointer<UVBuffer>::pointer pointer;
				
        static UVBuffer::pointer create();
        static UVBuffer::pointer create(unsigned int count);
        
		virtual ~UVBuffer();
        virtual std::string getClassName() const;
		
		float * uvs();
		UV * getUV(unsigned int index);
		void setUV(unsigned int index, float u, float v);
		
	protected:
		UVBuffer();
        virtual bool init();
        virtual bool init(unsigned int count);
        
	};
	
}}
#endif
#endif
