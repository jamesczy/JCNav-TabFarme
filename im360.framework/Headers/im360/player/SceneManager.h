//
//  SceneManager.h
//  libim360
//
//  Created by Ben Siroshton on 10/8/13.
//  Copyright (c) 2013 Immersive Ventures. All rights reserved.
//

#ifndef _SceneManager_h_
#define _SceneManager_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"
#include "im360/event/EventDispatcher.h"
#include "ISceneManager.h"

#ifdef __cplusplus

// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace player {

    class I3DAPI SceneManager : virtual public ISceneManager, virtual public event::EventDispatcher
    {
    public:
        typedef core::SharedPointer<SceneManager>::pointer pointer;

        virtual ~SceneManager();

    protected:
        SceneManager();
        virtual bool init();

    };

}}

#endif
#endif
