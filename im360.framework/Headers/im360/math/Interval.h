/*
 *  Interval.h
 *  libim360
 *
 *  Created by Ben Siroshton on 05/02/11.
 *  Copyright 2010 Immersive Media. All rights reserved.
 *
 */

#ifndef _Interval_h_
#define _Interval_h_

#include "MathUtils.h"
#include "im360/util/Debug.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace math {

	template <typename T> class Interval
	{
	public:
		Interval()
		{
            //I3d_debug_memory_construction

			_min = _max = 0;
		}

		Interval(T v1, T v2)
		{
            //I3d_debug_memory_construction

			set(v1, v2);
		}

        virtual std::string getClassName() const
        {
            return "im360.math.Interval";
        }

        virtual ~Interval()
        {
            //I3d_debug_memory_deconstruction
        }

		bool contains(T val)
		{
			return val>=_min && val<=_max;
		}

		void expand(T val)
		{
			if( val<_min ) _min = val;
			if( val>_max ) _max = val;
		}

		void set(T v1, T v2)
		{
			_min = I3d_min(v1,v2);
			_max = I3d_max(v1,v2);
		}
		
		void setMin(T min)
		{
			_min = min;
			if( _max<_min ) _max = _min;
		}

		void setMax(T max)
		{
			_max = max;
			if( _min>_max ) _min = _max;
		}

		T length()
		{
			return _max - _min;
		}

		T wrap(T val)
		{
			T len = length();
			if( len==0 ) return _min;

			while( val<_min )
			{
				val += len;
			}
			while( val>_max )
			{
				val -= len;
			}
			return val;
		}

		T lerpWrap(T from, T to, float factor)
		{			
			T len = I3d_max(from,to) - I3d_min(from,to);

            if( len<length()/2 ) return lerp(from, to, factor);
	
			len = length();

			if( from<to ) to-=len;
			else to+=len;

            return wrap(lerp(from, to, factor));
		}

		T clamp(T val)
		{
			if( val<_min ) return _min;
			if( val>_max ) return _max;
			return val;
		}

		T lerp(float factor)
		{
			float v1 = (float)_min;
			float v2 = (float)_max;
			float inv = 1.f - factor;
			return (T)(v1 * inv + v2 * factor);			
		}
		
		void scale(T scl)
		{
			_min *= scl;
			_max *= scl;
		}

        float getPos(T value)
        {
            float len = (float)length();
            if( len==0 ) return 0;
            return (float)(value-_min)/len;
        }

		T getMin()
		{
			return _min;
		}

		T getMax()
		{
			return _max;
		}
		
		bool split(T val, Interval<T> * first, Interval<T> * second)
		{
			if( !contains(val) ) return false;
			if( first ) first->set(_min, val);
			if( second ) second->set(val, _max);
			return true;
		}

		static T clamp(T val, T min, T max)
		{
			if( val<min ) return min;
			if( val>max ) return max;
			return val;
		}

		static T wrap(T val, T min, T max)
		{
			Interval i(min, max);
			return i.wrap(val);
		}

		static T lerp(T min, T max, float factor)
		{
			Interval i(min, max);
			return i.lerp(factor);
		}

		static T lerpWrap(T min, T max, T from, T to, float factor)
		{
			Interval i(min, max);
			return i.lerpWrap(from, to, factor);
		}
		
	private:
		T _min;
		T _max;

	};

}}
#endif
#endif
