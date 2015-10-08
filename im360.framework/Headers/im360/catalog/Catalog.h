/*
 *  Catalog.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 3/28/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Catalog_h_
#define _Catalog_h_

#include "im360/core/MarbleConfig.h"
#include "im360/event/EventDispatcher.h"
#include "im360/event/CatalogEvent.h"
#include "im360/ws/entities/ChannelEntity.h"
#include "im360/ws/entities/PackageEntity.h"
#include "im360/ws/entities/VideoEntity.h"
#include "im360/ws/entities/RemoteServerEntity.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace catalog {

    class I3DAPI Catalog : virtual public util::Singleton<Catalog>, virtual public event::EventDispatcher, virtual public event::EventListener
	{
    friend class util::Singleton<Catalog>;
	public:
        typedef core::SharedPointer<Catalog>::pointer pointer;

		enum ResultCode
		{
			SUCCESS,
			ERROR_ALREADY_INSTALLED,
			ERROR_INVALID_LICENSE,
			ERROR_INVALID_PACKAGE,
			ERROR_PACKAGE_NOT_FOUND,
			ERROR_SOURCE_NOT_FOUND,
			ERROR_ENTITY_NOT_FOUND,
			ERROR_INVALID_ENTITY,
			ERROR_FAILED
		};
				
		virtual ~Catalog();
        virtual std::string getClassName() const;
		
		ResultCode installLicense(std::string licenseFile);

		// cancel any install for the given source file
		ResultCode cancelInstall(std::string sourceFile);

		// channels
        ResultCode installChannel(ws::entities::ChannelEntity::pointer & channel);
        ws::entities::ChannelEntity::pointer getChannel(unsigned long channelId, int depth=1, int packageDepth=1, int videoDepth=1, ResultCode * code=NULL);

		// packages
        ResultCode installPackage(std::string packageFile, const ws::entities::PackageEntity::pointer & packageEntity);
        ResultCode deletePackage(unsigned long packageId);
        ResultCode deletePackagesInChannel(ws::entities::ChannelEntity::pointer & channel);

        void installPublicPackages();
        bool isPackageInstalled(unsigned long packageId);
        ws::entities::PackageEntity::pointer getPackage(unsigned long packageId);
        bool getPackages(std::vector<ws::entities::PackageEntity::pointer> & packages);
        bool getPackages(long channelId, std::vector<ws::entities::PackageEntity::pointer> & packages);
        unsigned int getPackageChannels(unsigned long packageId, std::vector<ws::entities::ChannelEntity::pointer> & channels, bool includeParentChannels);

		unsigned int getInstalledPackageCount();
		        
		// videos
        ResultCode installVideo(std::string videoFile, const ws::entities::VideoEntity::pointer & videoEntity);
		ResultCode deleteVideo(unsigned long videoId);
        ResultCode deleteVideosInChannel(ws::entities::ChannelEntity::pointer & channel);

		bool isVideoInstalled(unsigned long videoId);
        ws::entities::VideoEntity::pointer getVideo(unsigned long videoId);
        bool getVideos(std::vector<ws::entities::VideoEntity::pointer> & videos);
        bool getVideos(long channelId, std::vector<ws::entities::VideoEntity::pointer> & videos);
        unsigned int getVideoChannels(unsigned long videoId, std::vector<ws::entities::ChannelEntity::pointer> & channels, bool includeParentChannels);

		unsigned int getInstalledVideoCount();

        // servers
        ResultCode installServer(const ws::entities::RemoteServerEntity::pointer & server);
        unsigned int getServers(std::vector<ws::entities::RemoteServerEntity::pointer> & servers);

    protected:
        Catalog();
        virtual bool init();
        virtual void onEvent(event::Event::pointer event);

	private:
		void * _catalog;
		
	};

}}
#endif
#endif
