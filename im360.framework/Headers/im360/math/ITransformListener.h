/*
 *  ITransformListener.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _ITransformListener_h_
#define _ITransformListener_h_

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace math {

	class Transform;

	class ITransformListener
	{
	friend class Transform;
    public:
        typedef core::SharedPointer<ITransformListener>::pointer pointer;

	protected:
		virtual void onPositionChange() = 0;
		virtual void onScaleChange() = 0;
		virtual void onRotationChange() = 0;

	};

}}
#endif
#endif
