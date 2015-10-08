/*
 *  RenderPass.h
 *  marble360
 *
 *  Created by Ben Siroshton on 11/9/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _RenderPass_h_
#define _RenderPass_h_

#include "RenderProperty.h"
#include "ShaderProgram.h"
#include "im360/texture/Texture.h"
#include "im360/math/MathUtils.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace render {

	class I3DAPI RenderPass : virtual public core::I3dObject
	{
	public:
        typedef core::SharedPointer<RenderPass>::pointer pointer;

		static RenderPass::pointer create();
        
		virtual ~RenderPass();
        virtual std::string getClassName() const;
		
        ShaderProgram::pointer getProgram();
        void setProgram(ShaderProgram::pointer program);

        void setTexture(unsigned int index, texture::Texture::pointer texture, int shaderLocation=-1);
        texture::Texture::pointer getTexture(unsigned int index);
        int getTextureIndex(texture::Texture::pointer texture);
		unsigned int getTextureCount();
		unsigned int getMaxTextureCount();
		
        void addProperty(IRenderPropertyBase::pointer property);
        IRenderPropertyBase::pointer getPropertyByIndex(unsigned int index);
        IRenderPropertyBase::pointer getPropertyByName(std::string name);
        int getPropertyIndex(IRenderPropertyBase::pointer property);
        void removeProperty(IRenderPropertyBase::pointer property);
		void removePropertyByName(std::string name);
		unsigned int getPropertyCount();

        void setTransform(const math::matrix & m);
        math::matrix getTransform();

		void setSceneTransformLocation(int uniformVariableLocation);
        void setWorldTransform(const math::matrix & m);

        //void apply();
        bool apply(const math::matrix & projection);

    protected:
        RenderPass();
        virtual bool init();
        
	private:
        ShaderProgram::pointer                      _program;
        std::vector<texture::Texture::pointer>      _textures;
        std::vector<int>                            _textureShaderLocations;

        std::vector<IRenderPropertyBase::pointer>	_properties;
	
        int                                         _glSceneTransformLoc;
        math::matrix                                _transform;
        math::matrix                                _worldTransform;
		
		void shrinkPropertiesAtIndex(int index);
	};

}}
#endif
#endif

