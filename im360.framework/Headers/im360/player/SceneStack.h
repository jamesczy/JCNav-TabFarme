#ifndef _SceneStack_h_
#define _SceneStack_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"
#include "im360/event/EventDispatcher.h"
#include "SceneManager.h"

#ifdef __cplusplus

// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace player {

    class I3DAPI SceneStack : virtual public SceneManager
    {
    public:
        typedef core::SharedPointer<SceneStack>::pointer pointer;

        static SceneStack::pointer create();
        virtual ~SceneStack();

        // I3dObject
        virtual std::string getClassName() const;

        // ISceneManager
        virtual void add(const scene::Scene::pointer & scene);
        virtual void removeTop();
        virtual void remove(const scene::Scene::pointer & scene);

        virtual int getCount();
        virtual scene::Scene::pointer getAt(int index);
        virtual scene::Scene::pointer getTop();

        void setIsActive(bool active);
        virtual void setViewport(scene::Viewport & viewport);

        virtual void clear();

        // IRenderable
        virtual void render(const math::matrix & worldTransform);

        // IInputHandler
        virtual void tap(input::TapData d);
        virtual void pinch(input::PinchData d);
        virtual void pan(input::PanData d);

        // player config
        virtual void setPlayerConfig(const player::PlayerConfig::weakPointer & config);
        player::PlayerConfig::weakPointer getPlayerConfig() const;
        
        // IJsonHandler
        void handleJsonNode(std::string name, json::JsonInfo & json);

        // PropertyHolder
        virtual void innerJson(im360::json::JsonStringBuilder & json) const;

    protected:
        SceneStack();
        virtual bool init();
        
    private:
        std::vector<scene::Scene::pointer>  _scenes;
        bool                                _isActive;
        scene::Viewport                     _viewport;
        player::PlayerConfig::weakPointer   _playerConfig;

        void setActive(const scene::Scene::pointer & scene, bool active);
    };

}}
#endif
#endif

