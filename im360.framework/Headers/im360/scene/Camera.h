/*
 *  Camera.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on ...
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Camera_h_
#define _Camera_h_

#include "ICamera.h"
#include "Node.h"
#include "im360/math/Interval.h"
#include "im360/math/Ray3.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

	class I3DAPI Camera : virtual public ICamera
	{
	public:
        typedef core::SharedPointer<Camera>::pointer pointer;

        static Camera::pointer create();
        
		virtual ~Camera();
        virtual std::string getClassName() const;

		im360::math::matrix getProjection(Viewport & viewport);
		im360::math::matrix getProjectionOrtho(Viewport & viewport);
		im360::math::matrix getView(Viewport & viewport);

		float	getFov();
		void	setFov(float f);

		im360::math::Interval<float> getFovRange();
		void setFovRange(im360::math::Interval<float> range);
		float getFovRangeMin();
		void setFovRangeMin(float min);
		float getFovRangeMax();
		void setFovRangeMax(float max);
		
		float	getNear();
		void	setNear(float n);

		float	getFar();
		void	setFar(float f);
		
		void	applyViewport();

		im360::math::Ray3 screenToRay(float x, float y, Viewport & viewport);
		im360::math::Ray3 screenToWorldRay(float x, float y, Viewport & viewport);

        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);

    protected:
        Camera();
        virtual bool init();

	private:
		im360::math::matrix	_projection;
		im360::math::matrix	_projectionOrtho;
		bool			_isProjectionDirty;

		float						_fov;
		im360::math::Interval<float>	_fovRange;
		
		float		_near;
		float		_far;

	};

}}
#endif
#endif

