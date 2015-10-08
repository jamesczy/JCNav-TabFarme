/*
 *  SphereSplitNode.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 1/24/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 * NOTE: Thanks to Andrew Myers for the description below!
 *
 * The stacking involves the following parameters:
 *
 * - Theta begin/end: which measure the angle around the horizontal, usually -180 to 180.
 * - Phi begin/end: which measure the angle around the vertical, depends on the camera.
 *
 *                                    phiBegin
 *                 +----------------------------------------------+
 *                 |                                              |
 *                 |                                              |
 *     thetaBegin  |                  Worldview                   | thetaEnd
 *                 |                                              |
 *                 |                                              |
 *                 +----------------------------------------------+
 *                                     phiEnd
 *
 * - OutputSegments: number of pieces the video is chopped into.
 * - OutputSegmentStacking: describes how the above pieces are put together.
 * - OutputSegmentType: describes the orientation of the stacking.
 *
 * Let's look at the stacking first.  Stacking can either be "Vertical" or "Horizontal":
 *
 *                          Vertical
 *             +--------------------------------+
 *             |                 S1             |
 *             +--------------------------------+
 *             |                 S2             |
 *             +--------------------------------+
 *             |          and so on...          |
 *             +--------------------------------+
 *
 *                        Horizontal
 *             +-------+------+-------+
 *             |       |      |       |
 *             |  S1   |  S2  |  and so on...
 *             |       |      |       |
 *             +-------+------+-------+
 *
 * The stacking type can either be "Horizontal" or "Horizontal Rotate."
 * Horizontal means that no rotation has been applied to the image segments.
 * If the rotation is present, then it is 90 degrees clockwise.
 *
 * For example, the Quattro running at 1920 x 1080 in panoramic mode will send you:
 *
 *     PhiBegin = 35
 *     PhiEnd = -36
 *     ThetaBegin = -180
 *     ThetaEnd = 180
 *     OutputSegments = 3
 *     OutputSegmentStacking = Horizontal
 *     OutputSegmentType = Horizontal Rotate
 *
 */

#ifndef _SphereSplitNode_h_
#define _SphereSplitNode_h_

#include "SimpleModelNode.h"
#include "im360/component/SphereShape.h"
#include "im360/core/Pointer.h"
#include "im360/math/Rect.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

    class I3DAPI SphereSplitNode : virtual public SimpleModelNode
    {
    public:
        typedef core::SharedPointer<SphereSplitNode>::pointer pointer;

        enum StackingType
        {
            HORIZONTAL, // segments are from left to right
            VERTICAL    // segments are from top to bottom
        };

        enum SegmentOrientation
        {
            ROT_0 = 0,  // segments not rotated
            ROT_90 = 90 // segments rotated 90 degress clockwise
        };

        static SphereSplitNode::pointer create();
        static SphereSplitNode::pointer create(float radius, unsigned int slices, unsigned int stacks, float phiBegin, float phiEnd, float thetaBegin, float thetaEnd,
                                                unsigned int segmentCount, StackingType stackingType, SegmentOrientation segmentOrientation, bool asInside=false, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);

        virtual std::string getClassName() const;

        virtual ~SphereSplitNode();

        virtual void setMesh(float radius, unsigned int slices, unsigned int stacks, float phiBegin, float phiEnd, float thetaBegin, float thetaEnd,
                             unsigned int segmentCount, StackingType stackingType, SegmentOrientation segmentOrientation, bool asInside=false, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);

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

        StackingType getStackingType();
        void setStackingType(StackingType type);

        SegmentOrientation getSegmentOrientation();
        void setSegmentOrientation(SegmentOrientation orientation);

        bool getAsInside();
        void setAsInside(bool asInside);

        math::Rect<float> getUVArea();
        void setUVArea(math::Rect<float> uvArea);

        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

    protected:
        SphereSplitNode();        
        virtual void init(float radius=1.f, unsigned int slices=20, unsigned int stacks=20, float phiBegin=45.f, float phiEnd=-45.f, float thetaBegin=-180.f, float thetaEnd=180.f,
                  unsigned int segmentCount=2, SphereSplitNode::StackingType stackingType=SphereSplitNode::VERTICAL, SphereSplitNode::SegmentOrientation segmentOrientation=SphereSplitNode::ROT_0,
                  bool asInside=false, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);

        void setBuildProperties(float radius, unsigned int slices, unsigned int stacks, float phiBegin, float phiEnd, float thetaBegin, float thetaEnd,
                                unsigned int segmentCount, StackingType stackingType, SegmentOrientation segmentOrientation, bool asInside=false, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);

        virtual mesh::MeshData::pointer buildMesh();
        virtual component::CollisionObject::pointer getShape();
        
        struct
        {
            float radius;
            unsigned int slices;
            unsigned int stacks;
            float phiBegin;
            float phiEnd;
            float thetaBegin;
            float thetaEnd;
            unsigned int segmentCount;
            StackingType stackingType;
            SegmentOrientation segmentOrientation;
            bool asInside;
            float u1, v1, u2, v2;
        } _build;

        component::SphereShape::pointer    _sphereShape;

        virtual void updateBounds();

        void setIndices(mesh::IndexBuffer & indexBuffer, int startVertex, int rows, int cols);
    };

}}
#endif
#endif
