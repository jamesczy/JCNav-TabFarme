/*
 *  SphereShape.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _SphereShape_h_
#define _SphereShape_h_

#include "CollisionObject.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace component {

	class I3DAPI SphereShape : virtual public CollisionObject
	{
	public:
        typedef core::SharedPointer<SphereShape>::pointer pointer;

        static SphereShape::pointer create();
		virtual ~SphereShape();
        virtual std::string getClassName() const;

		void setRadius(float radius);

		virtual void fitShape();

	protected:
        SphereShape();
        virtual bool init();

        class Data;
        Data * _data;

	};

}}
#endif
#endif
