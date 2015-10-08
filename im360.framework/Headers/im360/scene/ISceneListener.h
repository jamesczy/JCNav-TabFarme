/*
 *  ISceneListener.h
 *  libim360
 *
 *  Created by Ben Siroshton on 11/19/11.
 *  Copyright 2010-2011 Immersive Media. All rights reserved.
 *
 */

#ifndef _ISceneListener_h_
#define _ISceneListener_h_

#include "im360/math/Ray3.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

    class Node;
    
	class ISceneListener
	{
	public:
        typedef core::SharedPointer<ISceneListener>::pointer pointer;

        struct HitInfo
        {
            core::SharedPointer<Node>::pointer node;
        };
        
		virtual bool onNodeClick(const ISceneListener::HitInfo & info) = 0;
        virtual void onWorldClick(const math::Ray3 & ray) = 0;

	};

}}
#endif
#endif
