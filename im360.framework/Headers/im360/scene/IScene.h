
#ifndef _IScene_h_
#define _IScene_h_

#include "ICamera.h"
#include "Node.h"
#include "IRenderable.h"
#include "ISceneListener.h"
#include "im360/math/Rect.h"
#include "im360/input/HumanInput.h"
#include "im360/json/IJsonHandler.h"
#include "im360/physics/IPhysicsEngine.h"
#include "im360/core/Pointer.h"
#include "im360/player/PlayerConfig.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

    class I3DAPI IScene : virtual public IRenderable, virtual public input::IInputHandler
	{
	public:
        typedef core::SharedPointer<IScene>::pointer pointer;

		enum SceneHints
		{
			SH_3D_MODE = 0x0001
		};

		virtual ~IScene(){}
		
        virtual void destroy() = 0;
        
        virtual ICamera::pointer getCamera() = 0;
        virtual void setCamera(ICamera::pointer camera) = 0;

        //virtual Node::pointer getRoot() = 0;

		virtual void setIsActive(bool active) = 0;
		virtual bool getIsActive() = 0;

		virtual void render() = 0;
        virtual	void render(const math::matrix & sceneTransform) = 0; // NOTE: no idea why this is not coming through with IRenderable????
        virtual math::matrix getLastSceneCameraMatrix() = 0;
        
        virtual void setSceneListener(ISceneListener::pointer listener) = 0;

        virtual physics::IPhysicsEngine::pointer getPhysicsEngine() = 0;

        virtual scene::Viewport getViewport() = 0;
        virtual void setViewport(scene::Viewport & viewport) = 0;
        
        virtual void setPlayerConfig(const player::PlayerConfig::weakPointer & config) = 0;
        virtual player::PlayerConfig::weakPointer getPlayerConfig() const = 0;

	protected:
		virtual void setSceneHints(unsigned long flags) = 0;
		
	};

}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

I3DAPI struct I3dIScene;
I3DAPI typedef struct I3dIScene I3dIScene;

I3DAPI void I3dScene_render(long handle);
I3DAPI long I3dScene_getCamera(long handle);
//I3DAPI long I3dScene_getRoot(long handle);
I3DAPI void I3dScene_setIsActive(long handle, int active);
I3DAPI int I3dScene_getIsActive(long handle);

#ifdef __cplusplus
}
#endif


#endif
