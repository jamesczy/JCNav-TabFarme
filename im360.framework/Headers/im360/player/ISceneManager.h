#ifndef _ISceneManager_h_
#define _ISceneManager_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"
#include "im360/event/EventDispatcher.h"
#include "im360/scene/Scene.h"
#include "im360/scene/IRenderable.h"
#include "im360/input/HumanInput.h"
#include "im360/player/PlayerConfig.h"

#ifdef __cplusplus

// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace player {

    class I3DAPI ISceneManager :
            virtual public core::I3dObject,
            virtual public scene::IRenderable,
            virtual public input::IInputHandler
    {
    public:
        typedef core::SharedPointer<ISceneManager>::pointer pointer;
        
        virtual ~ISceneManager();

        virtual void add(const scene::Scene::pointer & scene) = 0;
        virtual void removeTop() = 0;
        virtual void remove(const scene::Scene::pointer & scene) = 0;

        virtual int getCount() = 0;
        virtual scene::Scene::pointer getAt(int index) = 0;
        virtual scene::Scene::pointer getTop() = 0;

        virtual void clear() = 0;

        virtual void setViewport(scene::Viewport & viewport) = 0;
        virtual void setIsActive(bool active) = 0;

        virtual void setPlayerConfig(const player::PlayerConfig::weakPointer & config) = 0;
        virtual player::PlayerConfig::weakPointer getPlayerConfig() const = 0;
        
    protected:
        ISceneManager();

    };

}}
#endif
#endif

