/*
 *  IVideoServer.h
 *  libim360
 *
 *  Created by Ben Siroshton on 1/25/12.
 *  Copyright 2012 Immersive Ventures. All rights reserved.
 *
 */
#ifndef libim360_IVideoServer_h_
#define libim360_IVideoServer_h_

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace video {

    class IVideoServer
    {
    public:
        typedef core::SharedPointer<IVideoServer>::pointer pointer;

        struct StreamSettings
        {
            std::string     protocol;
            unsigned int    port;
            unsigned int    width;
            unsigned int    height;
            float           fps;
            unsigned int    bitRate;

            StreamSettings(unsigned int width, unsigned int height)
            {
                protocol = "rtsp";
                port = 5544;
                this->width = width;
                this->height = height;
                fps = 16.f;
                bitRate = 2048;
            }
        };

        virtual ~IVideoServer(){}
        virtual bool startStream(const StreamSettings & options) = 0;
        virtual bool isServing() = 0;
        virtual void stop() = 0;

        virtual const StreamSettings & getSettings() = 0;

        virtual unsigned char * lockBuffer() = 0;
        virtual void unlockBuffer() = 0;
        virtual int getBufferSize() = 0;

        virtual void copyFromGlFrameBuffer() = 0;
    };

}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
// ... functions ...
#ifdef __cplusplus
}
#endif

#endif
