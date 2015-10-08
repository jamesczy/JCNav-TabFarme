/*
 *  IPhysicsObject.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _IPhysicsObject_h_
#define _IPhysicsObject_h_

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace physics {

	class PhysicsEngine;

    class IPhysicsObject
	{
	friend class PhysicsEngine;
    public:
        typedef core::SharedPointer<IPhysicsObject>::pointer pointer;
        typedef core::WeakPointer<IPhysicsObject>::pointer weakPointer;

	private:
		virtual	void * getPhysicsHandle() const = 0;

	};

}}
#endif
#endif

