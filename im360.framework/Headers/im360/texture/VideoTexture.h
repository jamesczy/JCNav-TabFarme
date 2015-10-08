#ifndef _VideoTexture_h_
#define _VideoTexture_h_

#include "im360/core/MarbleConfig.h"
#include "im360/render/ShaderProgram.h"
#include "im360/resource/Resource.h"
#include "im360/texture/TextureUtils.h"
#include "im360/util/Thread.h"
#include "im360/core/Pointer.h"
#include "Texture.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace texture {

    class I3DAPI VideoTexture : virtual public Texture, virtual public resource::Resource
	{
	public:		
        typedef core::SharedPointer<VideoTexture>::pointer pointer;

        static VideoTexture::pointer create();
		static VideoTexture::pointer create(TextureFormat format);
		static VideoTexture::pointer create(TextureFormat format, unsigned int width, unsigned int height);
        
		virtual ~VideoTexture();
        virtual std::string getClassName() const;

		virtual bool initTexture(TextureFormat format, unsigned int width, unsigned int height);
		virtual void destroy();

		virtual void clear();

		virtual bool isLocked(int plane=0);
		virtual unsigned char * lock(int plane=0);
		virtual void unlock(int plane=0);

		virtual TextureFormat getFormat();
		
		virtual unsigned int getWidth();
		virtual unsigned int getHeight();		
		virtual unsigned int getVideoWidth();
		virtual unsigned int getVideoHeight();

		virtual unsigned int getPlaneWidth(int plane=0);
		virtual unsigned int getPlaneHeight(int plane=0);
		virtual unsigned int getPlaneDataSize(int plane=0);
		virtual unsigned int getPlaneCount();
		
		virtual bool bindTexture(unsigned int textureSlot=0);
		virtual void updateFromYUV420(const YUVSeperated & yuv);
		virtual void updateFromYUV444(const YUVSeperated & yuv);

		bool wasUpdated();
		
		virtual std::string getFragmentSource(FragmentOptions * options=NULL);
        virtual void setShaderLocations(render::ShaderProgram::pointer program);
		
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);

        // IResource interface
        virtual resource::IResource::RestoreResult restoreResource(unsigned int restoreCount);

    protected:
        VideoTexture();
		virtual bool init();
		virtual bool init(TextureFormat format);
		virtual bool init(TextureFormat format, unsigned int width, unsigned int height);

	private:
		static const unsigned int MaxDataCount = 3;

		TextureFormat	_format;

		unsigned int	_dataCount; // also plane count
		unsigned int	_videoWidth;
		unsigned int	_videoHeight;
		bool			_isDirty;
		bool			_wasUpdated;

		struct
		{
			unsigned char * data;
			unsigned long	dataSize;
			unsigned int	glTex;
			unsigned int	width;
			unsigned int	height;
			bool			isLocked;
		} _texture[MaxDataCount];
		
		int		_texLoc;
		int		_yTexLoc;
		int		_uTexLoc;
		int		_vTexLoc;
		int		_yTex2Loc;
		int		_uTex2Loc;
		int		_vTex2Loc;
		int		_vTexSizeLoc;
		
        async::Mutex    _textureMutex;

		void updateGlTexture();
		static std::string getFragmentCropFunction(FragmentOptions * options);
        
        void setTextureProperties(unsigned int index);
        
        bool initMemory();
        bool initGl();
	};

}}
#endif
#endif
