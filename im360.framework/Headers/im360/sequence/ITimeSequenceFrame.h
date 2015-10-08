/*
 *  ITimeSequenceFrame.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 9/28/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef _ITimeSequenceFrame_h_
#define _ITimeSequenceFrame_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"
#include "im360/event/EventDispatcher.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace sequence {

    class I3DAPI ITimeSequenceFrame : virtual public im360::event::IEventDispatcher
    {
    public:
        typedef core::SharedPointer<ITimeSequenceFrame>::pointer pointer;

        virtual ITimeSequenceFrame::pointer getInterpolatedFrame(const ITimeSequenceFrame::pointer & frameTo, float amount) = 0;

        virtual ITimeSequenceFrame::pointer clone() = 0;

        virtual void setTime(float time) = 0;
        virtual float getTime() = 0;

        virtual bool getInterpolateToEnabled() = 0;
        virtual void setInterpolateToEnabled(bool enabled) = 0;

        virtual void updateTarget(im360::core::I3dObject::pointer & target, float amount=1.f) = 0;
    };

}}
#endif
#endif
