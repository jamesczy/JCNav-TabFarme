/*
 *  TimeChangeEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 9/28/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */

#ifndef _TimeChangeEvent_h_
#define _TimeChangeEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI TimeChangeEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<TimeChangeEvent>::pointer pointer;

        enum EventId
        {
            TIME_CHANGED,
            DURATION_CHANGED
        };

        float time;

        static TimeChangeEvent::pointer create(unsigned int eventId);
        static TimeChangeEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~TimeChangeEvent();
        virtual std::string getClassName() const;

    protected:
        TimeChangeEvent();

    };

}}
#endif
#endif

