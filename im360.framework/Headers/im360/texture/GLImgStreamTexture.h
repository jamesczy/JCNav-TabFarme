/*
 * GLImgStreamTexture.h
 *
 *  Created on: Dec 15, 2011
 *      Author: Ben Siroshton
 */

#ifndef _GLImgStreamTexture_h_
#define _GLImgStreamTexture_h_

#include "im360/core/MarbleConfig.h"
#include "Texture.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace texture {

	class GLImgStreamTexture : virtual public Texture
	{
	public:
        typedef core::SharedPointer<GLImgStreamTexture>::pointer pointer;
		
        static GLImgStreamTexture::pointer create();
        
		virtual ~GLImgStreamTexture();
        virtual std::string getClassName() const;

		void destroy();

		void setTextureStreamIndex(int textureIndex);
		int getTextureStreamCount();

		virtual bool bindTexture(unsigned int textureSlot=0);

		virtual unsigned int getWidth();
		virtual unsigned int getHeight();
		virtual TextureFormat getFormat();

    protected:
        GLImgStreamTexture();
        virtual bool init();
        
	private:
		struct
		{
			unsigned int *	textures;
			int				textureCount;
			int				streamWidth;
			int				streamHeight;
			int				streamIndex;
		} _gl;

		int initTextureStreams();
	};

}}
#endif
#endif

