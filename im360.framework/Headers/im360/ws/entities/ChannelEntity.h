/*
 *  ChannelEntity.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 05/27/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _ChannelEntity_h_
#define _ChannelEntity_h_

#include "im360/core/MarbleConfig.h"
#include "IEntity.h"
#include "im360/core/Pointer.h"
#include "SourceEntity.h"
#include "PackageEntity.h"
#include "VideoEntity.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI ChannelEntity : virtual public IEntity
	{
	public:
        typedef core::SharedPointer<ChannelEntity>::pointer pointer;

		long		channelId;
		std::string	channelName;
		bool		channelActive;
        bool        channelPublic;
		std::string	channelDateAdded;
		std::string	channelDateUpdated;
		long		channelParentId;
        std::string channelThumbUrl;

        std::vector<ChannelEntity::pointer> channels;
        std::vector<SourceEntity::pointer> sources;
        std::vector<PackageEntity::pointer> packages;
        std::vector<VideoEntity::pointer> videos;
    
        static ChannelEntity::pointer create();
        
		virtual ~ChannelEntity();
        virtual std::string getClassName() const;

		virtual void clear();

        virtual void jsonPropertiesStart();
		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

		virtual std::string getJson() const;
		virtual void parseJson(std::string json);

		SourceEntity::pointer findSourceById(long sourceId);
		void buildSources();

    protected:
		ChannelEntity();
        virtual bool init();
	};

}}}
#endif
#endif
