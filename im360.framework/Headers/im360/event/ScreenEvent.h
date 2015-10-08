/*
 *  ScreenEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 8/7/13.
 *  Copyright 2013 Immersive Media. All rights reserved.
 *
 */

#ifndef _ScreenEvent_h_
#define _ScreenEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI ScreenEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<ScreenEvent>::pointer pointer;

        enum EventId
        {
            SCREEN_SET
        };

        static ScreenEvent::pointer create(unsigned int eventId);
        static ScreenEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~ScreenEvent();
        virtual std::string getClassName() const;
    
    protected:
        ScreenEvent();
    };

}}
#endif
#endif

