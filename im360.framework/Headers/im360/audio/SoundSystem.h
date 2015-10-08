

#ifndef _SoundSystem_h_
#define _SoundSystem_h_

#include "im360/core/MarbleConfig.h"
#include "im360/util/Singleton.h"
#include "SoundSource.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace audio {

    class I3DAPI SoundSystem : virtual public core::I3dObject, virtual public util::Singleton<SoundSystem>
	{
    friend class util::Singleton<SoundSystem>;
	public:                
		virtual ~SoundSystem();
        virtual std::string getClassName() const;

		bool isInitialized();
        void initAudio();

        static SoundSource::pointer fromWavFile(const std::string & file);

    protected:
        SoundSystem();

	private:
		void *	_device;
		void *	_context;

	};

}}
#endif
#endif
