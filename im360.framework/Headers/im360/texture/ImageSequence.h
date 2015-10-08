#ifndef _ImageSequence_h_
#define _ImageSequence_h_

#include "Texture.h"
#include "BitmapTexture.h"
#include "im360/video/IVideo.h"
#include "im360/util/Thread.h"

namespace im360 {
namespace texture {

    class ImageSequence : virtual public Texture, virtual public video::IVideo, virtual public video::IMediaListener, virtual public async::Thread
    {
    public:
        typedef core::SharedPointer<ImageSequence>::pointer pointer;

        static ImageSequence::pointer create();
        
        virtual ~ImageSequence();
        virtual std::string getClassName() const;

        void setRootPath(const std::string & path);
        void setNameFormat(const std::string & format);
        void setFps(float fps);

        void stepBackward();

        // Texture
        virtual bool bindTexture(unsigned int textureSlot=0);

        virtual unsigned int getWidth();
        virtual unsigned int getHeight();

        virtual TextureFormat getFormat();

        // IVideo
        virtual bool loadVideo(std::string url, std::string extra="");
        virtual bool isLoaded();
        virtual std::string getUrl();

        virtual unsigned int getVideoWidth();
        virtual unsigned int getVideoHeight();

        virtual float getTime();
        virtual void setTime(float time);
        virtual float getDuration();

        virtual void play();
        virtual bool getPaused();
        virtual void setPaused(bool paused);
        virtual void stepForward();

        virtual void setLoopEnabled(bool enabled);
        virtual bool getLoopEnabled();

        virtual void suspend();
        virtual void resume();
        virtual void destroy();
        virtual void update();

        virtual void setTexture(Texture::pointer texture);
        virtual Texture::pointer getTexture();

        virtual TextureFormat getTextureFormat();

        virtual unsigned int getFramesDecoded();
        virtual int getCapabilities();

        virtual void setMediaListener(video::IMediaListener::weakPointer listener);

        // Thread
        void run();

        // IMediaListener
        virtual void onMediaLoaded(const char * url);
        virtual void onMediaFrame();
        virtual void onMediaTimeChange(float time);
        virtual void onMediaDurationChange(float duration);
        virtual void onMediaFormatChange(TextureFormat format);
        virtual void onMediaPlayStateChange(PlayState state);
        virtual void onMediaError(video::MediaError::ErrorCode code, const std::string & description = "");
        virtual void onMediaMetaData(const std::string & name, const std::string & value);

    protected:
        ImageSequence();
        bool init();

    private:
        struct
        {
            std::string path;
            std::string nameFormat;
            float       fps;
            long        frameOffset;
            float       gotoTime;
        } _input;

        struct
        {
            float           time;
            float           duration;
            long            frameNumber;
            long            frameCount;            
            unsigned long   framesDecoded;
            unsigned long   timePerFrame;
            std::string     url;
            bool            loopEnabled;
            bool            wasPaused;
            bool            isPaused;
            bool            isRunning;
            bool            isQuiting;
        } _info;

        struct
        {
            BitmapTexture::pointer  texture;
            async::Mutex            textureMutex;
        } _tex;

        char _tempName[256];

        video::IMediaListener::weakPointer _listener;

        void updateFrameCount();
        void getFileNameForFrame(long frame, std::string & file);
        long getFrameNumberAtTime(float time);
        float getFrameTime(long frameNumber);
        bool loadFrame(long frameNumber);
        bool loadFrameAtTime(float time);

    };

}}
#endif
