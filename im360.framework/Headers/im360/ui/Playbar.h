//
//  Playbar.h
//  im360lib
//
//  Created by Ben Siroshton on 02/25/13.
//  Copyright (c) 2013 ImmersiveMedia. All rights reserved.
//

#ifndef __im360lib__Playbar__
#define __im360lib__Playbar__

#include "i3d/scene/Node.h"
#include "i3d/scene/Scene.h"
#include "i3d/scene/Sprite.h"
#include "i3d/event/core/EventListener.h"
#include "i3d/input/HumanInput.h"

namespace I3d
{
    class Playbar : public Node, public EventListener
    {
    public:
        typedef SharedPointer<Playbar>::pointer pointer;
        
        static Playbar::pointer create();
        virtual ~Playbar();
        virtual std::string getClassName() const;

        bool onTap(TapData d);
        
        virtual void update(const I3dMath::matrix & worldTransform);
        
    protected:
        Playbar();
        virtual void init();
        
        virtual void onAddedToScene(WeakPointer<Scene>::pointer scene);

    private:
        virtual void onEvent(Event::pointer event);
        
        Sprite::pointer _bg;
        Sprite::pointer _seekBg;
        Sprite::pointer _seekFg;
        Sprite::pointer _play;
        Sprite::pointer _pause;

        struct Info
        {
            float   width;
            float   height;
            float   seekStartX;
            float   seekEndX;
            float   time;
            float   duration;
            bool    playing;
        } _info;
        
        void resize();
        void updateSeekBar();

    };
}

#endif 
