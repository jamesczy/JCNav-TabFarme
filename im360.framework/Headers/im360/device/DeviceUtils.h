//
//  DeviceUtils.h
//  libim360
//
//  Created by Ben Siroshton on 12/27/11.
//  Copyright (c) 2011 Immersive Ventures. All rights reserved.
//

#ifndef _libim360_DeviceUtils_h
#define _libim360_DeviceUtils_h

#include "IMotionProvider.h"
#include "im360/core/MarbleConfig.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace device {
    
    I3DAPI IMotionProvider::pointer getMotionProviderInstance();
    
}}
#endif
#endif
