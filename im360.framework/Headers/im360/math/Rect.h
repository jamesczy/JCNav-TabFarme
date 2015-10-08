/*
 *  Rect.h
 *  marble360
 *
 *  Created by Ben Siroshton on 11/8/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Rect_h_
#define _Rect_h_

#include "im360/util/Debug.h"
#include "MathTypes.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace math {

	template <typename T> class Rect
	{
	public:
		Rect()
		{
            //I3d_debug_memory_construction
		}
		
		Rect(const Rect<T> & rect)
		{
            //I3d_debug_memory_construction

			_left = rect._left;
			_top = rect._top;
			_right = rect._right;
			_bottom = rect._bottom;		
		}
		
		virtual ~Rect()
		{
            //I3d_debug_memory_deconstruction
		}
		
        virtual std::string getClassName() const
        {
            return "im360.math.Rect";
        }

		void zero()
		{
			_top = _left = _right = _bottom = 0;
		}
		
		void setXYWH(T x, T y, T width, T height)
		{
			_left = x;
			_top = y;
			_right = x + width;
			_bottom = y + height;
		}
		
		void setTLRB(T top, T left, T right, T bottom)
		{
			_top = top;
			_left = left;
			_right = right;
			_bottom = bottom;
		}

		void moveBy(T x, T y)
		{
			_left += x;
			_right += x;
			_top += y;
			_bottom += y;
		}

        void scale(float scale)
        {
            setXYWH((float)getCenterX() - (float)getHalfWidth() * scale,
                    (float)getCenterY() - (float)getHalfHeight() * scale,
                    (float)getWidth() * scale,
                    (float)getHeight() * scale);
        }
        
        void scale(double scale)
        {
            setXYWH((double)getCenterX() - (double)getHalfWidth() * scale,
                    (double)getCenterY() - (double)getHalfHeight() * scale,
                    (double)getWidth() * scale,
                    (double)getHeight() * scale);
        }

		T getX() const
		{
			return _left;
		}
		
		void setX(T x)
		{
			_left = x;
		}
		
		T getY() const
		{
			return _top;
		}
		
		void setY(T y)
		{
			_top = y;
		}
		
		T getWidth() const
		{
            T w = _right - _left;
            return w < 0 ? -w : w;
		}
				
		T getHalfWidth() const
		{
            return getWidth() / 2;
		}

		void setWidth(T width)
		{
			_right = _left + width;
		}
		
		T getHeight() const
		{
            T h = _bottom - _top;
            return h < 0 ? -h : h;
        }
		
		T getHalfHeight() const
		{
			return getHeight() / 2;
		}
        
		void setHeight(T height)
		{
			_bottom = _top + height;
		}

		T getTop() const
		{
			return _top;
		}
				
		void setTop(T top)
		{
			_top = top;
		}
		
		T getLeft() const
		{
			return _left;
		}
		
		void setLeft(T left)
		{
			_left = left;
		}
		        
		T getRight() const
		{
			return _right;
		}
		
		void setRight(T right)
		{
			_right = right;
		}
				
		T getBottom() const
		{
			return _bottom;
		}
		
		void setBottom(T bottom)
		{
			_bottom = bottom;
		}
                
        im360::math::vec2 getTopLeft() const
        {
            return im360::math::vec2(_left, _top);
        }

        im360::math::vec2 getTopRight() const
        {
            return im360::math::vec2(_right, _top);
        }

        im360::math::vec2 getBottomLeft() const
        {
            return im360::math::vec2(_left, _bottom);
        }
        
        im360::math::vec2 getBottomRight() const
        {
            return im360::math::vec2(_right, _bottom);
        }
        
        T getCenterX() const
        {
            return getX() + getWidth() * 0.5f;
        }

        T getCenterY() const
        {
            return getY() + getHeight() * 0.5f;
        }
		
        im360::math::vec2 getCenter() const
        {
            return im360::math::vec2(getCenterX(), getCenterY());
        }

        Rect<T> getTopHalf() const
        {
            return Rect<T>::fromTLRB(_top, _left, _right, _top * 0.5 + _bottom * 0.5);
        }

        Rect<T> getBottomHalf() const
        {
            return Rect<T>::fromTLRB(_top * 0.5 + _bottom * 0.5, _left, _right, _bottom);
        }

        Rect<T> getLeftHalf() const
        {
            return Rect<T>::fromTLRB(_top, _left, _left * 0.5 + _right * 0.5, _bottom);
        }

        Rect<T> getRightHalf() const
        {
            return Rect<T>::fromTLRB(_top, _left * 0.5 + _right * 0.5, _right, _bottom);
        }

		void expand(const Rect<T> & rect)
		{
			_left = I3d_min(_left, rect.getLeft());
			_top = I3d_min(_top, rect.getTop());
			_right = I3d_max(_right, rect.getRight());
			_bottom = I3d_max(_bottom, rect.getBottom());
		}

		bool contains(T x, T y) const
		{
			if( x<_left ) return false;
			if( x>_right ) return false;
			if( y<_top ) return false;
			if( y>_bottom ) return false;
			
			return true;
		}

		bool contains(const im360::math::vec2 & point) const
		{
            return contains(point[0], point[1]);
		}

        bool equals(T left, T top, T right, T bottom)
        {
            return _left==left && _top==top && _right==right && _bottom!=bottom;
        }

		// TODO: bool intersects(const Rect<T> & rect);

		static Rect<T> fromXYWH(T x, T y, T width, T height)
		{
			Rect<T> r;
			r.setXYWH(x,y,width,height);
			return r;					  
		}
		
		static Rect<T> fromTLRB(T top, T left, T right, T bottom)
		{
			Rect<T> r;
			r.setTLRB(top,left,right,bottom);
			return r;
		}
		
	private:
		T _left;
		T _top;
		T _right;
		T _bottom;
		
	};

}}
#endif
#endif

