//
//  WsUtil.h
//  libim360
//
//  Created by Ben Siroshton on 5/31/11.
//  Copyright 2011 Immersive Ventures. All rights reserved.
//

#ifndef _WsUtil_h_
#define _WsUtil_h_

#include "im360/core/MarbleConfig.h"
#include "im360/json/IJsonHandler.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {

    class EntityLevel
    {
    public:
        enum Level
        {
            NONE,
            ID,
            FULL
        };
    private:
        EntityLevel(){}
    };

    enum QueryFlags
    {
        LIVE_ONLY = 0,
        USE_CACHE_UPFRONT = 0x01,
        USE_CACHE_ONLY = 0x02,
        USE_CACHE_ON_FAILURE = 0x04,
        DONT_CACHE = 0x08
    };

    I3DAPI std::string getServerUrl(std::string service="");
    I3DAPI std::string getSignedServerUrl(std::string service="", std::string method = "GET", unsigned int expires = 5);
	I3DAPI unsigned int getExpires(unsigned int minutesFromNow);
	I3DAPI std::string getSignedUrl(std::string url, std::string method, unsigned int expires, std::string accessKey, std::string secretKey);
	I3DAPI std::string getSignature(std::string resource, std::string method, unsigned int expires, std::string secretKey);
    I3DAPI int httpGet(std::string url, json::IJsonHandler & handler, int flags=LIVE_ONLY);
    I3DAPI int httpPost(std::string url, std::string & request, json::IJsonHandler & handler, int flags=LIVE_ONLY);
    I3DAPI std::string constructIdPath(long id);

}}
#endif
#endif
