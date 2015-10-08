/*
 *  HumanInput.h
 *  player
 *
 *  Created by Ben Siroshton on 8/16/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _HumanInput_h_
#define _HumanInput_h_

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace input {

	enum HumanInputState
	{
		HIS_UNKNOWN,
		HIS_STARTED,
		HIS_CHANGED,
        HIS_ENDED
	};
	
	struct TapData
	{
		int x;
		int y;
		int numberOfPoints;
	};

	struct PanData
	{
		HumanInputState state;
		int x;
		int y;
		int lastX;
		int lastY;
	};

	struct PinchData
	{
		HumanInputState state;
		float scale;
	};

	class I3DAPI IInputHandler
	{
	public:
        typedef core::SharedPointer<IInputHandler>::pointer pointer;

        virtual ~IInputHandler(){}
		virtual void tap(TapData d) = 0;
		virtual void pinch(PinchData d) = 0;
		virtual void pan(PanData d) = 0;
	};
	
}}
#endif
#endif

