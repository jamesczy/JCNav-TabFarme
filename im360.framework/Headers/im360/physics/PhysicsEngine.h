/*
 *  PhysicsEngine.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _PhysicsEngine_h_
#define _PhysicsEngine_h_

#include "im360/core/MarbleConfig.h"
#include "IPhysicsEngine.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace physics {

	class I3DAPI PhysicsEngine : virtual public core::I3dObject, virtual public IPhysicsEngine
	{
	public:
        typedef core::SharedPointer<PhysicsEngine>::pointer pointer;

        static PhysicsEngine::pointer create();
        
		virtual ~PhysicsEngine();
        virtual std::string getClassName() const;

        virtual void addPhysicsObject(IPhysicsObject::pointer physicsObject);
        virtual void removePhysicsObject(IPhysicsObject::pointer physicsObject);

		virtual bool hitTest(const im360::math::Ray3 & ray, float rayLength, HitInfo & hitInfo);
        virtual bool hitTestSingle(const im360::math::Ray3 & ray, float rayLength, const IPhysicsObject & testObj, HitInfo & hitInfo);

		virtual bool save(const char * file);

    protected:
        PhysicsEngine();
        virtual bool init();
        
	private:
		class Data;
		Data * _data;

	};

}}
#endif
#endif
