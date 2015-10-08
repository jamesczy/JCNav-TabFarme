/*
 *  Videos.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 05/31/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _VideosWs_h_
#define _VideosWs_h_

#include "im360/core/MarbleConfig.h"
#include "WsUtil.h"
#include "im360/net/Url.h"
#include "entities/VideoEntity.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace ws {

    namespace entities { class ChannelEntity; }

    // DEPRECATED

    class I3DAPI Videos : virtual public core::I3dObject
	{
	public:
        typedef core::SharedPointer<Videos>::pointer pointer;

        static Videos::pointer create();
        
		virtual ~Videos();
        virtual std::string getClassName() const;

        entities::VideoEntity::pointer loadVideo(long videoId, int * responseCode, int flags=0);

        int getChannelVideos(entities::ChannelEntity * channel, int flags=LIVE_ONLY);
        unsigned int getChannelVideos(std::vector<entities::VideoEntity::pointer> & list, long channelId, int * responseCode, int flags=LIVE_ONLY);

        virtual void jsonPropertiesStart();
		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

        static bool rememberVideo(std::string key, const entities::VideoEntity::pointer & Video);
        static entities::VideoEntity::pointer recallVideo(std::string key);
		static void forgetVideo(std::string key);

    protected:
		Videos();
        virtual bool init();
        
	private:
        std::vector<entities::VideoEntity::pointer> * _list;

		unsigned int query(std::string url);

	};

}}
#endif
#endif

