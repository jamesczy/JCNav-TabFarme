/*
 *  SceneManagerEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 7/18/13.
 *  Copyright 2013 Immersive Media. All rights reserved.
 *
 */

#ifndef _SceneManagerEvent_h_
#define _SceneManagerEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"
#include "im360/scene/Scene.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI SceneManagerEvent : virtual public Event
    {
    public:
        typedef core::SharedPointer<SceneManagerEvent>::pointer pointer;

        enum EventId
        {
            SCENE_ACTIVATED,
            SCENE_DEACTIVATED
        };

        scene::Scene::pointer scene;

        static SceneManagerEvent::pointer create(unsigned int eventId);
        static SceneManagerEvent::pointer create(unsigned int eventId, std::string message);

        virtual ~SceneManagerEvent();
        virtual std::string getClassName() const;
        
    protected:
        SceneManagerEvent();
    };

}}
#endif
#endif
