/*
 *  Packages.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 05/31/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _PackagesWs_h_
#define _PackagesWs_h_

#include "im360/core/MarbleConfig.h"
#include "WsUtil.h"
#include "im360/net/Url.h"
#include "entities/PackageEntity.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace ws {

    namespace entities { class ChannelEntity; }
    
    class I3DAPI Packages : virtual public core::I3dObject
	{
	public:
        typedef core::SharedPointer<Packages>::pointer pointer;

        static Packages::pointer create();

		virtual ~Packages();
        virtual std::string getClassName() const;

        entities::PackageEntity::pointer loadPackage(long packageId, int * responseCode, int flags=LIVE_ONLY);

        int getChannelPackages(entities::ChannelEntity * channel, int flags=0);
        unsigned int getChannelPackages(std::vector<entities::PackageEntity::pointer> & list, long channelId, int * responseCode, int flags=LIVE_ONLY);

        bool savePackage(entities::PackageEntity & package, int * responseCode);

        virtual void jsonPropertiesStart();
		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

        static bool rememberPackage(std::string key, const entities::PackageEntity::pointer & package);
        static entities::PackageEntity::pointer recallPackage(std::string key);
		static void forgetPackage(std::string key);

    protected:
		Packages();
        virtual bool init();

	private:
        std::vector<entities::PackageEntity::pointer> * _list;

		unsigned int query(std::string url);

	};
}}
#endif
#endif

