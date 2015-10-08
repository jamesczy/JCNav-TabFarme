/*
 *  DownloadEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 7/9/13.
 *  Copyright 2013 Immersive Media. All rights reserved.
 *
 */

#ifndef _DownloadEvent_h_
#define _DownloadEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI DownloadEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<DownloadEvent>::pointer pointer;

        enum EventId
        {
            DONLOAD_STARTED,
            DOWNLOAD_COMPLETE,
            DOWNLOAD_FAILED,
            DOWNLOAD_PROGRESS,
            DOWNLOAD_CANCELED
        };

        std::string url;
        std::string destination;
        float       progress;
        int         httpStatus;
        void *      userData;

        static DownloadEvent::pointer create(unsigned int eventId);
        static DownloadEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~DownloadEvent();
        virtual std::string getClassName() const;
        
    protected:
        DownloadEvent();
    };

}}
#endif
#endif

