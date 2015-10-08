#ifndef _ViewPort_h_
#define _ViewPort_h_

#include "im360/core/MarbleConfig.h"
#include "im360/math/Rect.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

    class I3DAPI Viewport : virtual public im360::math::Rect<float>
	{
	public:
		Viewport();
		virtual ~Viewport();

		void applyViewport();

        im360::math::vec2 screenToOrtho(const im360::math::vec2 & screen) const;
        im360::math::vec2 orthoToScreen(const im360::math::vec2 & ortho) const;
        im360::math::Rect<float> screenToOrtho(const im360::math::Rect<float> & screen) const;
        im360::math::Rect<float> orthoToScreen(const im360::math::Rect<float> & ortho) const;

        static Viewport fromRect(const im360::math::Rect<float> & rect);
	};

}}
#endif
#endif
