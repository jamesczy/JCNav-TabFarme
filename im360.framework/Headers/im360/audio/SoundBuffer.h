
#ifndef _SoundBuffer_h_
#define _SoundBuffer_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace audio {

	enum AudioFormat
	{
		AF_UNKNOWN=-1,
		AF_PCM_MONO8=0x1100,
		AF_PCM_MONO16=0x1101,
		AF_PCM_STEREO8=0x1102,
        AF_PCM_STEREO16=0x1103
	};

	class SoundSource;

    class I3DAPI SoundBuffer : virtual public core::I3dObject
	{
	friend class SoundSource;

	public:
        typedef core::SharedPointer<SoundBuffer>::pointer pointer;

        static SoundBuffer::pointer create();
		virtual ~SoundBuffer();
        virtual std::string getClassName() const;

		bool setData(AudioFormat format, void * data, unsigned int sizeBytes, unsigned int frequency);

		unsigned int getFrequency();
		unsigned int getBitDepth();
		unsigned int getChannels();
		unsigned int getSizeBytes();
		unsigned long getSampleCount();
		unsigned long getDurationMSecs();
		float getDurationSecs();
		
		bool getIsQueued();
		bool getIsValid();

		float getSampleTimeSec(unsigned int sample);

		static AudioFormat getFormat(unsigned int channels, unsigned int bitDepth);

    protected:
        SoundBuffer();
        virtual bool init();

	private:
		unsigned int	_buffer;

	};

}}
#endif
#endif
