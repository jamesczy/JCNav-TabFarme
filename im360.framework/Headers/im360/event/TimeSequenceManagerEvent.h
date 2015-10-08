/*
 *  TimeSequenceManagerEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 10/03/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */

#ifndef _TimeSequenceManagerEvent_h_
#define _TimeSequenceManagerEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"
#include "im360/sequence/ITimeSequence.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI TimeSequenceManagerEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<TimeSequenceManagerEvent>::pointer pointer;

        enum EventId
        {
            SEQUENCE_ADDED,
            SEQUENCE_REMOVED
        };

        im360::sequence::ITimeSequence::pointer sequence;

        static TimeSequenceManagerEvent::pointer create(unsigned int eventId);
        static TimeSequenceManagerEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~TimeSequenceManagerEvent();
        virtual std::string getClassName() const;
        
    protected:
        TimeSequenceManagerEvent();

    };

}}
#endif
#endif
