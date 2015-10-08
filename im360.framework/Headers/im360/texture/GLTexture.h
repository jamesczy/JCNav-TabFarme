/*
 * GLTexture.h
 *
 *  Created on: Aug 15, 2011
 *      Author: ben
 */

#ifndef _GLTexture_h_
#define _GLTexture_h_

#include "im360/core/MarbleConfig.h"
#include "Texture.h"
#include "im360/resource/Resource.h"

namespace im360 {
namespace texture {

	class GLTexture : virtual public Texture, virtual public resource::Resource
	{
	public:
		typedef core::SharedPointer<GLTexture>::pointer pointer;

		static GLTexture::pointer create();
		static GLTexture::pointer create(TextureFormat format);
		static GLTexture::pointer create(unsigned int handle, TextureFormat format);

		virtual ~GLTexture();
        virtual std::string getClassName() const;
        
		unsigned int getGlHandle();

		virtual bool bindTexture(unsigned int textureSlot=0);

		virtual unsigned int getWidth();
		void setWidth(unsigned int width);

		virtual unsigned int getHeight();
		void setHeight(unsigned int height);

		virtual TextureFormat getFormat();

		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);

        // IResource interface
        virtual resource::IResource::RestoreResult restoreResource(unsigned int restoreCount);

    protected:
		GLTexture();
        virtual bool init();
		virtual bool init(TextureFormat format);
		virtual bool init(unsigned int handle, TextureFormat format);

	private:
		unsigned int            _handle;
		bool                    _isMyHandle;
        texture::TextureFormat 	_format;
		unsigned int            _width;
		unsigned int            _height;

	};

}}
#endif
