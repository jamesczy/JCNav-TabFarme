/*
 *  PlayerEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 9/27/12.
 *  Copyright 2012 Immersive Player. All rights reserved.
 *
 */

#ifndef _PlayerEvent_h_
#define _PlayerEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI PlayerEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<PlayerEvent>::pointer pointer;

        enum EventId
        {
            SCENE_MANAGER_SET,
            SNAPSHOT_SAVED
        };

        static PlayerEvent::pointer create(unsigned int eventId);
        static PlayerEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~PlayerEvent();
        virtual std::string getClassName() const;

    protected:
        PlayerEvent();
        
    };

}}
#endif
#endif

