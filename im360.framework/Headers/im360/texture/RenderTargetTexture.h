/*
 *  RenderTargetTexture.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 2/15/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _RenderTargetTexture_h_
#define _RenderTargetTexture_h_

#include "im360/core/MarbleConfig.h"
#include "im360/resource/Resource.h"
#include "im360/core/Pointer.h"
#include "Texture.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace texture {

    class I3DAPI RenderTargetTexture : virtual public Texture, virtual public resource::Resource
	{
	public:
        typedef core::SharedPointer<RenderTargetTexture>::pointer pointer;

		static RenderTargetTexture::pointer create();
		static RenderTargetTexture::pointer create(unsigned int width, unsigned int height, bool includeDepthBuffer);
        
		virtual ~RenderTargetTexture();
        virtual std::string getClassName() const;
				
		void bindFrameBuffer();
		virtual bool bindTexture(unsigned int textureSlot=0);
		
		virtual unsigned int getWidth();
		virtual unsigned int getHeight();
		virtual TextureFormat getFormat();

		void setSize(unsigned int width, unsigned int height);
		
		bool getDepthBufferEnabled();
		void setDepthBufferEnabled(bool enabled);
		
		unsigned int getClearOnBindBits();
		void setClearOnBindBits(unsigned int mask);

        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
		
        // IResource interface
        virtual resource::IResource::RestoreResult restoreResource(unsigned int restoreCount);
    
    protected:
        RenderTargetTexture();
        virtual bool init();
        virtual bool init(unsigned int width, unsigned int height, bool includeDepthBuffer);
        
	private:
		unsigned int	_glFrameBuffer;
		unsigned int	_glDepthBuffer;
		unsigned int	_glTexture;
		
		unsigned int	_width;
		unsigned int	_height;
		
		unsigned int	_clearOnBindBits;
		
		void update(unsigned int width, unsigned int height, bool includeDepthBuffer);
		void createDepthBuffer();
		void deleteDepthBuffer();
		
	};

}}
#endif
#endif
