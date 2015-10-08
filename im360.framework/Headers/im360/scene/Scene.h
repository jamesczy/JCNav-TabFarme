/*
 *  Scene.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on ...
 *  Copyright 2012 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Scene_h_
#define _Scene_h_

#include "IScene.h"
#include "Node.h"
#include "im360/json/IJsonHandler.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace player { class Player; }
namespace scene {

    class I3DAPI Scene : virtual public IScene, virtual public Node
    {
    friend class player::Player;

    public:
        typedef core::SharedPointer<Scene>::pointer pointer;

        virtual ~Scene();
        virtual std::string getClassName() const;
        
        virtual void destroy();

        virtual ICamera::pointer getCamera();
        virtual void setCamera(ICamera::pointer camera);

        virtual void setIsActive(bool active);
        virtual bool getIsActive();

        virtual void render();
        virtual	void render(const math::matrix & sceneTransform);
        virtual math::matrix getLastSceneCameraMatrix();

        virtual void setSceneListener(ISceneListener::pointer listener);

        virtual physics::IPhysicsEngine::pointer getPhysicsEngine();

        // IScene
        virtual scene::Viewport getViewport();
        virtual void setViewport(scene::Viewport & viewport);
        virtual void setPlayerConfig(const player::PlayerConfig::weakPointer & config);
        virtual player::PlayerConfig::weakPointer getPlayerConfig() const;
        
        // IJsonHandler
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);

        // I3dObject
        virtual util::Variant evaluate(const util::Command & command);
        
    protected:
        Scene();
        virtual bool init();

        virtual void setSceneHints(unsigned long flags);

        void setNodeScene(Node::pointer node);
        void clearNodeScene(Node::pointer node);

        player::PlayerConfig::weakPointer _playerConfig;
        
    private:
        math::matrix _identity;

    };

}}
#endif
#endif
