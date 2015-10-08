
#ifndef _FrameEvent_h_
#define _FrameEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI FrameEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<FrameEvent>::pointer pointer;

        enum EventId
        {
            MEDIA_FRAME
        };

        std::string url;

        static FrameEvent::pointer create(unsigned int eventId);
        static FrameEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~FrameEvent();
        virtual std::string getClassName() const;

    protected:
        FrameEvent();
    };


}}
#endif
#endif

