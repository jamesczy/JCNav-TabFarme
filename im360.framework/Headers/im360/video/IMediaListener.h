/*
 *  IMediaListener.h
 *  libim360
 *
 *  Created by Ben Siroshton on 11/19/11.
 *  Copyright 2010-2011 Immersive Media. All rights reserved.
 *
 */

#ifndef _IMediaListener_h_
#define _IMediaListener_h_

#include "im360/core/Pointer.h"
#include "im360/texture/ITexture.h"

#ifdef __cplusplus
#include <string>
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace video {

    class MediaError
	{
	public:
		enum ErrorCode
		{
			LOAD_FAILED
		};

	private:
		MediaError(){} // don't allow construction of this class
	};

	class IMediaListener
	{
	public:
        typedef core::SharedPointer<IMediaListener>::pointer pointer;
        typedef core::WeakPointer<IMediaListener>::pointer weakPointer;

		enum PlayState
		{
			PLAYING,
			PAUSED,
			ENDED,
            STALLED,
            STALL_RECOVERED,
		};

        virtual void onMediaLoaded(const char * url){}
        virtual void onMediaFrame(){}
        virtual void onMediaTimeChange(float time){}
        virtual void onMediaDurationChange(float duration){}
        virtual void onMediaFormatChange(texture::TextureFormat format){}
        virtual void onMediaPlayStateChange(PlayState state){}
        virtual void onMediaError(MediaError::ErrorCode code, const std::string & description = ""){}
        virtual void onMediaMetaData(const std::string & name, const std::string & value){}
	};

}}
#endif
#endif
