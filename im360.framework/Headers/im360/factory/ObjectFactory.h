/*
 *  ObjectFactory.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 2/15/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _ObjectFactory_h_
#define _ObjectFactory_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/I3dObject.h"
#include "im360/util/Singleton.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace factory {

    class I3DAPI ObjectFactory : virtual public core::I3dObject, virtual public im360::util::Singleton<ObjectFactory>
	{
    friend class im360::util::Singleton<ObjectFactory>;
	public:
        virtual ~ObjectFactory();
        virtual std::string getClassName() const;

        im360::core::I3dObject::pointer createObject(std::string className);

        template<typename T>
        std::tr1::shared_ptr<T> createObject(std::string className)
        {
            im360::core::I3dObject::pointer obj = createObject(className);
            if( !obj ) return std::tr1::shared_ptr<T>();

            //return obj->getPointer<T>();
            return std::tr1::dynamic_pointer_cast<T>(obj);
        }

	protected:
        ObjectFactory();
        
	};

}}
#endif
#endif
