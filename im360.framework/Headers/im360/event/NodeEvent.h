/*
 *  NodeEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 11/08/12.
 *  Copyright 2012 Immersive Node. All rights reserved.
 *
 */

#ifndef _NodeEvent_h_
#define _NodeEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI NodeEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<NodeEvent>::pointer pointer;

        enum EventId
        {
            ADDED_TO_PARENT,
            REMOVED_FROM_PARENT,
            COMPONENT_ADDED,
            COMPONENT_REMOVED
        };

        static NodeEvent::pointer create(unsigned int eventId);
        static NodeEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~NodeEvent();
        virtual std::string getClassName() const;

    protected:
        NodeEvent();
        
    };

}}
#endif
#endif

