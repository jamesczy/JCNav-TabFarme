/*
 *  Transform.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _Transform_h_
#define _Transform_h_

#include "im360/core/MarbleConfig.h"
#include "MathTypes.h"
#include "ITransformListener.h"
#include "im360/event/EventDispatcher.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace math {

    class I3DAPI Transform : virtual public event::EventDispatcher
	{
	public:
        typedef core::SharedPointer<Transform>::pointer pointer;

        static Transform::pointer create();
		virtual ~Transform();
        virtual std::string getClassName() const;

		float getX() const;
		void setX(float x);

		float getY() const;
		void setY(float y);

		float getZ() const;
		void setZ(float z);

        vec3 getPosition() const;
        void setPosition(const vec3 & pos);
		void setPosition(float x, float y, float z);

		float getRotationX() const;
		void setRotationX(float x);

		float getRotationY() const;
		void setRotationY(float y);

		float getRotationZ() const;
		void setRotationZ(float z);

        vec3 getRotation() const;
        void setRotation(const vec3 & rot);
		void setRotation(float rx, float ry, float rz);

		float getScaleX() const;
		void setScaleX(float scale);

		float getScaleY() const;
		void setScaleY(float scale);

		float getScaleZ() const;
		void setScaleZ(float scale);

        vec3 getScale() const;
        void setScale(const vec3 & scale);
		void setScale(float sx, float sy, float sz);
        void setUniformScale(float scale);

        vec3 getUp();
        
        void lookAt(const vec3 & target, const vec3 & up);
        
        matrix getMatrix();
        void fromMatrix(const matrix & mx);

		void setListener(ITransformListener * listener);
		ITransformListener * getListener();

        // I3dObject
        util::Variant evaluate(const util::Command & command);
        
    protected:
		Transform();
        Transform(const matrix & m);
        
        virtual void onPositionChange();
        virtual void onScaleChange();
        virtual void onRotationChange();

	private:
        matrix	_transform;
        bool    _isTransformDirty;

        vec3    _rotation;
        vec3    _translation;
        vec3    _scale;

		ITransformListener *	_listener;

	};

}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

I3DAPI float I3dTransform_getX(long handle);
I3DAPI void I3dTransform_setX(long handle, float x);
I3DAPI float I3dTransform_getY(long handle);
I3DAPI void I3dTransform_setY(long handle, float y);
I3DAPI float I3dTransform_getZ(long handle);
I3DAPI void I3dTransform_setZ(long handle, float z);
I3DAPI void I3dTransform_setPosition(long handle, float x, float y, float z);

I3DAPI float I3dTransform_getRotationX(long handle);
I3DAPI void I3dTransform_setRotationX(long handle, float x);
I3DAPI float I3dTransform_getRotationY(long handle);
I3DAPI void I3dTransform_setRotationY(long handle, float y);
I3DAPI float I3dTransform_getRotationZ(long handle);
I3DAPI void I3dTransform_setRotationZ(long handle, float z);
I3DAPI void I3dTransform_setRotation(long handle, float x, float y, float z);

#ifdef __cplusplus
}
#endif

#endif

