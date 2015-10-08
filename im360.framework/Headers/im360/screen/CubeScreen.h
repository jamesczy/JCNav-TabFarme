/*
 *  CubeScreen
 *  libmarble360
 *
 *  Created by Ben Siroshton on 08/05/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _CubeScreen_h_
#define _CubeScreen_h_

#include "ScreenBase.h"
#include "im360/scene/CubeNode.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
    namespace screen {
        
        class I3DAPI CubeScreen : virtual public ScreenBase
        {
        public:
            typedef core::SharedPointer<CubeScreen>::pointer pointer;
            
            static CubeScreen::pointer create();
            
            virtual ~CubeScreen();
            virtual std::string getClassName() const;
            
            // ScreenBase
            virtual void setTexture(texture::Texture::pointer texture);
            virtual scene::ModelNode::pointer getModelNode();

        protected:
            CubeScreen();
            virtual bool init();
            
        private:
            scene::CubeNode::pointer    _mesh;
            
        };
        
    }}
#endif
#endif
