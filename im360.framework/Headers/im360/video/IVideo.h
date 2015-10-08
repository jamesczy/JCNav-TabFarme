/*
 *  IVideo.h
 *  player
 *
 *  Created by Ben Siroshton on 8/24/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _IVideo_h_
#define _IVideo_h_

#include "im360/core/MarbleConfig.h"
#include "IMediaListener.h"
#include "im360/texture/TextureUtils.h"
#include "im360/texture/VideoTexture.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace video {

    class I3DAPI VideoCaps
	{
	public:
		enum Flags
		{
			UNDEFINED,
			GL_IMG_STREAM
		};

	private:
		VideoCaps(){} // don't allow construction of this class, its just an enum holder.
	};

	class I3DAPI IVideo
	{
	public:	
        typedef core::SharedPointer<IVideo>::pointer pointer;

		virtual ~IVideo(){}
        virtual bool loadVideo(std::string url, std::string extra="") = 0;
		virtual bool isLoaded() = 0;
		virtual std::string getUrl() = 0;

		virtual unsigned int getVideoWidth() = 0;
		virtual unsigned int getVideoHeight() = 0;
		
		virtual float getTime() = 0;
		virtual void setTime(float time) = 0;
		virtual float getDuration() = 0;
		
		virtual void play() = 0;
		virtual bool getPaused() = 0;
		virtual void setPaused(bool paused) = 0;
        virtual void stepForward() = 0;

		virtual void setLoopEnabled(bool enabled) = 0;
		virtual bool getLoopEnabled() = 0;
        
		virtual void suspend() = 0;
		virtual void resume() = 0;
		virtual void destroy() = 0;
		virtual void update() = 0;
				
        virtual void setTexture(texture::Texture::pointer texture) = 0;
        virtual texture::Texture::pointer getTexture() = 0;

        virtual texture::TextureFormat getTextureFormat() = 0;
        
		virtual unsigned int getFramesDecoded() = 0;
		virtual int getCapabilities() = 0;

        virtual void setMediaListener(IMediaListener::weakPointer listener) = 0;
	};

}}
#endif
#endif
