/*
 *  BasicScene.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on ...
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _BasicScene_h_
#define _BasicScene_h_

#include "Scene.h"
#include "Camera.h"
#include "SphericalCamera.h"
#include "PlaneNode.h"
#include "im360/math/MatrixStack.h"
#include "im360/video/IVideo.h"
#include "im360/render/RenderEffect.h"
#include "im360/physics/IPhysicsEngine.h"
#include "im360/device/IMotionProvider.h"
#include "im360/screen/IScreen.h"
#include "im360/sequence/TimeSequenceManager.h"
#include "im360/sequence/ITimeline.h"
#include "im360/texture/BitmapTexture.h"
#include "im360/util/Command.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <queue>
namespace im360 {
namespace scene {

    class I3DAPI BasicScene :
            virtual public video::IMediaListener,
            virtual public device::IMotionListener,
            virtual public ISceneListener,
            virtual public sequence::ITimeline,
            virtual public event::EventListener,
            virtual public Scene
	{
	public:		
        typedef core::SharedPointer<BasicScene>::pointer pointer;
	
		enum LogoPosition
		{
			LP_BOTTOM,
			LP_TOP,
			LP_WATERMARK,
            LP_NONE
		};

        enum LookMode
        {
            LM_FINGER = 1,          // (mutualy exclusive with LM_HOLD_AND_DRAG)
            LM_GRAVITY = 2,
            LM_MOTION = 4,
            LM_HOLD_AND_DRAG = 8    // (mutualy exclusive with LM_FINGER)
        };

        static BasicScene::pointer create();
        
		virtual ~BasicScene();
        virtual std::string getClassName() const;
        
		// IScene
        virtual void destroy();
		virtual void setIsActive(bool active);
		virtual bool getIsActive();
		
        ICamera::pointer getCamera();
        void setCamera(ICamera::pointer camera);

        //virtual void render();
		virtual void render(const im360::math::matrix & worldTransform);

		// BasicScene
		void resetScene();

        screen::IScreen::pointer getScreen();
        void setScreen(screen::IScreen::pointer node);
		
		void setAttachScreenToCamera(bool enabled);
		bool getAttachScreenToCamera();

		im360::math::matrix getLastSceneCameraMatrix();
		im360::math::vec3 getLastSceneForwardVector();

		bool loadScene(std::string url);
        bool loadVideo(std::string url, std::string extra = "");
		bool loadImage(std::string url);        
		void unloadMedia();
		bool isMediaLoaded();
        core::MediaType::Type getLoadedMediaType();
        std::string getVideoUrl();
        std::string getAudioUrl();
        std::string getImageUrl();
        void setMediaTexture(texture::Texture::pointer texture);
		
		bool getPaused();
		void setPaused(bool paused);
        void stepForward();
		bool getLoopEnabled();
		void setLoopEnabled(bool enabled);
		
        virtual float getTime();
        virtual void setTime(float time);
        virtual float getDuration();
		
        virtual void tap(input::TapData d);
        virtual void pinch(input::PinchData d);
        virtual void pan(input::PanData d);
		
		void setPinchFactor(float factor);
		float getPinchFactor();
		
		void setPanFactor(float factor);
		float getPanFactor();
						
        bool getBuildScreenOnMeta();
        void setBuildScreenOnMeta(bool enabled);

        void setLogoPosition(LogoPosition position); // LP_NONE requires license
		LogoPosition getLogoPosition();

		bool setLogoImage(std::string url); // requires license
		
        virtual void setSceneListener(ISceneListener::pointer listener);
        virtual void setMediaListener(IMediaListener::weakPointer listener);

        virtual physics::IPhysicsEngine::pointer getPhysicsEngine();

        void setLookFlags(int flags);
        int getLookFlags();
        void resetMotionData();
        
        void setUserMotionEnabled(bool enabled);
        bool getUserMotionEnabled();
        void setMotionData(const IMotionListener::MotionData & motion);

        // IScene
        virtual Viewport getViewport();
        virtual void setViewport(Viewport & viewport);
        virtual void setPlayerConfig(const player::PlayerConfig::weakPointer & config);
        
        // Sequences
        sequence::TimeSequenceManager::pointer getSequenceManager();

        // IJsonHandler
        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
		virtual void jsonPropertiesEnd();
		
		// IMediaListener
		virtual void onMediaLoaded(const char * url);
        virtual void onMediaFrame();
		virtual void onMediaTimeChange(float time);
		virtual void onMediaDurationChange(float duration);
        virtual void onMediaFormatChange(texture::TextureFormat format);
		virtual void onMediaPlayStateChange(PlayState state);
        virtual void onMediaError(video::MediaError::ErrorCode code, const std::string & description = "");
        virtual void onMediaMetaData(const std::string & name, const std::string & value);

        // IMotionListener
        virtual void onDeviceMotion(const IMotionListener::MotionData & motion);

        // ISceneListener
        virtual bool onNodeClick(const ISceneListener::HitInfo & info);
        virtual void onWorldClick(const im360::math::Ray3 & ray);

        // I3dObject
        virtual util::Variant evaluate(const util::Command & command);
        
    protected:
        BasicScene();
        virtual bool init();

		// IScene
		virtual void setSceneHints(unsigned long flags);		
        
        // EventListener
        void onEvent(event::Event::pointer event);

    private:
		struct ActiveState
		{
			bool	videoPaused;
		} _activeState;

		bool				_isActive;

		// scene
        screen::IScreen::pointer    _screen;
        ICamera::pointer            _camera;
        SphericalCamera::pointer	_defaultCamera;
        bool                        _attachScreenToCamera;

		// listeners
        ISceneListener::pointer     _sceneListener;
        IMediaListener::weakPointer _mediaListener;

		// rendering
        im360::math::MatrixStack        _mxStack;
        im360::math::matrix             _identity;
        im360::math::matrix             _lastSceneCameraMatrix;

        // motion handling
        struct
        {
            device::IMotionProvider::pointer    motionProvider;
            device::IMotionListener::MotionData motionData[2];
            im360::math::matrix                 gravityView;
            im360::math::Transform::pointer     motionTransform;
            int                                 lookFlags;
            int                                 lastLookFlags;
            bool                                userMotionEnabled;
            bool                                motionUpdated;
            im360::math::vec2                   dragVector;
            float                               dragFactor;
            float                               dragDampeningFactor;
            bool                                isDragging;
            struct
            {
                float yaw;
                float pitch;
                float roll;
            } lookOffset;
        } _motion;


		void renderScene();
        void updateCamera();

		// physics
        physics::IPhysicsEngine::pointer    _physicsEngine;

		// Input
		float				_pinchFov;
		float				_pinchFactor;
		float				_panFactor;
		
        // media
        video::IVideo::pointer          _video;
        texture::Texture::pointer       _mediaTexture;
        async::Mutex                    _videoLoadMutex;
        bool                            _reconnectMediaTexture;
        texture::BitmapTexture::pointer _loadTexture;

        struct DataUrls
        {
            std::string video;
            std::string audio;
            std::string image;
            std::string scene;
            std::string urlRoot;
        } _urls;

        bool                            _buildScreenOnMeta;
        std::string                     _buildScreenMeta;
        bool                            _screenMetaChanged;

        void connectMediaToScreen(texture::Texture::pointer texture);
	
		// bottom logo
        PlaneNode::pointer  _logo;
		LogoPosition		_logoPosition;
		
		void buildLogo();
        void updateWatermark();

		// player friend support
		unsigned long		_sceneHints;
		Viewport			_viewport;
        
        // input queues
        std::queue<input::TapData> _tapQueue;
        async::Mutex               _tapQueueMutex;
        
        void processInput();

        // sequences
        sequence::TimeSequenceManager::pointer  _sequenceManager;
        bool                                    _tickSequence;

	};

}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
I3DAPI long I3dBasicScene_new();
I3DAPI void I3dBasicScene_delete(long handle);
#ifdef __cplusplus
}
#endif


#endif
