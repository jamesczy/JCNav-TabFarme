//
//  SourceMetaEntity.h
//  libim360
//
//  Created by Ben Siroshton on 3/1/13.
//  Copyright (c) 2013 Immersive Ventures. All rights reserved.
//

#ifndef __libim360__SourceMetaEntity__
#define __libim360__SourceMetaEntity__

#include "im360/core/MarbleConfig.h"
#include "IEntity.h"
#include "im360/core/Pointer.h"
#include "PackageEntity.h"
#include "VideoEntity.h"
#include "ThumbnailEntity.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI SourceMetaEntity : virtual public IEntity
    {
    public:
        typedef core::SharedPointer<SourceMetaEntity>::pointer pointer;
        
        long        metaId;
        long        sourceId;
        long        metaTypeId;
        std::string typeName;
        std::string metaFile;
        long        metaFilesize;
        std::string metaPath;
        std::string metaUrl;
        std::string metaData;
        std::string metaDateAdded;
        std::string metaDateUpdated;
        
        static SourceMetaEntity::pointer create();
        
        virtual ~SourceMetaEntity();
        virtual std::string getClassName() const;
        
        virtual void clear();
        
        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();
        
        virtual std::string getJson() const;
        virtual void parseJson(std::string json);

    protected:
        SourceMetaEntity();
        virtual bool init();
    };
    
}}}
#endif
#endif /* defined(__libim360__SourceMetaEntity__) */
