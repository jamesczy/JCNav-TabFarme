//
//  PlayerController.h
//  libim360
//
//  Created by Ben Siroshton on 2/1/12.
//  Copyright (c) 2012 Immersive Media. All rights reserved.
//
#ifndef _libim360_PlayerController_h_
#define _libim360_PlayerController_h_

#include "RemoteController.h"
#include "im360/input/HumanInput.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace remote {

    class PlayerController : virtual public RemoteController
    {
    public:
        typedef core::SharedPointer<PlayerController>::pointer pointer;

        static PlayerController::pointer create();
        
        virtual ~PlayerController();
        virtual std::string getClassName() const;

        void tap(input::TapData d);
        void pinch(input::PinchData d);
        void pan(input::PanData d);

    protected:
        PlayerController();
        virtual bool init();
        
    };

}}
#endif
#endif

