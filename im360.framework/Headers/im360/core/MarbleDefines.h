/*
 *  MarbleDefines.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 3/20/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _MarbleDefines_h_
#define _MarbleDefines_h_

#define I3d_VERSION "0.5.5"

// Debug defines
#define I3d_DebugGL
//#define I3d_DebugMemory
//#define I3d_DebugJNICalls
//#define I3d_NO_PHYSICS

#if !defined(DEBUG)
	#define QT_NO_DEBUG_OUTPUT
	#undef I3d_DebugGL
	#undef I3d_DebugMemory
	#undef I3d_DebugJNICalls
#endif

#if defined(QT_CORE_LIB)
	#undef I3d_QT
	#define I3d_QT
#endif

#if defined(__ANDROID__)
	#define I3d_ANDROID
#endif

// what os?
#if defined(_WIN32) || defined(WIN32)
	#define I3d_WINDOWS
#elif defined(__APPLE__) || defined(__APPLE_CC__)
	#include <TargetConditionals.h>
	#define I3d_APPLE
#endif

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
	#define I3d_IOS
#elif defined(I3d_APPLE)
	#define I3d_MAC
#endif

#if TARGET_IPHONE_SIMULATOR
	#error : Building for the simulator is not supported at this time.
#endif

#if defined(I3d_EXPORT)
	#define I3DAPI __declspec(dllexport)
#else
	#define I3DAPI __declspec(dllimport)
#endif

#if defined(I3d_APPLE) || defined(I3d_ANDROID)
	#undef I3DAPI
	#define I3DAPI
#endif

#if defined(I3d_MAC)
	#define I3d_NO_OPENSLES
#endif

#if defined(I3d_WINDOWS)
	#define I3d_NO_OPENSLES
    #define I3d_NO_EGL
#endif

#if defined(I3d_IOS)
	#define I3d_NO_OPENSLES
	#define I3d_NO_THEORA
    #define I3d_MOBILE
#endif

#if defined(I3d_ANDROID)
	#define I3d_NO_THEORA
	#define I3d_NO_FMOD
	//#define I3d_NO_JSCONCPP
    #define I3d_MOBILE
	//#define I3d_NO_PHYSICS
	//#define GL_TEXTURE_EXTERNAL_OES  // this SHOULD defined by default using ndk-build
#endif

#if !defined(I3d_WINDOWS)
    #define I3d_TR1_DIR
#endif

#endif
