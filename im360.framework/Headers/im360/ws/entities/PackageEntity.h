/*
 *  PackageEntity.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 05/31/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _PackageEntity_h_
#define _PackageEntity_h_

#include "im360/core/MarbleConfig.h"
#include "IEntity.h"

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI PackageEntity : virtual public IEntity
	{		
	public:
        typedef core::SharedPointer<PackageEntity>::pointer pointer;

        long        sourceId;
		long		packageId;
		std::string	packageName;
		std::string	packageFile;
		std::string	packageThumb;
		std::string	packageThumb2x;
		std::string	packageKeywords;
		std::string	packageDescription;
		std::string	packageUrl;
		std::string	packageThumbUrl;
		std::string	packageThumb2xUrl;
		std::string packageCity;
		std::string packageState;
		std::string packageCountry;
		double		packageLatitude;
		double		packageLongitude;
		std::string	packageDateAdded;
		std::string	packageDateUpdated;
        
        static PackageEntity::pointer create();
        
		virtual ~PackageEntity();
        virtual std::string getClassName() const;

		virtual void clear();

        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

		virtual std::string getJson() const;
		virtual void parseJson(std::string json);
        
    protected:
		PackageEntity();
        virtual bool init();
	};

}}}
#endif
#endif

