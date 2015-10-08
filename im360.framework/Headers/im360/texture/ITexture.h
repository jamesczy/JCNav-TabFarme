
#ifndef _ITexture_h_
#define _ITexture_h_

#include "im360/core/MarbleConfig.h"
#include "im360/json/IJsonHandler.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace texture {

    enum TextureFormat
	{
		// NOTE: if these are changed be sure to update the java bindings
		TF_UNKNOWN,
		TF_1_RGB888,
		TF_1_RGBA8888,
		TF_1_RGB565,
		TF_1_BGR888,
		TF_1_BGR565,
        TF_1_BGRA8888,
		TF_1_YUV420,
        TF_1_YUVJ422,
		TF_2_YUV420,
		TF_3_YUV420,
		TF_EXT_EOS,			// GL_TEXTURE_EXTERNAL_OES
        TF_GL_IMG_STREAM    // GL IMAGE STREAM
	};

    class I3DAPI ITexture
	{
	public:
        typedef core::SharedPointer<ITexture>::pointer pointer;

        virtual ~ITexture(){}
		virtual bool bindTexture(unsigned int textureSlot=0) = 0;

		virtual unsigned int getWidth() = 0;
		virtual unsigned int getHeight() = 0;

		virtual TextureFormat getFormat() = 0;
	};

}}
#endif
#endif
