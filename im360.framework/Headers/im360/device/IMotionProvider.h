//
//  IMotionProvider.h
//  libim360
//
//  Created by Ben Siroshton on 12/27/11.
//  Copyright (c) 2011 Immersive Media. All rights reserved.
//

#ifndef _libim360_IMotionProvider_h
#define _libim360_IMotionProvider_h

#include "IMotionListener.h"
#include "im360/core/Pointer.h"
#include "im360/player/PlayerConfig.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace device {

    class MotionFlags
    {
    public:
        enum
        {
            UNAVAILABLE = 0,
            ROTATIONS   = 1
        };
        
    private:
        MotionFlags(){} // don't allow creation of this class
    };
    
    /**
     * IMotionProvider implementations must follow these rules.
     *
     * Y Axis = Bottom of device to Top of device.
     * X Axis = Left of device to right of device.
     * Z Axis = Center of screen into screen.
     *
     * Rest Position = Screen facing user and Y Axis is perpendicular to the ground, Yaw, Pitch and Roll should be 0
     * in this position, with the exception being Yaw (see below).
     *     
     * Yaw = Y Axis, as device is rotated clockwise (looking at top of device) values increase. This value is
     * either a compass value or is an offset from 0 which is the devices initial start position.
     *
     * Pitch = X Axis, as the Top moves away from the user from the rest position this value will decrease.
     *
     * Roll = Z Axis, As the device is rotated clockwise from the rest position this value will increase.
     *
     */
    class I3DAPI IMotionProvider
    {
    public:
        typedef core::SharedPointer<IMotionProvider>::pointer pointer;

		virtual ~IMotionProvider(){}
		
        virtual int motionFlags() = 0;
        virtual bool isEnabled() = 0;
        virtual void setEnabled(bool enabled) = 0;
        
        virtual bool hasMotionData() = 0;
        virtual bool getMotionData(IMotionListener::MotionData & motionData) = 0;
        
        virtual void setMotionListener(IMotionListener * listener) = 0;
        
        virtual void update() = 0;
        
        virtual void setPlayerConfig(const player::PlayerConfig::weakPointer & config) = 0;
        virtual player::PlayerConfig::weakPointer getPlayerConfig() const = 0;
    };
    
}}
#endif
#endif
