/*
 *  VertexBuffer2.h
 *  player
 *
 *  Created by Ben Siroshton on 11/4/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _VertexBuffer2_h_
#define _VertexBuffer2_h_

#include "im360/core/MarbleConfig.h"
#include "RenderElement.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace mesh {

	struct XY
	{
		float x;
		float y;
	};
	
	class I3DAPI VertexBuffer2 : virtual public RenderElement
	{		
	public:
        typedef core::SharedPointer<VertexBuffer2>::pointer pointer;

        static VertexBuffer2::pointer create();
        static VertexBuffer2::pointer create(unsigned int count);

		virtual ~VertexBuffer2();
        virtual std::string getClassName() const;
		
		float * vertices();
		XY * getVert(unsigned int index);
		void setVert(unsigned int index, float x, float y);
		
	protected:
		VertexBuffer2();
		virtual bool init();
        virtual bool init(unsigned int count);
		
	};
	
}}
#endif
#endif
