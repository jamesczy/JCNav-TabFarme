

#ifndef _SoundSource_h_
#define _SoundSource_h_

#include "im360/core/MarbleConfig.h"
#include "SoundBuffer.h"
#include "im360/util/Thread.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>

namespace im360 {
namespace audio {

    class I3DAPI SoundSource : virtual public core::I3dObject, virtual protected async::Thread
	{
	public:
        typedef core::SharedPointer<SoundSource>::pointer pointer;
        typedef std::list<SoundBuffer::pointer>     soundBufferList;
        typedef soundBufferList::iterator           soundBufferListIt;

        static SoundSource::pointer create();
        
		virtual ~SoundSource();
        virtual std::string getClassName() const;

		void play();
		void stop();
		void rewind();       

		bool getPaused();
		void setPaused(bool paused);

        void setLoopEnabled(bool enabled);
        bool getLoopEnabled();
        
		void waitTillFinished();

        bool queueBuffer(SoundBuffer::pointer buffer);
		unsigned int clearQueue();
        unsigned int returnUsedBuffers(soundBufferList * list);
		
		float getSecondOffset();
		unsigned int getSampleOffset();
		unsigned int getByteOffset();

		unsigned int getBuffersQueued();
		unsigned long getBuffersPlayed();
		unsigned long getBytesQueued();

		float getTimePlayedSecs();
		unsigned long getTimePlayedMSecs();
		float getTimeQueuedSecs();
		unsigned long getTimeQueuedMSecs();

		void setPlayInThreadEnabled(bool enabled);
		bool getPlayInThreadEnabled();

		void resetTimePlayed();

		void debugPrintQueue();
		
        // Thread
        void run();

    protected:
        SoundSource();
        virtual bool init();

	private:
        SoundBuffer::pointer unqueueBuffer(unsigned int alBufferId);
		void collectProcessedBuffers();
		
        soundBufferList	_queue;
        soundBufferList	_usedBuffers;

		bool			_isPlaying;
        bool            _loopEnabled;
		bool			_isUserPaused;
		bool			_playInThread;
		bool			_stopThreadWhenEmpty;

		struct
		{
			long	buffersPlayed;
			long	bytesQueued;
			float	timePlayedSecs;
			float	timeQueuedSecs;
		} _stats;

		unsigned int	_source;
        async::Mutex	_sourceMutex;
        async::Mutex	_queueMutex;
        async::Mutex	_usedBufferMutex;

		void lockSource();
		void unlockSource();

	};

}}
#endif
#endif
