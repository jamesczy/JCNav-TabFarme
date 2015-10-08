/*
 *  SimpleModelNode.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 2/14/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _SimpleModelNode_h_
#define _SimpleModelNode_h_

#include "ModelNode.h"
#include "IRenderable.h"
#include "im360/mesh/MeshUtils.h"
#include "im360/render/RenderPass.h"
#include "im360/core/Pointer.h"
#include "im360/component/CollisionObject.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace scene {

	class I3DAPI SimpleModelNode : virtual public ModelNode
	{
	public:
        typedef core::SharedPointer<SimpleModelNode>::pointer pointer;

		virtual ~SimpleModelNode();
        virtual std::string getClassName() const;
		
        virtual void setMeshData(mesh::MeshData::pointer mesh);
		
        virtual void setTexture(texture::Texture::pointer texture, bool autoCreateEffect=false);
        texture::Texture::pointer getTexture();

        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);

        void setCollisionEnabled(bool enabled);
        bool getCollisionEnabled();
		
        // Node
        virtual void render();
        virtual void update(const math::matrix & worldTransform);

	protected:
        SimpleModelNode();
        virtual bool init();

        virtual mesh::MeshData::pointer buildMesh() = 0;
        virtual render::RenderEffect::pointer createEffect();
		
		void updateMesh();
        void setDirty();

        virtual component::CollisionObject::pointer getShape();
        
	private:
        texture::Texture::pointer		_texture;
        mesh::MeshData::pointer         _mesh;
        bool                            _collisionEnabled;
        bool                            _isDirty;

	};
	
}}
#endif
#endif
