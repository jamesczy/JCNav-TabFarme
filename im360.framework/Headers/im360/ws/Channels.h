/*
 *  Channels.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 05/27/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _ChannelsWs_h_
#define _ChannelsWs_h_

#include "im360/core/MarbleConfig.h"
#include "WsUtil.h"
#include "im360/net/Url.h"
#include "entities/ChannelEntity.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace ws {

    // DEPRECATED

    class I3DAPI Channels : virtual public core::I3dObject
	{
	public:
        typedef core::SharedPointer<Channels>::pointer pointer;

        static Channels::pointer create();

		virtual ~Channels();
        virtual std::string getClassName() const;

		int getLastResponseCode();

        entities::ChannelEntity::pointer loadChannel(long channelId, int packageLevel, int videoLevel, int * responseCode, int flags=LIVE_ONLY);
        
        unsigned int getChannelList(std::vector<entities::ChannelEntity::pointer> & list, bool asTreeRoot, int * responseCode, int flags=LIVE_ONLY);
        unsigned int getChannelChildren(std::vector<entities::ChannelEntity::pointer> & list, long parentId, int * responseCode, int flags=LIVE_ONLY);

        virtual void jsonPropertiesStart();
		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

    protected:
		Channels();
        virtual bool init();

	private:
		int _lastResponseCode;
        std::vector<entities::ChannelEntity::pointer> * _list;

        unsigned int query(std::string url, json::IJsonHandler & handler);

	};

}}
#endif
#endif
