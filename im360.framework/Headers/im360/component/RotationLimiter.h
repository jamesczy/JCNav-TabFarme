/*
 *  RotationLimiter.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _RotationLimiter_h_
#define _RotationLimiter_h_

#include "ComponentBase.h"
#include "im360/math/Interval.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace component {

	class I3DAPI RotationLimiter : virtual public ComponentBase
	{
	public:
        typedef core::SharedPointer<RotationLimiter>::pointer pointer;

        static RotationLimiter::pointer create();
		virtual ~RotationLimiter();
        virtual std::string getClassName() const;

		void setRotationRangeX(im360::math::Interval<float> range);
		im360::math::Interval<float> getRotationRangeX();

		void setRotationRangeY(im360::math::Interval<float> range);
		im360::math::Interval<float> getRotationRangeY();

		void setRotationRangeZ(im360::math::Interval<float> range);
		im360::math::Interval<float> getRotationRangeZ();

        float getRotationMinX();
        void setRotationMinX(float min);
        float getRotationMaxX();
        void setRotationMaxX(float max);

        float getRotationMinY();
        void setRotationMinY(float min);
        float getRotationMaxY();
        void setRotationMaxY(float max);

        float getRotationMinZ();
        void setRotationMinZ(float min);
        float getRotationMaxZ();
        void setRotationMaxZ(float max);

        void setRotationRangeXEnabled(bool enabled);
		bool getRotationRangeXEnabled();

		void setRotationRangeYEnabled(bool enabled);
		bool getRotationRangeYEnabled();

		void setRotationRangeZEnabled(bool enabled);
		bool getRotationRangeZEnabled();

	protected:
        RotationLimiter();
        virtual bool init();

		void onUpdate();

	private:
		im360::math::Interval<float>	_rangeX;
		im360::math::Interval<float>	_rangeY;
		im360::math::Interval<float>	_rangeZ;

		bool _enabledX;
		bool _enabledY;
		bool _enabledZ;

	};

}}
#endif
#endif
