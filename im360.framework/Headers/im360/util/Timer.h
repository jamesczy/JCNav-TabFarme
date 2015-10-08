/*
 *  Timer.h
 *  player
 *
 *  Created by Ben Siroshton on 8/11/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Timer_h_
#define _Timer_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace util {

    class I3DAPI Timer
	{
		
	public:		
		Timer();
		virtual ~Timer();
		
		void start(bool reset=false);
		void pause(bool reset=false);
		void setPaused(bool paused);
		void reset(bool pause=false);
		
		bool isPaused();
		
		unsigned long getMilliseconds();
		float getSeconds();
		
		static unsigned long long getNow();
		static double getNowSeconds();
		
	private:
		unsigned long long	_startTime;
		unsigned long long	_lastTime;
		unsigned long		_milliseconds;
		bool				_isPaused;
		
		void update();
	
	};
	
}}
#endif
#endif
