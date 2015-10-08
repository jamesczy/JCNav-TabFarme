/*
 *  MarbleTypes.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 12/10/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _MarbleTypes_h_
#define _MarbleTypes_h_

#include "MarbleDefines.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace core {

    class I3DAPI MediaType
    {
    public:
        enum Type
        {
            UNKNOWN,
            VIDEO,
            IMAGE,
            AUDIO,
            PLAYER,
            SCENE
        };

    private:
        MediaType(){} // prevent construction of this class
    };

    class I3DAPI FillModeType
    {
    public:
        enum Type
        {
            ASPECT_FIT,
            ASPECT_FILL,
            STRETCH_FILL,
            ORIGINAL
        };
        
    private:
        FillModeType(){} // prevent construction of this class
    };
    
    class I3DAPI ImageFormat
    {
    public:
        enum Format
        {
            UNKNOWN,
            JPG,
            BMP,
            PNG
        };

    private:
        ImageFormat(){} // prevent construction of this class
    };

    class I3DAPI MediaProjection
    {
    public:
        enum Projection
        {
            PLANAR,
            EQUIRECTANGULAR,
            CUBICAL
        };
    private:
        MediaProjection(){} // prevent construction of this class
    };

}}
#endif
#endif
