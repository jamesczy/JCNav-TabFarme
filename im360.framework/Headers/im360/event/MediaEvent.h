/*
 *  MediaEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 9/27/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */

#ifndef _MediaEvent_h_
#define _MediaEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI MediaEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<MediaEvent>::pointer pointer;

        enum EventId
        {
            MEDIA_LOADED,
            MEDIA_UNLOADED,
            MEDIA_PAUSED,
            MEDIA_PLAYING,
            MEDIA_ENDED,
            MEDIA_ERROR,
            MEDIA_STALLED,
            MEDIA_STALL_RECOVERED
        };

        std::string url;

        static MediaEvent::pointer create(unsigned int eventId);
        static MediaEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~MediaEvent();
        virtual std::string getClassName() const;
    
    protected:
        MediaEvent();
    };


}}
#endif
#endif

