/*
 *  VertexBuffer3.h
 *  player
 *
 *  Created by Ben Siroshton on 8/6/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _VertexBuffer3_h_
#define _VertexBuffer3_h_

#include "im360/core/MarbleConfig.h"
#include "im360/math/MathUtils.h"
#include "RenderElement.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace mesh {

	struct XYZ
	{
		float x;
		float y;
		float z;
	};
	
	class I3DAPI VertexBuffer3 : virtual public RenderElement
	{
	public:
        typedef core::SharedPointer<VertexBuffer3>::pointer pointer;

        static VertexBuffer3::pointer create();
        static VertexBuffer3::pointer create(unsigned int count);
		
        virtual ~VertexBuffer3();
        virtual std::string getClassName() const;
		
		float * vertices();
		XYZ * getVert(unsigned int index);
        math::vec3 getVec3(unsigned int index) const;
		void setVert(unsigned int index, float x, float y, float z);

	protected:
		VertexBuffer3();
		virtual bool init();
        virtual bool init(unsigned int count);

	};
	
}}
#endif
#endif
