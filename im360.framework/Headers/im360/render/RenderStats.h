/*
 *  RenderStats.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/08/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef _RenderStats_h_
#define _RenderStats_h_

#include "im360/core/MarbleConfig.h"
#include "im360/util/Singleton.h"
#include "im360/core/Pointer.h"
#include "im360/util/Timer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace player { class Player; }
namespace render {    

    class I3DAPI RenderStats : virtual public core::I3dObject
    {
    friend class player::Player;
    public:
        typedef core::SharedPointer<RenderStats>::pointer pointer;

        static RenderStats::pointer create();
        virtual ~RenderStats();
        virtual std::string getClassName() const;

        float getFps();
        float getAverageFps();

        unsigned long getLastFrameTimeMs();
        float getLastFrameTimeSec();

        unsigned long getAverageFrameTimeMs();
        float getAverageFrameTimeSec();

        unsigned long getTimeSinceControlMs();
        float getTimeSinceControlSec();

        void reset();
        
    protected:
        RenderStats();
        virtual bool init();
        
    private:
        float           _fps;
        float           _averageFps;
        unsigned long   _lastFrameTime;
        unsigned long   _averageFrameTime;
        util::Timer     _frameTimer;
        util::Timer     _controlTimer;

        void tickFrame();
        void resetControlTime();
    };

}}
#endif
#endif

