/*
 *  EventManager.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 5/09/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _EventMangaer_h_
#define _EventMangaer_h_

#include "im360/core/MarbleConfig.h"
#include "im360/util/Thread.h"
#include "im360/core/Pointer.h"
#include "EventDispatcher.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <queue>
#include <list>
#include <map>
namespace im360 {
namespace event {

    class I3DAPI EventManager : virtual public util::Singleton<EventManager>, virtual public core::I3dObject //, virtual public EventDispatcher
	{
	friend class EventDispatcher;
    friend class util::Singleton<EventManager>;

	public:
        typedef core::SharedPointer<EventManager>::pointer pointer;

		virtual ~EventManager();
        virtual std::string getClassName() const;

		void dispatchEvents();

    protected:
        EventManager();
        virtual bool init();

	private:
        struct EventEntry
        {
            EventDispatcher::weakPointer    originator;
            EventDispatcher::weakPointer    sender;
            EventListener::weakPointer      listener;
            Event::pointer                  event;
        };

        struct
        {
            std::vector<EventEntry*>    queue;
            async::Mutex                queueMutex;
        } _events;

        struct
        {
            std::list<EventDispatcher::weakPointer> dispatchers;
            async::Mutex    mutex;
        } _registerdDispatchers;

        void registerDispatcher(const EventDispatcher::pointer & dispatcher);
        void unregisterDispatcher(const EventDispatcher::pointer & dispatcher);

        void registerListener(const EventDispatcher::pointer & dispatcher, const EventListener::pointer & listener);
        void unregisterListener(const EventDispatcher::pointer & dispatcher, const EventListener::pointer & listener);
        void queueEvent(const EventDispatcher::weakPointer & originator, Event::pointer & event);
        void queueEvent(const EventDispatcher::weakPointer & originator, const EventDispatcher::weakPointer & sender, Event::pointer & event);
	};

}}
#endif
#endif
