/*
 *  CollisionObject.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _CollisionObject_h_
#define _CollisionObject_h_

#include "ComponentBase.h"
#include "im360/physics/IPhysicsEngine.h"
#include "im360/math/MathTypes.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace component {

    class I3DAPI CollisionObject : virtual public ComponentBase, virtual public physics::IPhysicsObject
	{
    friend class physics::PhysicsEngine;

	public:
        typedef core::SharedPointer<CollisionObject>::pointer pointer;

		virtual ~CollisionObject();
        virtual std::string getClassName() const;

		virtual void fitShape() = 0;

	protected:
        CollisionObject();
        virtual bool init();
		virtual void setShape(void * shape);

        class Data;
        Data * _data;

		virtual void onUpdate();
		virtual void onAddedToScene();
		virtual void onRemovedFromScene();
        
	private:
		void * getPhysicsHandle() const;

        physics::IPhysicsEngine::weakPointer _physicsEngine;

	};

}}
#endif
#endif
