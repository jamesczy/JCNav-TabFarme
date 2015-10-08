/*
 *  IJsonHandler.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 2/11/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _IJsonHandler_h_
#define _IJsonHandler_h_

#include "im360/core/MarbleDefines.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace json {

    typedef void * JsonNode;

    struct JsonInfo
    {
        std::string url;
        std::string urlRoot;
        JsonNode	node;
        JsonNode	parent;
    };

    class I3DAPI IJsonHandler
    {
    public:
        typedef core::SharedPointer<IJsonHandler>::pointer pointer;

        virtual void jsonPropertiesStart() = 0;
        virtual void handleJsonNode(std::string name, JsonInfo & json) = 0;
        virtual void handleJsonProperty(std::string name, std::string value, JsonInfo & json) = 0;
        virtual void jsonPropertiesEnd() = 0;

    };

}}
#endif
#endif
