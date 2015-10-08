/*
 *  DeviceInfo.h
 *  libim360
 *
 *  Created by Ben Siroshton on 5/6/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _DeviceInfo_h_
#define _DeviceInfo_h_

#include "im360/core/MarbleConfig.h"
#include "im360/math/MathUtils.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace device {

	class ScreenOrientation
	{
	public:
		enum Orientation{
			PORTRAIT,
			PORTRAIT_UPSIDE_DOWN,
			LANDSCAPE_RIGHT,
			LANDSCAPE_LEFT
		};
	private:
		ScreenOrientation(){} // prevent instances of this class
	};
	
    class I3DAPI DeviceInfo : virtual public core::I3dObject
	{
    friend class util::Singleton<DeviceInfo>;
	public:
		typedef core::SharedPointer<DeviceInfo>::pointer pointer;
    		
        static DeviceInfo::pointer create();
        
		virtual ~DeviceInfo();
        virtual std::string getClassName() const;
		
		im360::math::vec3 getUp();
		void setUp(const im360::math::vec3 & up);
		
		im360::math::vec3 getRight();
		void setRight(const im360::math::vec3 & right);
		
		im360::math::vec3 getForward();
		void setForward(const im360::math::vec3 & forward);
		
		void setOrientation(const im360::math::vec3 & forward, const im360::math::vec3 & right, const im360::math::vec3 & up);

        void setScreenOrientation(ScreenOrientation::Orientation orientation);
        ScreenOrientation::Orientation getScreenOrientation();        

		im360::math::matrix getScreenMatrix();		
        float get2DScreenRotation();
        float get2DScreenUprightRotation();
        im360::math::matrix get2DScreenRotationMatrix();
        im360::math::matrix get2DScreenUprightRotationMatrix();
	
    protected:
        DeviceInfo();
        virtual bool init();
        
	private:
		struct Orientation
		{
			im360::math::vec3                   forward;
			im360::math::vec3                   right;
			im360::math::vec3                   up;
            ScreenOrientation::Orientation  screen;
		} _orientation;

	};


}}
#endif
#endif
