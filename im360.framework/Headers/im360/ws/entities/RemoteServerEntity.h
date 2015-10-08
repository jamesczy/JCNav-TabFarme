/*
 *  RemoteServerEntity.h
 *  libim360
 *
 *  Created by Ben Siroshton on 01/31/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef libim360_RemoteServerEntity_h_
#define libim360_RemoteServerEntity_h_

#include "im360/core/MarbleConfig.h"
#include "IEntity.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI RemoteServerEntity : virtual public IEntity
    {
    public:
        typedef core::SharedPointer<RemoteServerEntity>::pointer pointer;

        std::string     host;
        unsigned int    port;

        static RemoteServerEntity::pointer create();
        
        virtual ~RemoteServerEntity();
        virtual std::string getClassName() const;

        virtual void clear();

        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

        virtual std::string getJson() const;
        virtual void parseJson(std::string json);
        
    protected:
        RemoteServerEntity();
        virtual bool init();
        
    };

}}}
#endif
#endif

