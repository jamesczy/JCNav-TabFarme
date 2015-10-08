/*
 *  EventDispatcher.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 1/24/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _EventDispatcher_h_
#define _EventDispatcher_h_

#include "im360/core/MarbleConfig.h"
#include "Event.h"
#include "EventListener.h"
#include "im360/core/Pointer.h"
#include "im360/util/Thread.h"
#include "im360/util/Timer.h"
#include "im360/util/Command.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
#include <vector>
namespace im360 {
namespace event {

    class I3DAPI IEventDispatcher
    {
    public:
        virtual void addEventListener(EventListener::pointer listener) = 0;
        virtual void removeEventListener(EventListener::pointer listener) = 0;
    };

    class I3DAPI EventDispatcher : virtual public core::I3dObject, virtual public IEventDispatcher
	{
	friend class EventManager;

	public:
        typedef core::SharedPointer<EventDispatcher>::pointer pointer;
        typedef core::WeakPointer<EventDispatcher>::pointer weakPointer;

        static EventDispatcher::pointer create();
        
		virtual ~EventDispatcher();
        virtual std::string getClassName() const;

        virtual void setParentDispatcher(EventDispatcher::weakPointer parent);

        virtual void addEventListener(EventListener::pointer listener);
        virtual void removeEventListener(EventListener::pointer listener);
        
        void setEventCullingEnabled(bool enable);
        bool getEventCullingEnabled();
        
        void setEventInterval(unsigned long interval);
        unsigned long getEventInterval();
        
        void setDispatchingEnabled(bool enabled);
        bool getDispatchingEnabled();

        // I3dObject
        virtual util::Variant evaluate(const util::Command & command);

	protected:
		EventDispatcher();
        virtual bool init();
        
        bool _isDispatchingEnabled; // for particulary noisy dispatchers, check this before creating an event and calling queueEvent

        void queueEvent(Event::pointer event);        

	private:
        typedef std::list<EventListener::weakPointer> Listeners;

        EventDispatcher::weakPointer    _parentDispatcher;

        bool            _eventCullingEnabled;   // only used if eventInterval>0
        unsigned long   _eventInterval;         // queue up events then fire at these intervals, useful if event culling is enabled to reduce the number of events that get fired by noisy dispatchers
        util::Timer     _eventTimer;

        Listeners       _listeners;
        async::Mutex    _listenerMutex;

        struct
        {
            std::vector<Event::pointer> events;
            async::Mutex mutex;
        } _queue;

        bool readyToDispatch();
        void resetEventTimer();
        void tickQueue();

	};

}}
#endif
#endif
