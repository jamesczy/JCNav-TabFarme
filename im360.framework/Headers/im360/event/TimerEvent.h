#ifndef TIMEREVENT_H
#define TIMEREVENT_H

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI TimerEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<TimerEvent>::pointer pointer;

        enum EventId
        {
            INTERVAL_REACHED
        };

        static TimerEvent::pointer create(unsigned int eventId);
        static TimerEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~TimerEvent();
        virtual std::string getClassName() const;

    protected:
        TimerEvent();
    };

}}
#endif
#endif
