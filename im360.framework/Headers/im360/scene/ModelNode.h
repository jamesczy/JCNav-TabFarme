#ifndef _ModelNode_h_
#define _ModelNode_h_

#include "Node.h"
#include "im360/mesh/MeshUtils.h"
#include "im360/render/RenderEffect.h"
#include "im360/math/Bounds3.h"
#include "IRenderable.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace scene {

	// TODO: replace this with a ModelComponent
    class I3DAPI ModelNode : virtual public scene::Node
	{
	public:
        typedef core::SharedPointer<ModelNode>::pointer pointer;

        static ModelNode::pointer create();
        
		virtual ~ModelNode();
        virtual std::string getClassName() const;

        mesh::MeshData::pointer getMeshData();
        virtual void setMeshData(mesh::MeshData::pointer mesh);

        render::RenderEffect::pointer getRenderEffect();
        virtual void setRenderEffect(render::RenderEffect::pointer effect);
		
		virtual void render();

		virtual void updateElementAttributeIndexes();
		
        texture::Texture::pointer findFirstTexture();
		
	protected:
        ModelNode();
        virtual bool init();

        virtual void onAddedToScene(core::WeakPointer< scene::Scene >::pointer scene);
        virtual void onRemovedFromScene(core::WeakPointer< scene::Scene >::pointer scene);

		virtual void updateBounds();
        
        render::RenderEffect::pointer	_effect;

	private:
        mesh::MeshData::pointer         _mesh;

        int _alphaLoc;
        int _alphaPass;
	};

}}
#endif
#endif
