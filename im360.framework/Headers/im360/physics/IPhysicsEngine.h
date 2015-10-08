/*
 *  IPhysicsEngine.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _IPhysicsEngine_h_
#define _IPhysicsEngine_h_

#include "IPhysicsObject.h"
#include "im360/math/Ray3.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace physics {

	class IPhysicsEngine
	{
	public:
        typedef core::SharedPointer<IPhysicsEngine>::pointer pointer;
        typedef core::WeakPointer<IPhysicsEngine>::pointer weakPointer;

		struct HitInfo
		{
            physics::IPhysicsObject::pointer    target;
            math::vec3                 hitPosition;
		};

		typedef std::vector<HitInfo> HitList;

        virtual void addPhysicsObject(physics::IPhysicsObject::pointer physicsObject) = 0;
        virtual void removePhysicsObject(physics::IPhysicsObject::pointer physicsObject) = 0;

        virtual bool hitTest(const math::Ray3 & ray, float rayLength, HitInfo & hitInfo) = 0;

		virtual bool save(const char * file) = 0;

	};

}}
#endif
#endif
