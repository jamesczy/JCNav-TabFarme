/*
 *  SourceEntity.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 08/24/12.
 *  Copyright 2012 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _SourceEntity_h_
#define _SourceEntity_h_

#include "im360/core/MarbleConfig.h"
#include "IEntity.h"
#include "im360/core/Pointer.h"
#include "PackageEntity.h"
#include "VideoEntity.h"
#include "ThumbnailEntity.h"
#include "SourceMetaEntity.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI SourceEntity : virtual public IEntity
    {
    public:
        typedef core::SharedPointer<SourceEntity>::pointer pointer;

        long        sourceId;
        std::string sourceName;
        std::string sourceDescription;
        std::string sourceKeywords;
        std::string sourceAddress;
        std::string sourceCity;
        std::string sourceState;
        std::string sourceZip;
        std::string sourceCountry;
        double      sourceLatitude;
        double      sourceLongitude;
        float       sourceFramesFps;
        float       sourceCameraOffsetHeading;
        std::string sourceDateAdded;
        std::string sourceDateUpdated;

        std::vector<PackageEntity::pointer> packages;
        std::vector<VideoEntity::pointer> videos;
        std::vector<ThumbnailEntity::pointer> thumbnails;
        std::vector<SourceMetaEntity::pointer> meta;

        static SourceEntity::pointer create();
        
        virtual ~SourceEntity();
        virtual std::string getClassName() const;

        virtual void clear();

        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

        virtual std::string getJson() const;
        virtual void parseJson(std::string json);
        
    protected:
        SourceEntity();
        virtual bool init();

    };

}}}
#endif
#endif
