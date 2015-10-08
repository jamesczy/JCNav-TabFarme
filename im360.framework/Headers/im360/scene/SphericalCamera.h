/*
 *  SphericalCamera.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 11/23/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */


#ifndef _SphericalCamera_h_
#define _SphericalCamera_h_

#include "Camera.h"
#include "im360/math/Interval.h"
#include "im360/component/RotationLimiter.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

	class I3DAPI SphericalCamera : virtual public Camera
	{
	public:
		typedef core::SharedPointer<SphericalCamera>::pointer pointer;

		static SphericalCamera::pointer create();

		virtual ~SphericalCamera();
		virtual std::string getClassName() const;

        component::RotationLimiter::pointer getRotationLimiter();

        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);

	protected:
		SphericalCamera();
        virtual bool init();
		
        virtual void onItemAdded(component::ComponentBase::pointer item);

	private:
        component::RotationLimiter::pointer	_rotationLimiter;

	};
	
}}
#endif
#endif
