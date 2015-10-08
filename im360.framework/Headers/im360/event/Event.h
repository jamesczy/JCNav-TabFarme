/*
 *  Event.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 3/22/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Event_h_
#define _Event_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/I3dObject.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace event {

	class I3DAPI EventManager;
    class I3DAPI EventDispatcher;
	class I3DAPI EventListener;

	class I3DAPI Event : virtual public core::I3dObject
	{
	friend class EventManager;
	friend class EventDispatcher;

	public:
        typedef core::SharedPointer<Event>::pointer pointer;

        static Event::pointer create(unsigned int eventId);
        static Event::pointer create(unsigned int eventId, std::string message);
        
		//Event(const Event & event);
		//Event & operator=(const Event & event);
        
		virtual ~Event();
        virtual std::string getClassName() const;

		unsigned int getEventId();
		std::string getMessage();
        I3dObject::pointer getOriginator();
        I3dObject::pointer getSender();

        void stopPropagation();

    protected:
		Event();
        virtual bool init(unsigned int eventId);
        virtual bool init(unsigned int eventId, std::string message);
        
	private:
		class Data;
        Data * _data;

        unsigned int        _eventId;
        bool                _stopPropagation;
        std::string         _message;

        void setOriginator(I3dObject::pointer originator);
        void setSender(I3dObject::pointer sender);

	};

}}
#endif
#endif
