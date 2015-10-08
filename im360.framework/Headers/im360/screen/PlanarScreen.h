/*
 *  PlanarScreen
 *  libmarble360
 *
 *  Created by Ben Siroshton on 08/05/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _PlanarScreen_h_
#define _PlanarScreen_h_

#include "ScreenBase.h"
#include "im360/scene/PlaneNode.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace screen {
        
        class I3DAPI PlanarScreen : virtual public ScreenBase
        {
        public:
            typedef core::SharedPointer<PlanarScreen>::pointer pointer;
            
            static PlanarScreen::pointer create();
            
            virtual ~PlanarScreen();
            virtual std::string getClassName() const;
            
            core::FillModeType::Type getFillMode();
            void setFillMode(core::FillModeType::Type fillMode);
            
            // ScreenBase
            virtual void setTexture(texture::Texture::pointer texture);
            virtual scene::ModelNode::pointer getModelNode();

            // Node
            virtual void update(const math::matrix & worldTransform);
            
        protected:
            PlanarScreen();
            virtual bool init();
            
        private:
            core::FillModeType::Type    _fillMode;
            scene::PlaneNode::pointer   _mesh;

        };
        
    }}
#endif
#endif
