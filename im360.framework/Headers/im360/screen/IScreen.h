/*
 *  IScreen
 *  libmarble360
 *
 *  Created by Ben Siroshton on 08/05/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _IScreen_h_
#define _IScreen_h_

#include "im360/scene/Node.h"
#include "im360/texture/Texture.h"
#include "im360/player/PlayerConfig.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
    namespace screen {
        
        class I3DAPI IScreen : virtual public scene::Node
        {
        public:
            typedef core::SharedPointer<IScreen>::pointer pointer;
                        
            virtual ~IScreen();
            
            virtual void setTexture(texture::Texture::pointer texture) = 0;
            virtual texture::Texture::pointer getTexture() = 0;
            
            virtual void setPlayerConfig(const player::PlayerConfig::weakPointer & config) = 0;
            virtual player::PlayerConfig::weakPointer getPlayerConfig() const = 0;
            
        protected:
            IScreen();
            
        };
        
    }}
#endif
#endif
