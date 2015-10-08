/*
 *  MediaUtils.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 11/9/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */

#ifndef _MediaUtils_h_
#define _MediaUtils_h_

#include "im360/core/MarbleConfig.h"
#include "im360/video/IVideo.h"
#include "im360/video/IVideoServer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace media {

    I3DAPI std::string findAudioForVideo(std::string file);
    I3DAPI core::MediaType::Type getMediaType(std::string fileName);
    I3DAPI bool isMediaLive(std::string fileName);
    I3DAPI core::ImageFormat::Format getImageFormatFromFile(std::string fileName);
    I3DAPI std::string getExtensionForFormat(core::ImageFormat::Format format);
    I3DAPI bool isRemotePath(std::string path);

    I3DAPI video::IVideo::pointer createVideo(std::string url);

    I3DAPI video::IVideoServer::pointer getVideoServerInstance();

}}
#endif
#endif
