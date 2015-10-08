/*
 *  EventListener.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 3/22/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _EventListener_h_
#define _EventListener_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/I3dObject.h"
#include "Event.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI EventManager;

	class I3DAPI EventListener : virtual public core::I3dObject
	{
    friend class EventManager;

	public:
        typedef core::SharedPointer<EventListener>::pointer pointer;
        typedef core::WeakPointer<EventListener>::pointer weakPointer;

        static EventListener::pointer create();
        
		virtual ~EventListener();
        virtual std::string getClassName() const;

    protected:
        EventListener();
        
        virtual void onEvent(Event::pointer event);

	};

}}
#endif
#endif

