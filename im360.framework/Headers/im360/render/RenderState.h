/*
 *  RenderState.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/22/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _RenderState_h_
#define _RenderState_h_

#include "im360/core/MarbleConfig.h"
#include "im360/util/Singleton.h"
#include "im360/math/MathTypes.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace render {

    class I3DAPI RenderState : virtual public core::I3dObject
	{
	public:
        typedef core::SharedPointer<RenderState>::pointer pointer;

        static RenderState::pointer create();
        virtual ~RenderState();
        virtual std::string getClassName() const;

		void setProjection(const im360::math::matrix & projection);
		im360::math::matrix & getProjection();

		void setScreenProjection(const im360::math::matrix & projection);
		im360::math::matrix & getScreenProjection();

    protected:
		RenderState();
        virtual bool init();

	private:
		im360::math::matrix	_projection;
		im360::math::matrix	_screenProjection;
	};

}}
#endif
#endif

