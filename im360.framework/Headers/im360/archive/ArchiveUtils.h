/*
 *  ArchiveUtils.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 2/24/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _ArchiveUtils_h_
#define _ArchiveUtils_h_

#include "im360/core/MarbleConfig.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace archive {

    enum ArchiveType
    {
        ARCHIVE_UNKNOWN,
        ARCHIVE_GZIP,
        ARCHIVE_ZIP,
        ARCHIVE_I3P
    };

    I3DAPI ArchiveType getArchiveType(std::string file);
    I3DAPI bool isKnownArchive(std::string file);

    I3DAPI bool extractGzip(std::string inFile, std::string outFile);
    I3DAPI bool extractZip(std::string inFile, std::string outDir);
    I3DAPI bool extractI3p(std::string inFile, std::string outDir, std::string password="");

    I3DAPI unsigned int getCrc32(void * data, size_t dataLen);

}}
#endif
#endif
