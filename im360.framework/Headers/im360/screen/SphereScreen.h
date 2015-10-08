/*
 *  SphereScreen
 *  libmarble360
 *
 *  Created by Ben Siroshton on 08/05/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _SphereScreen_h_
#define _SphereScreen_h_

#include "ScreenBase.h"
#include "im360/scene/SphereSplitNode.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
    namespace screen {
        
        class I3DAPI SphereScreen : virtual public ScreenBase
        {
        public:
            typedef core::SharedPointer<SphereScreen>::pointer pointer;
            
            static SphereScreen::pointer create();
            
            virtual ~SphereScreen();
            virtual std::string getClassName() const;
            
            bool getAutoAdjustSphere();
            void setAutoAdjustSphere(bool enabled);            
            
            float getRadius();
            void setRadius(float radius);

            unsigned int getSlices();
            void setSlices(unsigned int slices);

            unsigned int getStacks();
            void setStacks(unsigned int stacks);

            float getPhiBegin();
            void setPhiBegin(float phi);

            float getPhiEnd();
            void setPhiEnd(float phi);

            float getThetaBegin();
            void setThetaBegin(float theta);

            float getThetaEnd();
            void setThetaEnd(float theta);

            unsigned int getSegmentCount();
            void setSegmentCount(unsigned int segments);

            scene::SphereSplitNode::StackingType getStackingType();
            void setStackingType(scene::SphereSplitNode::StackingType type);

            scene::SphereSplitNode::SegmentOrientation getSegmentOrientation();
            void setSegmentOrientation(scene::SphereSplitNode::SegmentOrientation orientation);

            bool getAsInside();
            void setAsInside(bool asInside);

            math::Rect<float> getUVArea();
            void setUVArea(math::Rect<float> uvArea);

            // ScreenBase
            virtual void setTexture(texture::Texture::pointer texture);
            scene::ModelNode::pointer getModelNode();
            
        protected:
            SphereScreen();
            virtual bool init();

        private:
            bool                                _autoAdjustSphere;
            scene::SphereSplitNode::pointer     _mesh;

        };
        
    }}
#endif
#endif
