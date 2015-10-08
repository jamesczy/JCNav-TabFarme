#ifndef _Test3DScene_h_
#define _Test3DScene_h_

#include "im360/core/MarbleConfig.h"
#include "BasicScene.h"
#include "PlaneNode.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace scene {

    class I3DAPI Test3DScene : virtual public BasicScene
	{
	public:
        typedef core::SharedPointer<Test3DScene>::pointer pointer;

        static Test3DScene::pointer create();
        
		virtual ~Test3DScene();
        virtual std::string getClassName() const;

		virtual void render(const im360::math::matrix & sceneTransform);

	private:
        Test3DScene();
        virtual bool init();

        std::vector<PlaneNode::pointer> _sprites;

        void createSprites();

	};

}}
#endif
#endif

