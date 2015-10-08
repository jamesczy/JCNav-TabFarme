/*
 *  ScreenBase
 *  libmarble360
 *
 *  Created by Ben Siroshton on 08/05/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _ScreenBase_h_
#define _ScreenBase_h_

#include "IScreen.h"
#include "im360/json/JsonStringBuilder.h"
#include "im360/scene/ModelNode.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
    namespace screen {
        
        class I3DAPI ScreenBase : virtual public IScreen
        {
        public:
            typedef core::SharedPointer<ScreenBase>::pointer pointer;
            
            virtual ~ScreenBase();
            virtual std::string getClassName() const;
            
            virtual void setTexture(texture::Texture::pointer texture);
            virtual texture::Texture::pointer getTexture();
            
            virtual void setPlayerConfig(const player::PlayerConfig::weakPointer & config);
            virtual player::PlayerConfig::weakPointer getPlayerConfig() const;
            
            virtual scene::ModelNode::pointer getModelNode() = 0;

        protected:
            ScreenBase();
            
            texture::Texture::pointer           _texture;
            player::PlayerConfig::weakPointer   _playerConfig;
            
            virtual void innerJson(json::JsonStringBuilder & json) const;
        };
        
    }}
#endif
#endif
