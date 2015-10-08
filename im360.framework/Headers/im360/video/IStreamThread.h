

#ifndef _IStreamThread_h_
#define _IStreamThread_h_

#include "im360/core/MarbleConfig.h"
#include "im360/util/Thread.h"
#include "im360/texture/Texture.h"
#include "BlockManager.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace video {

    class I3DAPI IStreamThread : virtual public async::Thread
	{
	public:		
        typedef core::SharedPointer<IStreamThread>::pointer pointer;

		virtual ~IStreamThread(){}
		virtual float getTime() = 0;
		virtual void setTime(float time) = 0;

		virtual bool isPlaying() = 0;
		virtual void stop() = 0;

		virtual void destroy() = 0;

	};

	class I3DAPI IMediaStream : virtual public IStreamThread
	{
	public:
        typedef core::SharedPointer<IMediaStream>::pointer pointer;

		virtual ~IMediaStream(){}
		virtual bool getIsInitialized() = 0;
		virtual void queueBlock(BlockManager::Block * block) = 0;
		
		virtual void setTrackNumber(int trackNumber) = 0;
		virtual int getTrackNumber() = 0;
		
		virtual float getTimeFront() = 0;
		virtual float getTimeBack() = 0;
		virtual float getTimeLength() = 0;
		
		virtual void flushQueue() = 0;
	};
	
	class I3DAPI IStreamTimeProvider
	{
	public:
        typedef core::SharedPointer<IStreamTimeProvider>::pointer pointer;

        virtual ~IStreamTimeProvider(){}
#ifdef I3d_WINDOWS
		typedef void(__cdecl TimeChangedCallback)(float,void*);
#else
		typedef void TimeChangedCallback(float,void*);
#endif
		virtual void setTimeChangedCallback(TimeChangedCallback * function, void * userData=NULL)=0;

		virtual void stop() = 0;
		virtual bool getPaused() = 0;
		virtual void setPaused(bool paused) = 0;

        virtual float getTime() = 0;
        virtual void setTime(float time) = 0;

	protected:
		virtual void notifyTimeChange(float time)=0;
		
	};
	
	class I3DAPI StreamTimeProvider : virtual public IStreamTimeProvider
	{
	public:		
        typedef core::SharedPointer<StreamTimeProvider>::pointer pointer;

		StreamTimeProvider()
		{
			_callback = NULL;
			_data = NULL;
		}
		virtual ~StreamTimeProvider(){}

		virtual void setTimeChangedCallback(IStreamTimeProvider::TimeChangedCallback * function, void * userData=NULL)
		{
			_callback = function;
			_data = userData;
		}

		virtual void stop(){}
		virtual bool getPaused(){ return true; }
		virtual void setPaused(bool paused){}
		
	protected:
		virtual void notifyTimeChange(float time)
		{
			if( _callback )
			{
				_callback(time,_data);
			}
		}

	private:
		TimeChangedCallback	*	_callback;
		void *					_data;
	};

	class I3DAPI IVideoStream : virtual public IMediaStream
	{
	public:
        typedef core::SharedPointer<IVideoStream>::pointer pointer;

		virtual ~IVideoStream(){}
		virtual unsigned int getVideoWidth() = 0;
		virtual unsigned int getVideoHeight() = 0;
		virtual float getFps() = 0;
	};

	class I3DAPI IVideoTextureStream : virtual public IVideoStream
	{
	public:
        typedef core::SharedPointer<IVideoTextureStream>::pointer pointer;

		virtual ~IVideoTextureStream(){}
        virtual texture::TextureFormat getTextureFormat() = 0;
        virtual void setTexture(texture::Texture::pointer texture) = 0;
        virtual texture::Texture::pointer getTexture() = 0;
	};

	class I3DAPI IAudioStream : virtual public IMediaStream, virtual public IStreamTimeProvider
	{
	public:
        typedef core::SharedPointer<IAudioStream>::pointer pointer;

		virtual ~IAudioStream(){}
		virtual unsigned int getChannels() = 0;
		virtual unsigned int getFrequency() = 0;
		virtual unsigned int getBitDepth() = 0;
	};

}}
#endif
#endif
