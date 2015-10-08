/*
 *  JsonUtils.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 2/11/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _JsonUtils_h_
#define _JsonUtils_h_

#include "IJsonHandler.h"
#include "im360/math/MathTypes.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace json {

    enum NodeType
    {
        UNKNOWN,
        ARRAY,
        STRING,
        NUMBER,
        BOOL,
        NODE
    };

    I3DAPI NodeType getNodeType(JsonNode node);

    I3DAPI std::string getName(JsonNode node);
    I3DAPI std::string getString(JsonNode node);
    I3DAPI bool getBool(JsonNode node);
    I3DAPI float getFloat(JsonNode node);
    I3DAPI double getDouble(JsonNode node);
    I3DAPI long getLong(JsonNode node);
    I3DAPI int getInt(JsonNode node);

    I3DAPI unsigned int getArraySize(JsonNode node);
    I3DAPI JsonNode getArrayNode(JsonNode node, unsigned int index);

    I3DAPI bool parseJsonFile(std::string url, IJsonHandler & handler);
    I3DAPI bool parseJsonString(std::string json, IJsonHandler & handler);
    I3DAPI void parseJson(JsonInfo & info, IJsonHandler & handler);

    I3DAPI std::string unescape(std::string value);
    
    I3DAPI std::string findValueForJsonProperty(const JsonInfo & info, std::string propertyName);
    I3DAPI std::string findValueForJsonProperty(const JsonNode & node, std::string propertyName);
    I3DAPI JsonNode findNodeForJsonProperty(const JsonInfo & info, std::string propertyName);
    I3DAPI JsonNode findNodeForJsonProperty(const JsonNode & node, std::string propertyName);

    I3DAPI std::string fromVec2(const math::vec2 & value);
    I3DAPI math::vec2 toVec2(std::string str, bool * parsedOk = NULL);
    I3DAPI math::vec2 toVec2(const JsonNode & node, bool * parsedOk = NULL);

    I3DAPI std::string fromVec3(const math::vec3 & value);
    I3DAPI math::vec3 toVec3(std::string str, bool * parsedOk = NULL);
    I3DAPI math::vec3 toVec3(const JsonNode & node, bool * parsedOk = NULL);

    I3DAPI std::string fromMatrix(const math::matrix & value);
    I3DAPI math::matrix toMatrix(std::string str, bool * parsedOk = NULL);
    I3DAPI math::matrix toMatrix(const JsonNode & node, bool * parsedOk = NULL);

}}
#endif
#endif
