#ifndef _IRenderable_h_
#define _IRenderable_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

    class I3DAPI IRenderable
	{
	public:
        typedef core::SharedPointer<IRenderable>::pointer pointer;

		virtual ~IRenderable(){}
        virtual void render(const math::matrix & worldTransform) = 0;
    
	};

}}
#endif
#endif
