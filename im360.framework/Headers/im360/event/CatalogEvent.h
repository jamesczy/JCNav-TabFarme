/*
 *  CatalogEvent.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 3/29/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _CatalogEvent_h_
#define _CatalogEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI CatalogEvent : virtual public Event
	{
	public:
        typedef core::SharedPointer<CatalogEvent>::pointer pointer;

		enum EventId
		{
			INSTALL_STATUS
		};
		
		enum StatusCode
		{
			SUCCESS,
			REJECTED,
			STARTED
		};

		enum InstallType
		{
			PACKAGE,
			VIDEO
		};

		StatusCode  status;

		std::string sourceFile;
		long        entityId;
		InstallType	installType;

        static CatalogEvent::pointer create(unsigned int eventId);
        static CatalogEvent::pointer create(unsigned int eventId, std::string message);
        
		virtual ~CatalogEvent();
        virtual std::string getClassName() const;
        
    protected:
		CatalogEvent();
		
	};

}}
#endif
#endif

