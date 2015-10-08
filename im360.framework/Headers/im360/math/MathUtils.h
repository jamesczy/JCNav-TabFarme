/*
 *  MathUtils.h
 *  player
 *
 *  Created by Ben Siroshton on 8/6/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _MathUtils_h_
#define _MathUtils_h_

#include "im360/core/MarbleConfig.h"
#include "im360/scene/Viewport.h"
#include "MathTypes.h"
#include "Ray3.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <math.h>
#include <string>
namespace im360 {
namespace math {
	
	inline float toDegrees(float radians){ return radians * 57.2957795f		/* 57.295.. = 180 / PI */; }
	inline float toRadians(float degrees){ return degrees * 0.0174532925f	/* 0.017..  = PI / 180 */; }
		
	// stupid MSVC is complaining about these.. works great everywhere else...
	//template<typename T> inline T min(T v1, T v2){ return v1<v2?v1:v2; }
	//template<typename T> inline T max(T v1, T v2){ return v1>v2?v1:v2; }

	I3DAPI double rint(double val);
	I3DAPI float rintf(float val);
	
    I3DAPI char lerp(char v1, char v2, float amount);
    I3DAPI int lerp(int v1, int v2, float amount);
    I3DAPI float lerp(float v1, float v2, float amount);
    I3DAPI double lerp(double v1, double v2, double amount);
    I3DAPI vec2 lerp(const vec2 & v1, const vec2 & v2, float amount);
    I3DAPI vec3 lerp(const vec3 & v1, const vec3 & v2, float amount);
    I3DAPI matrix lerp(const matrix & v1, const matrix & v2, float amount);

    I3DAPI char lerpAngle(char v1, char v2, float amount);
    I3DAPI int lerpAngle(int v1, int v2, float amount);
    I3DAPI float lerpAngle(float v1, float v2, float amount);
    I3DAPI double lerpAngle(double v1, double v2, double amount);
    I3DAPI vec2 lerpAngle(const vec2 & v1, const vec2 & v2, float amount);
    I3DAPI vec3 lerpAngle(const vec3 & v1, const vec3 & v2, float amount);

    I3DAPI float getFraction(float v);
		
    I3DAPI matrix identityMatrix();
	I3DAPI std::string matrixToString(const matrix & m);
	I3DAPI std::string matrixVectorsToString(const matrix & m);
 
    Ray3 screenToWorldRay(const matrix & view, float x, float y, const scene::Viewport & viewport, float fov);
    
    I3DAPI Rect<float> getFillRect(core::FillModeType::Type fillMode, Rect<float> & fillArea, Rect<float> & sourceArea);

}}
#endif
#endif

