/*
 *  TimeSequenceEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 10/01/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */

#ifndef _TimeSequenceEvent_h_
#define _TimeSequenceEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"
#include "im360/sequence/ITimeSequenceFrame.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI TimeSequenceEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<TimeSequenceEvent>::pointer pointer;

        enum EventId
        {
            FRAME_ADDED,
            FRAME_REMOVED
        };

        im360::sequence::ITimeSequenceFrame::pointer frame;

        static TimeSequenceEvent::pointer create(unsigned int eventId);
        static TimeSequenceEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~TimeSequenceEvent();
        virtual std::string getClassName() const;
        
    protected:
        TimeSequenceEvent();
    };

}}
#endif
#endif
