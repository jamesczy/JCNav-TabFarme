/*
 *  VideoHistoryTexture.h
 *  marble360
 *
 *  Created by Ben Siroshton on 9/29/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _VideoHistoryTexture_h_
#define _VideoHistoryTexture_h_

#include "VideoTexture.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace texture {

    class I3DAPI VideoHistoryTexture : virtual public VideoTexture
	{
	public:
        typedef core::SharedPointer<VideoHistoryTexture>::pointer pointer;

		static VideoHistoryTexture::pointer create();
		static VideoHistoryTexture::pointer create(unsigned int size);
        
		virtual ~VideoHistoryTexture();
        virtual std::string getClassName() const;
		
		virtual bool bindHistoryTexture(unsigned int index, unsigned int textureSlot=0);
		virtual bool bindHistoryTextureByAge(unsigned int age, unsigned int textureSlot=0);

		void setHistorySize(unsigned int size);
		unsigned int getHistorySize();

        inline VideoTexture::pointer getLatest(unsigned int age=0);
        inline VideoTexture::pointer getCurrentTexture();
		
		void setBindToCycleTexture(bool enabled);
		bool getBindToCycleTexture();
		
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
		
        virtual std::string getFragmentSource(FragmentOptions * options=NULL);
        virtual void setShaderLocations(render::ShaderProgram::pointer program);
		
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);

    protected:
        VideoHistoryTexture();
		virtual bool init();
		virtual bool init(unsigned int size);
        
	private:
        typedef std::vector<VideoTexture::pointer> TextureList;
		
		TextureList		_list;
		unsigned int	_currentIndex;		
		unsigned int	_lastIndex;
        async::Mutex	_listMutex;
				
		TextureFormat	_format;
		unsigned int	_width;
		unsigned int	_height;
		
        VideoTexture::pointer	_lastTextureBound;
        bool                    _autoCycleTextureOnBind;
		
		inline void setNextTexture();
		
	};

}}
#endif
#endif
