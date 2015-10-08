//
//  IMotionListener.h
//  libim360
//
//  Created by Ben Siroshton on 12/27/11.
//  Copyright (c) 2011 Immersive Media. All rights reserved.
//

#ifndef _libim360_IMotionListener_h
#define _libim360_IMotionListener_h

#include "im360/math/MathTypes.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace device {

    class I3DAPI IMotionListener
    {
    public:
        typedef core::SharedPointer<IMotionListener>::pointer pointer;

		struct MotionData
        {
            float           yaw;
            float           pitch;
            float           roll;
            im360::math::vec3   gravity;
        };
        
        virtual ~IMotionListener(){}
        virtual void onDeviceMotion(const IMotionListener::MotionData & motion) = 0;

    };
    
}}
#endif
#endif
