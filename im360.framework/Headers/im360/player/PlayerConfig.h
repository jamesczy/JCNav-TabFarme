//
//  PlayerConfig.h
//  libim360
//
//  Created by Ben Siroshton on 8/27/13.
//  Copyright (c) 2013 Immersive Ventures. All rights reserved.
//

#ifndef __libim360__PlayerConfig__
#define __libim360__PlayerConfig__

#include "im360/core/MarbleConfig.h"
#include "im360/device/DeviceInfo.h"
#include "im360/render/RenderState.h"
#include "im360/render/RenderStats.h"

namespace im360 {
namespace player {

    class Player;
    
    class I3DAPI PlayerConfig : public core::I3dObject
    {
    friend class Player;
    public:
        typedef core::SharedPointer<PlayerConfig>::pointer pointer;
        typedef core::WeakPointer<PlayerConfig>::pointer weakPointer;
        
        virtual ~PlayerConfig();
        virtual std::string getClassName() const;
        
        device::DeviceInfo::pointer getDeviceInfo() const;
        render::RenderState::pointer getRenderState() const;
        render::RenderStats::pointer getRenderStats() const;

    protected:
        static PlayerConfig::pointer create();
        PlayerConfig();
        virtual bool init();
        
    private:
        device::DeviceInfo::pointer     _deviceInfo;
        render::RenderState::pointer    _renderState;
        render::RenderStats::pointer    _renderStats;

    };
    
}}

#endif /* defined(__libim360__PlayerConfig__) */
