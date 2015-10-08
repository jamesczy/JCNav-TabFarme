/*
 *  SphereNode.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 2/14/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _SphereNode_h_
#define _SphereNode_h_

#include "SimpleModelNode.h"
#include "im360/component/SphereShape.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

	class I3DAPI SphereNode : virtual public SimpleModelNode
	{
	public:
        typedef core::SharedPointer<SphereNode>::pointer pointer;

        static SphereNode::pointer create();
        static SphereNode::pointer create(float radius, unsigned int slices, unsigned int stacks, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);
        
		virtual ~SphereNode();
        virtual std::string getClassName() const;
		
		virtual void setMesh(float radius, unsigned int slices, unsigned int stacks, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);
				
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
		virtual void jsonPropertiesEnd();
	
	protected:
        SphereNode();
        void init(float radius=1.f, unsigned int slices=20, unsigned int stacks=20, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);

		void setBuildProperties(float radius, unsigned int slices, unsigned int stacks, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);
		
        virtual mesh::MeshData::pointer buildMesh();
        virtual component::CollisionObject::pointer getShape();
        
		struct{
			float radius;
			float slices;
			float stacks;
			float u1;
			float v1;
			float u2;
			float v2;
		} _build;

        component::SphereShape::pointer    _sphereShape;

		virtual void updateBounds();
	};
	
}}
#endif
#endif
