/*
 *  Player.h
 *
 *  Created by Ben Siroshton on 8/12/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Player_h_
#define _Player_h_

#include "im360/core/MarbleConfig.h"
#include "im360/catalog/Catalog.h"
#include "im360/event/EventDispatcher.h"
#include "im360/input/HumanInput.h"
#include "im360/math/MathUtils.h"
#include "im360/scene/ICamera.h"
#include "im360/scene/IRenderable.h"
#include "im360/scene/Scene.h"
#include "im360/scene/PlaneNode.h"
#include "im360/texture/RenderTargetTexture.h"
#include "im360/core/Pointer.h"
#include "im360/util/Timer.h"
#include "im360/video/IVideoServer.h"
#include "im360/core/MarbleTypes.h"
#include "SceneManager.h"
#include "PlayerConfig.h"

#ifdef __cplusplus
#include <string>
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace player {

    class I3DAPI IPlayerListener
    {
    public:
        typedef core::SharedPointer<IPlayerListener>::pointer pointer;
        
        virtual void onRender() = 0;
    };


    class I3DAPI PlayerViewMode
    {
    public:
        enum Mode
        {
			STANDARD=0,
			SIDE_BY_SIDE_3D,
			TOP_BOTTOM_3D,
			ANAGLYPH_3D,

			COUNT
        };
    private:
        PlayerViewMode(){}
    };

    class I3DAPI Player : virtual public scene::IRenderable, virtual public input::IInputHandler, virtual public event::EventDispatcher
	{
	public:	
        typedef core::SharedPointer<Player>::pointer pointer;

        static Player::pointer create();
        virtual ~Player();
        virtual std::string getClassName() const;

        void setPlayerListener(IPlayerListener::pointer listener);
        
        bool loadMedia(const std::string & url);
        bool loadPackage(const ws::entities::PackageEntity::pointer & package);
        bool loadVideo(const ws::entities::VideoEntity::pointer & video);
        bool loadScene(const std::string & url);
        bool loadSourceById(unsigned long id);
        bool saveSnapshot(const std::string & file, core::ImageFormat::Format format = core::ImageFormat::UNKNOWN);

        static bool installLicense(std::string licenseFile);

        void restoreResources();
		void setIsActive(bool active);
		
		void render();
		void render(const im360::math::matrix & worldTransform);
				
		void resize(unsigned int width, unsigned int height);
	
        void tap(input::TapData d);
        void pinch(input::PinchData d);
        void pan(input::PanData d);

        SceneManager::pointer getSceneManager() const;
        void setSceneManager(SceneManager::pointer manager);

        PlayerConfig & config() const;
        
        /**
         * @brief Conveinence function to retrieve the top most scene from the SceneManager and
         * dynamically cast it to the requested type.
         */
        template<typename T>
        std::tr1::shared_ptr<T> getScene()
        {
            if( !_sceneManager ) return std::tr1::shared_ptr<T>();
            scene::Scene::pointer scene = _sceneManager->getTop();
            if( !scene ) return std::tr1::shared_ptr<T>();
            return scene->getPointer<T>();
        }

        /**
         * @brief Conveinence function that will clear the scene manager, set a new one if it does not exist
         * and push the given scene onto it.
         *
         * @param scene Scene to set
         */
        void setScene(scene::Scene::pointer scene);

		void setViewMode(PlayerViewMode::Mode mode);
		PlayerViewMode::Mode getViewMode() const;

        virtual void setViewport(scene::Viewport & viewport);
        virtual scene::Viewport getViewport() const;

        void setStereoSeparation(float distance);
        float getStereoSeparation() const;

		void setStereoConvergence(float angle);
		float getStereoConvergence() const;

        video::IVideoServer::pointer getVideoServer() const;

        bool getDispatchEventsEnabled();
        void setDispatchEventsEnabled(bool enabled);

        // IJsonHandler
        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
		virtual void jsonPropertiesEnd();

        // I3dObject
        virtual util::Variant evaluate(const util::Command & command);

	protected:
        Player();
        virtual bool init();

#if defined(I3d_JNI)
		virtual void onJniSet();
#endif

	private:
        unsigned long   _playerThreadId;
        IPlayerListener::pointer    _playerListener;
        
		// Scene
        SceneManager::pointer       _sceneManager;
        im360::math::matrix         _identity;

		// View Modes
        texture::RenderTargetTexture::pointer   _renderTargets[2];
        scene::PlaneNode::pointer               _screenTarget;

        // Config
        PlayerConfig::pointer   _playerConfig;
        
        float		_stereoSeparation;
        float		_stereoSeparationHalf;
		float		_stereoConvergence;
		float		_stereoConvergenceHalf;

        PlayerViewMode::Mode    _viewMode;
        scene::Viewport         _viewport;

		// Render Effects
		enum ScreenEffects
		{
			SE_3D_ANAGLYPH,

			SE_COUNT
		};

        render::RenderEffect::pointer  _screenEffects[SE_COUNT];

        // video server
        video::IVideoServer::pointer  _videoServer;

        // functions
		void buildAnaglyphSupport();
		void createShaderProgram();

		// events
		bool _dispatchEventsEnabled;

        // snapshot
        struct Snap
        {
            bool                        take;
            core::ImageFormat::Format   format;
            std::string                 file;
        } _snap;

        bool saveSnapshot_(const std::string & file, core::ImageFormat::Format format = core::ImageFormat::UNKNOWN);
	};
	
}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

I3DAPI long I3dPlayer_new();
I3DAPI void I3dPlayer_delete(long handle);
I3DAPI void I3dPlayer_render(long handle);
I3DAPI int I3dPlayer_loadMedia(long handle, const char * url);
I3DAPI void I3dPlayer_resize(long handle, int width, int height);
I3DAPI long I3dPlayer_getSceneManager(long handle);

#ifdef __cplusplus
}
#endif

#endif


