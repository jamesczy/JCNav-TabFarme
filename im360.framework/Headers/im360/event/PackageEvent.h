#ifndef _PackageEvent_h_
#define _PackageEvent_h_

#include "Event.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI PackageEvent : virtual public Event
	{
	public:
        typedef core::SharedPointer<PackageEvent>::pointer pointer;

		enum EventId
		{
            PASSWORD_REQUEST
		};

		std::string password;
		bool		cancel;

        static PackageEvent::pointer create(unsigned int eventId);
        static PackageEvent::pointer create(unsigned int eventId, std::string message);

		virtual ~PackageEvent();
        virtual std::string getClassName() const;
    
    protected:
        PackageEvent();
	};

}}
#endif
#endif
