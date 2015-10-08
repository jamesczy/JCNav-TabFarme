//
//  CatalogEntry.h
//  libim360
//
//  Created by Ben Siroshton on 6/6/11.
//  Copyright 2011 Immersive Ventures. All rights reserved.
//
#ifndef _CatalogEntry_h_
#define _CatalogEntry_h_

#include <string>

#include "MarbleConfig.h"
#include "im360/ws/entities/PackageEntity.h"

namespace I3d
{

    struct CatalogEntry
    {
        unsigned long	packageId;
        std::string		packageName;
        std::string		packageThumb;
        std::string		packageThumb2x;
        std::string		packageDescription;
        std::string     packageStart;
        
        std::string     group;
    };

}

#endif
