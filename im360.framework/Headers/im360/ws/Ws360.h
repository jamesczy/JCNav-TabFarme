/*
 *  Ws360.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 08/24/12.
 *  Copyright 2012 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _Ws360_h_
#define _Ws360_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/I3dObject.h"
#include "WsUtil.h"
#include "im360/net/Url.h"
#include "im360/net/NetUtil.h"
#include "im360/core/Pointer.h"
#include "im360/json/IJsonHandler.h"
#include "im360/json/JsonUtils.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {

    template <class T> class Ws360 : virtual public json::IJsonHandler
    {
    public:
        typedef std::tr1::shared_ptr<T> EntityPointer;
        
        Ws360() : _lastResponseCode(0)
        {
            _rootUrl = ws::getServerUrl();
        }

        Ws360(std::string rootUrl) : _rootUrl(rootUrl), _lastResponseCode(0)
        {
        }

        virtual ~Ws360()
        {
        }

        std::string getRootUrl()
        {
            return _rootUrl;
        }

        void setRootUrl(std::string rootUrl)
        {
            _rootUrl = rootUrl;
        }

        int getLastResponseCode()
        {
            return _lastResponseCode;
        }
       
        unsigned int loadList(std::vector<EntityPointer> & list, std::string request, int flags=LIVE_ONLY)
        {
            return loadListFromUrl(list, _rootUrl + request, flags);
        }
        
        unsigned int loadListFromUrl(std::vector<EntityPointer> & list, std::string url, int flags=LIVE_ONLY)
        {        
            int count = list.size();

            _list = &list;
            _entity = EntityPointer();
            _lastResponseCode = httpGet(url, *this, flags);

            return list.size()-count;
        }

        EntityPointer loadEntity(std::string request, int flags=LIVE_ONLY)
        {
            return loadEntityFromUrl(_rootUrl + request, flags);
        }

        EntityPointer loadEntityFromUrl(std::string url, int flags=LIVE_ONLY)
        {
            _entity = T::create();
            _list = NULL;
            _lastResponseCode = httpGet(url, *_entity, flags);
            
            if( _lastResponseCode!=net::HTTP_OK )
            {
                return EntityPointer();
            }
            
            return _entity;
        }

        virtual void jsonPropertiesStart()
        {

        }

        virtual void handleJsonNode(std::string name, json::JsonInfo & json)
        {
            if( !_list ) return;

            if( json::getNodeType(json.node)!=json::ARRAY ) return;

            unsigned int len = json::getArraySize(json.node);
            for(unsigned int i=0;i<len;i++)
            {
                json::JsonInfo info;
                info.node = json::getArrayNode(json.node, i);

                EntityPointer entity = T::create();
                json::parseJson(info, *entity);
                _list->push_back(entity);
            }
        }

        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json)
        {
            //I3d_debug(im360::util::DBG_INFO, "channels.json prop: %s=%s", name.c_str(), value.c_str());
        }

        virtual void jsonPropertiesEnd()
        {

        }

    private:
        std::string                     _rootUrl;
        std::vector<EntityPointer> *    _list;
        EntityPointer                   _entity;
        int                             _lastResponseCode;

    };

}}
#endif
#endif
