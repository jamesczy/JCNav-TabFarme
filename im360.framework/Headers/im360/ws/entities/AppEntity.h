//
//  AppEntity.h
//  libim360
//
//  Created by Ben Siroshton on 2/25/13.
//  Copyright (c) 2013 Immersive Ventures. All rights reserved.
//

#ifndef __libim360__AppEntity__
#define __libim360__AppEntity__

#include "im360/core/MarbleConfig.h"
#include "IEntity.h"
#include "im360/core/Pointer.h"
#include "AppPropertyEntity.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI AppEntity : virtual public IEntity
	{
	public:
        typedef core::SharedPointer<AppEntity>::pointer pointer;
        
		long		appId;
		std::string	appName;
		std::string	appUrl;
		std::string	appDescription;
		std::string	appKey;
		std::string	appSecret;
		std::string	appDateAdded;
		std::string	appDateUpdated;
        
        std::vector<AppPropertyEntity::pointer> properties;
        
        static AppEntity::pointer create();
        
		virtual ~AppEntity();
        virtual std::string getClassName() const;
        
        AppPropertyEntity::pointer findProperty(const std::string & name);
        std::string getPropertyValue(const std::string & name, const std::string & defaultValue = "");
        
		virtual void clear();

        virtual void jsonPropertiesStart();
		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();
        
		virtual std::string getJson() const;
		virtual void parseJson(std::string json);
        
    protected:
        AppEntity();
        virtual bool init();
        
	};
    
}}}
#endif
#endif
