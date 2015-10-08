/*
 *  TransformEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 7/23/13.
 *  Copyright 2013 Immersive Media. All rights reserved.
 *
 */

#ifndef _TransformEvent_h_
#define _TransformEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
    namespace event {
        
        class I3DAPI TransformEvent : virtual public Event
        {
        public:
            typedef core::SharedPointer<TransformEvent>::pointer pointer;
            
            enum EventId
            {
                POSITION_CHANGED,
                ROTATION_CHANGED,
                SCALE_CHANGED
            };
            
            static TransformEvent::pointer create(unsigned int eventId);
            static TransformEvent::pointer create(unsigned int eventId, std::string message);

            virtual ~TransformEvent();
            virtual std::string getClassName() const;

        protected:
            TransformEvent();

        };
        
        
    }}
#endif
#endif

