/*
 *  Debug.h
 *  player
 *
 *  Created by Ben Siroshton on 8/19/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Debug_h_
#define _Debug_h_

#include "im360/core/MarbleConfig.h"
#include "Logger.h"
#include "Thread.h"

#ifdef __cplusplus

#include "assert.h"

#include <stdio.h>
#include <string>
#include <map>

#if defined(I3d_QT)
	#include <QDebug>
	#include <QString>
#endif

#if defined(I3d_ANDROID)
	#include <android/log.h>
#endif

namespace im360 {
namespace util {

	static char __dbgBuffer[1024];

	enum DebugLevel
	{
		DBG_DEBUG,
		DBG_INFO,
		DBG_WARNING,
		DBG_ERROR
	};

    class I3DAPI Debug : virtual public core::I3dObject
	{
	public:
        Debug();

		static const char * levelString(DebugLevel level);
		//static void I3d_debug(DebugLevel level, char * args, ...);

        static long construction(I3dObject * p);
        static long deconstruction(I3dObject * p);

        static void debugDump();

    private:
        typedef std::map<I3dObject*,long> countMap;
        static long _debug_construction_count;
        static async::Mutex _mutex;
        static countMap     _counts;

	};

//#define I3d_debug(level, ...) im360::util::I3d_debug(level, __VA_ARGS__);

#if defined(I3d_QT)
	#define I3d_debug(level, ...) \
	{ \
		QString msg1; \
        msg1.sprintf("[%p][%lu][%s:%d][%s]", dynamic_cast<core::I3dObject*>(this), im360::async::Thread::getCurrentThreadId(), __FUNCTION__, __LINE__, im360::util::Debug::levelString(level)); \
		QString msg2; msg2.sprintf(__VA_ARGS__); \
        qDebug("%s %s", msg1.toStdString().c_str(), msg2.toStdString().c_str()); \
        im360::util::Logger::instance().debug("libim360", "%s %s", msg1.toStdString().c_str(), msg2.toStdString().c_str()); \
	}

	#define I3d_debugF(level, ...) \
	{ \
        QString msg1; \
        msg1.sprintf("[%lu][%s:%d][%s]", im360::async::Thread::getCurrentThreadId(), __FUNCTION__, __LINE__, im360::util::Debug::levelString(level)); \
        QString msg2; msg2.sprintf(__VA_ARGS__); \
        qDebug("%s %s", msg1.toStdString().c_str(), msg2.toStdString().c_str()); \
        im360::util::Logger::instance().debug("libim360", "%s %s", msg1.toStdString().c_str(), msg2.toStdString().c_str()); \
	}
#else
	#if defined(I3d_ANDROID)
        #define logLevelToAndroidLevel(level)(level==im360::util::DBG_ERROR ? ANDROID_LOG_ERROR : (level==im360::util::DBG_WARNING ? ANDROID_LOG_WARN : ANDROID_LOG_INFO))
		#define I3d_debug(level, ...) \
		{ \
			sprintf(im360::util::__dbgBuffer, __VA_ARGS__); \
            __android_log_print(logLevelToAndroidLevel(level), "libim360", "[%p][%lu][%s/%s::%s:%d] %s", dynamic_cast<core::I3dObject*>(this), im360::async::Thread::getCurrentThreadId(), typeid(this).name(), typeid(*this).name(), __FUNCTION__, __LINE__, im360::util::__dbgBuffer);  \
            /* im360::util::Logger::instance().log((im360::util::Logger::LogLevel)level, "libim360", "[%p][%lu][%s::%s:%d] %s", this, im360::async::Thread::getCurrentThreadId(), typeid(*this).name(), __FUNCTION__, __LINE__, im360::util::__dbgBuffer); */ \
		}
		#define I3d_debugF(level, ...) \
		{ \
			sprintf(im360::util::__dbgBuffer, __VA_ARGS__); \
            __android_log_print(logLevelToAndroidLevel(level), "libim360", "[%lu][%s:%d] %s", im360::async::Thread::getCurrentThreadId(), __FUNCTION__, __LINE__, im360::util::__dbgBuffer); \
            /* im360::util::Logger::instance().log((im360::util::Logger::LogLevel)level, "libim360", "[%lu][%s:%d] %s", im360::async::Thread::getCurrentThreadId(), __FUNCTION__, __LINE__, im360::util::__dbgBuffer); */ \
		}
	#else
        #define I3d_debug(level, ...){fprintf(stderr,"[%p][%lu][%s::%s:%d][%s] ", dynamic_cast<core::I3dObject*>(this), im360::async::Thread::getCurrentThreadId(), typeid(*this).name(), __FUNCTION__, __LINE__, im360::util::Debug::levelString(level)); fprintf(stderr,__VA_ARGS__); fprintf(stderr,"\n");}
        #define I3d_debugF(level, ...){fprintf(stderr,"[%lu][%s:%d][%s] ", im360::async::Thread::getCurrentThreadId(), __FUNCTION__, __LINE__, im360::util::Debug::levelString(level)); fprintf(stderr,__VA_ARGS__); fprintf(stderr,"\n");}
	#endif
#endif

#if !defined(DEBUG)
    #undef I3d_debug
    #undef I3d_debugF
	#define I3d_debug(level, ...){}
	#define I3d_debugF(level, ...){}
#endif

#if defined(I3d_DebugGL)
	#define gl(exp) \
	{ \
		while( glGetError()!=GL_NO_ERROR) ; \
		exp; \
		int error = glGetError(); \
        if( error!=GL_NO_ERROR ){ I3d_debug(im360::util::DBG_ERROR,"--OPENGL ERROR w/ASSERT--: %d [0x%x] EXECUTION STOPPED!",error,error); assert(false); } \
	}
	#define glno(exp) \
	{ \
		while( glGetError()!=GL_NO_ERROR) ; \
		exp; \
		int error = glGetError(); \
        if( error!=GL_NO_ERROR ){ I3d_debug(im360::util::DBG_ERROR,"--OPENGL ERROR--: %d [0x%x]",error,error); } \
	}
	#define glF(exp) \
	{ \
		while( glGetError()!=GL_NO_ERROR) ; \
		exp; \
		int error = glGetError(); \
        if( error!=GL_NO_ERROR ){ I3d_debugF(im360::util::DBG_ERROR,"--OPENGL ERROR w/ASSERT--: %d [0x%x] EXECUTION STOPPED!",error,error); assert(false); } \
	}
	#define glFno(exp) \
	{ \
		while( glGetError()!=GL_NO_ERROR) ; \
		exp; \
		int error = glGetError(); \
        if( error!=GL_NO_ERROR ){ I3d_debugF(im360::util::DBG_ERROR,"--OPENGL ERROR--: %d [0x%x]",error,error); } \
	}
#else
	#define gl(exp) exp
	#define glno(exp) exp
	#define glF(exp) exp
	#define glFno(exp) exp
#endif
    
#if defined(I3d_DebugMemory) && defined(DEBUG)
    #define I3d_debug_memory_construction I3d_debug(im360::util::DBG_INFO,"construction: %p", this);
    #define I3d_debug_memory_deconstruction I3d_debug(im360::util::DBG_INFO,"deconstruction: %p", this);
    //#define I3d_debug_memory_construction I3d_debug(im360::util::DBG_INFO,"construction: %d", im360::util::Debug::construction((im360::core::I3dObject*)this) );
    //#define I3d_debug_memory_deconstruction I3d_debug(im360::util::DBG_INFO,"deconstruction: %d", im360::util::Debug::deconstruction((im360::core::I3dObject*)this) );
#else
    #define I3d_debug_memory_construction
    #define I3d_debug_memory_deconstruction
#endif

#if defined(I3d_DebugJNICalls) && defined(DEBUG)
    #define I3d_debug_jni_call { I3d_debugF(im360::util::DBG_INFO,"(jni call)"); }
#else
	#define I3d_debug_jni_call
#endif

}} // end of namespace(s)

#else // not c++
    #undef I3d_debug
    #undef I3d_debugF
    #define I3d_debug(level, ...){}
    #define I3d_debugF(level, ...){}
    #undef I3d_debug_memory_construction
    #undef I3d_debug_memory_deconstruction
    #define I3d_debug_memory_construction
    #define I3d_debug_memory_deconstruction
	#define I3d_debug_jni_call
#endif

#endif
