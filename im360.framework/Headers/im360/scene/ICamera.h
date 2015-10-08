/*
 *  ICamera.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on ...
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _ICamera_h_
#define _ICamera_h_

#include "Node.h"
#include "Viewport.h"
#include "im360/math/MathUtils.h"
#include "im360/math/Rect.h"
#include "im360/math/Ray3.h"
#include "im360/core/Pointer.h"
#include "im360/util/Command.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

    class I3DAPI ICamera : virtual public Node
	{
	public:
        typedef core::SharedPointer<ICamera>::pointer pointer;

		virtual ~ICamera();

        virtual math::matrix getProjection(scene::Viewport & viewport) = 0;
        virtual math::matrix getProjectionOrtho(scene::Viewport & viewport) = 0;
        virtual math::matrix getView(scene::Viewport & viewport) = 0;

		virtual float getFov() = 0;
		virtual void setFov(float f) = 0;

		virtual float getNear() = 0;
		virtual void setNear(float n) = 0;

		virtual float getFar() = 0;
		virtual void setFar(float f) = 0;

        virtual math::Ray3 screenToRay(float x, float y, scene::Viewport & viewport) = 0;
        virtual math::Ray3 screenToWorldRay(float x, float y, scene::Viewport & viewport) = 0;
        
        // I3dObject
        virtual util::Variant evaluate(const util::Command & command);
        
    protected:
        ICamera();

	};

}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

I3DAPI float I3dICamera_getFov(long handle);
I3DAPI void I3dICamera_setFov(long handle, float fov);
I3DAPI float I3dICamera_getNear(long handle);
I3DAPI void I3dICamera_setNear(long handle, float near);
I3DAPI float I3dICamera_getFar(long handle);
I3DAPI void I3dICamera_setFar(long handle, float far);

#ifdef __cplusplus
}
#endif


#endif

