//
//  AppPropertyEntity.h
//  libim360
//
//  Created by Ben Siroshton on 2/26/13.
//  Copyright (c) 2013 Immersive Ventures. All rights reserved.
//

#ifndef __libim360__AppPropertyEntity__
#define __libim360__AppPropertyEntity__

#include "im360/core/MarbleConfig.h"
#include "im360/core/i3dObject.h"
#include "IEntity.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI AppPropertyEntity : virtual public IEntity
	{
	public:
        typedef core::SharedPointer<AppPropertyEntity>::pointer pointer;
        
        long        appPropertyId;
		long		appId;
		std::string	appPropertyName;
		std::string	appPropertyValue;
		std::string	appPropertyDescription;
		std::string	appPropertyDateAdded;
		std::string	appPropertyDateUpdated;
        
        static AppPropertyEntity::pointer create();
        
		virtual ~AppPropertyEntity();
        virtual std::string getClassName() const;
        
		virtual void clear();
        
        virtual void jsonPropertiesStart();
		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();
        
		virtual std::string getJson() const;
		virtual void parseJson(std::string json);
    
    protected:
        AppPropertyEntity();
        virtual bool init();
        
	};
    
}}}
#endif
#endif
