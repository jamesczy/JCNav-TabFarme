#ifndef _SceneEvent_h_
#define _SceneEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI SceneEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<SceneEvent>::pointer pointer;

        enum EventId
        {
            SCENE_RESET
        };

        static SceneEvent::pointer create(unsigned int eventId);
        static SceneEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~SceneEvent();
        virtual std::string getClassName() const;

    protected:
        SceneEvent();

    };

}}
#endif
#endif

