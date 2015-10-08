/*
 *  ITimeSequence.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 9/28/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef _TimeSequence_h_
#define _TimeSequence_h_

#include "im360/core/MarbleConfig.h"
#include "im360/event/EventDispatcher.h"
#include "im360/event/EventListener.h"
#include "im360/json/IJsonHandler.h"

#include "ITimeSequence.h"
#include "ITimeSequenceFrame.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace sequence {

    class I3DAPI TimeSequence : virtual public ITimeSequence, virtual public im360::event::EventDispatcher, virtual public im360::event::EventListener
    {
    public:
        typedef core::SharedPointer<TimeSequence>::pointer pointer;
        
        static TimeSequence::pointer create();
        
        virtual ~TimeSequence();
        virtual std::string getClassName() const;

        virtual unsigned int addFrame(const ITimeSequenceFrame::pointer & frame);
        virtual void removeFrame(const ITimeSequenceFrame::pointer & frame);
        virtual bool hasFrame(const ITimeSequenceFrame::pointer & frame);

        virtual int getFramesAtTime(float time, ITimeSequenceFrame::pointer & fromFrame, ITimeSequenceFrame::pointer & toFrame, int * fromIndex, int * toIndex);
        virtual ITimeSequenceFrame::pointer getInterpolatedFrameAtTime(float time);
        virtual ITimeSequenceFrame::pointer getInterpolatedFrameAtTime(float time, int * fromIndex, int * toIndex);

        virtual unsigned int getFrameCount();
        virtual ITimeSequenceFrame::pointer getFrameAtIndex(unsigned int index);

        virtual void setEnabled(bool enabled);
        virtual bool getEnabled();

        virtual void setTarget(im360::core::I3dObject::pointer target);
        virtual im360::core::I3dObject::pointer getTarget();

        // IJsonHandler
        virtual void handleJsonNode(std::string name, im360::json::JsonInfo & json);

    protected:
        TimeSequence();
        virtual bool init();
        
        class Data;
        Data * _data;

        virtual void onEvent(im360::event::Event::pointer event);
        virtual void innerJson(im360::json::JsonStringBuilder & json) const;
    };

}}
#endif
#endif
