/*
 *  IEntity.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/10/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _IEntity_h_
#define _IEntity_h_

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace ws {
namespace entities {

    static const double LNG_LAT_EMPTY = -9999;

    class EntityLevel
	{
	public:
		enum
		{
			NONE,
			ID_ONLY,
			FULL
		};
	private:
		EntityLevel(){} // don't allow construction of this class
	};

    class IEntity : virtual public core::I3dObject
	{
	public:
        typedef core::SharedPointer<IEntity>::pointer pointer;

		virtual void clear() = 0;

		virtual std::string getJson() const = 0;
		virtual void parseJson(std::string json) = 0;
	};

}}}
#endif
#endif
