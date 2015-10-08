#ifndef _PlayerExporter_h_
#define _PlayerExporter_h_

#include "im360/player/Player.h"
#include "im360/util/Thread.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace tool {

    class I3DAPI PlayerExporter : public event::EventDispatcher, public event::EventListener
    {
    public:
        enum Status
        {
            UNKNOWN,
            PROCESSING,
            FAILED,
            FINISHED
        };

        typedef core::SharedPointer<PlayerExporter>::pointer pointer;

        static PlayerExporter::pointer create();
        virtual ~PlayerExporter();
        virtual std::string getClassName() const;

        // input
        void setInputMedia(const std::string & url);
        void setMediaOverride(const std::string & url);

        // output
        void setOutputImageFormat(core::ImageFormat::Format format);
        void setOutputPath(const std::string & path);
        void setOutputSize(int width, int height);

        core::ImageFormat::Format getOutputImageFormat();
        std::string getOutputPath();
        int getOutputWidth();
        int getOutputHeight();

        // process
        bool initExport();
        bool tickExport();
        void finishExport();
        Status getStatus();

    protected:
        PlayerExporter();

        // EventListener
        virtual void onEvent(event::Event::pointer event);

    private:
        virtual bool init();

        struct
        {
            std::string url;
            std::string overrideMedia;
        } _input;

        struct
        {
            std::string                 path;
            int                         width;
            int                         height;
            core::ImageFormat::Format   imageFormat;
            std::string                 imageExt;
        } _output;

        struct
        {
            long    context;
            int     frameBuffer;
            int     colorBuffer;
            int     depthBuffer;
        } _gl;

        struct
        {
            player::Player::pointer player;
            scene::Scene::pointer   scene;
            async::Mutex            runMutex;
            async::WaitCondition    runWait;
            Status                  status;
            int                     mediaEventId;
            unsigned long           tickCount;
            core::MediaType::Type   mediaType;
            unsigned long           frame;
            char                    tempFile[256];
            bool                    reachedEnd;
            bool                    hasFrame;
            bool                    snapshotSaved;
        } _process;

        bool initGL();
        bool finish(Status status);

    };

}}
#endif
#endif
