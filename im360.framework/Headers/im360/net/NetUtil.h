/*
 *  NetUtil.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 05/27/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _NetUtil_h_
#define _NetUtil_h_

#include "im360/core/MarbleConfig.h"
#include "Url.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace net {

	enum HttpMethod
	{
		HTTP_GET,
		HTTP_POST
	};

	enum HttpResultCode
	{
		HTTP_ACCEPTED = 202,
		HTTP_BAD_GATEWAY = 502,
		HTTP_BAD_METHOD = 405,
		HTTP_BAD_REQUEST = 400,
		HTTP_CLIENT_TIMEOUT = 408,
		HTTP_CONFLICT = 409,
		HTTP_CREATED = 201,
		HTTP_ENTITY_TOO_LARGE = 413,
		HTTP_FORBIDDEN = 403,
		HTTP_GATEWAY_TIMEOUT = 504,
		HTTP_GONE = 410,
		HTTP_INTERNAL_ERROR = 500,
		HTTP_LENGTH_REQUIRED = 411,
		HTTP_MOVED_PERM = 301,
		HTTP_MOVED_TEMP = 302,
		HTTP_MULT_CHOICE = 300,
		HTTP_NO_CONTENT = 204,
		HTTP_NOT_ACCEPTABLE = 406,
		HTTP_NOT_AUTHORITATIVE = 203,
		HTTP_NOT_FOUND = 404,
		HTTP_NOT_IMPLEMENTED = 501,
		HTTP_NOT_MODIFIED = 304,
		HTTP_OK = 200,
		HTTP_PARTIAL = 206,
		HTTP_PAYMENT_REQUIRED = 402,
		HTTP_PRECON_FAILED = 412,
		HTTP_PROXY_AUTH = 407,
		HTTP_REQ_TOO_LONG = 414,
		HTTP_RESET = 205,
		HTTP_SEE_OTHER = 303,
		HTTP_UNAUTHORIZED = 401,
		HTTP_UNAVAILABLE = 503,
		HTTP_UNSUPPORTED_TYPE = 415,
		HTTP_USE_PROXY = 305,
        HTTP_VERSION = 505
	};

    I3DAPI std::string httpGet(Url & url, int * responseCode=NULL);
    I3DAPI std::string httpPost(Url & url, std::string & requestData, int * responseCode=NULL);
    I3DAPI long httpDownload(Url & url, const std::string & toFile, int * responseCode=NULL);
    I3DAPI std::string httpRequest(HttpMethod method, Url & url, std::string & requestData, std::string dataEncoding, int * responseCode=0);
    
	I3DAPI std::string encodeBase64(const char * data, unsigned int dataLen);
    
    I3DAPI std::string unescape(std::string url);

}}
#endif
#endif
