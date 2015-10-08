/*
 *  PlaneNode.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 11/30/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _PlaneNode_h_
#define _PlaneNode_h_

#include "SimpleModelNode.h"
#include "im360/component/BoxShape.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

    class I3DAPI PlaneNode : virtual public SimpleModelNode
	{
	public:
        static const int CF_DISABLE_DEPTH_TEST = 1;
        
        typedef core::SharedPointer<PlaneNode>::pointer pointer;

        static PlaneNode::pointer create();
        static PlaneNode::pointer create(float width, float height);
        static PlaneNode::pointer create(const std::string & texture, ProjectionMode projection, int creationFlags=0);
        static PlaneNode::pointer create(const std::string & texture, im360::math::vec3 pos=im360::math::vec3(0.f,0.f,0.f), float scale=1.f, ProjectionMode projection=PROJECTION_VIEWPLANE, int creationFlags=0);

        virtual ~PlaneNode();
        virtual std::string getClassName() const;
		
		void setTextureAspectEnabled(bool enabled);
		bool getTextureAspectEnabled();
		
		void sizeToTextureAspect(float scale=1.f);
        virtual void setTexture(texture::Texture::pointer texture, bool autoCreateEffect=false);
		void updateSizeFromTexture();
		      
		void setSize(float width, float height);
        
        float getWidth();
        float getHeight();

        void setCollisionBoundsScale(float scale);
        float getCollisionBoundsScale();
		
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
		virtual void jsonPropertiesEnd();

	protected:
        PlaneNode();
        virtual void init(float width=1.f, float height=1.f, float scale=1.f, bool sizeToAspect=true);

        virtual mesh::MeshData::pointer buildMesh();
        virtual component::CollisionObject::pointer getShape();
        
		struct{
			float	width;
			float	height;
			float	scale;
			bool	sizeToAscpect;			
		} _build;
		
		virtual void updateBounds();

	private:
        component::BoxShape::pointer	_boxShape;
        float                           _collisionBoundsScale;

	};
	
}}
#endif
#endif
