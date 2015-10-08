/*
 *  ITimeSequence.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 9/28/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef _ITimeSequence_h_
#define _ITimeSequence_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"

#include "ITimeSequenceFrame.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace sequence {

    class I3DAPI ITimeSequence
    {
    public:
        typedef core::SharedPointer<ITimeSequence>::pointer pointer;

        virtual unsigned int addFrame(const ITimeSequenceFrame::pointer & frame) = 0;
        virtual void removeFrame(const ITimeSequenceFrame::pointer & frame) = 0;
        virtual bool hasFrame(const ITimeSequenceFrame::pointer & frame) = 0;

        virtual int getFramesAtTime(float time, ITimeSequenceFrame::pointer & fromFrame, ITimeSequenceFrame::pointer & toFrame, int * fromIndex, int * toIndex) = 0;
        virtual ITimeSequenceFrame::pointer getInterpolatedFrameAtTime(float time) = 0;

        virtual unsigned int getFrameCount() = 0;
        virtual ITimeSequenceFrame::pointer getFrameAtIndex(unsigned int index) = 0;

        virtual void setEnabled(bool enabled) = 0;
        virtual bool getEnabled() = 0;

        virtual void setTarget(im360::core::I3dObject::pointer target) = 0;
        virtual im360::core::I3dObject::pointer getTarget() = 0;
    };

}}
#endif
#endif
