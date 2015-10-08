/*
 *  _ITimeline.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 11/08/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef _ITimeline_h_
#define _ITimeline_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace sequence {

    class I3DAPI ITimeline
    {
    public:
        typedef core::SharedPointer<ITimeline>::pointer pointer;

        virtual float getTime() = 0;
        virtual void setTime(float time) = 0;
        virtual float getDuration() = 0;
        virtual bool getPaused() = 0;
    };

}}
#endif
#endif
