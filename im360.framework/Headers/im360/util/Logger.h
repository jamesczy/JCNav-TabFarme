/*
 *  Logger.h
 *  libim360
 *
 *  Created by Ben Siroshton on 12/22/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _libim360_Logger_h_
#define _libim360_Logger_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/I3dObject.h"
#include "Singleton.h"
#include "Thread.h"

#define FILE_TAG __FILE__ ":" __LINE__

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
#include <stdio.h>
namespace im360 {
namespace util {

    class I3DAPI Logger : virtual public core::I3dObject, virtual public util::Singleton<Logger>
	{
    friend class util::Singleton<Logger>;
	public:
    	typedef core::SharedPointer<Logger>::pointer pointer;

    	enum LogLevel
    	{
    		LL_DEBUG,
    		LL_INFO,
    		LL_WARNING,
    		LL_ERROR
    	};

        virtual ~Logger();
        virtual std::string getClassName() const;

        bool open(const std::string & file, bool overwrite=true);

        void debug(const char * tag, const char * format, ...);
        void info(const char * tag, const char * format, ...);
        void warn(const char * tag, const char * format, ...);
        void error(const char * tag, const char * format, ...);
        void log(LogLevel level, const char * tag, const char * format, ...);

    protected:
		Logger();

	private:
        //class Data;
        //Data * _data;
        std::string     _file;
        async::Mutex	_mutex;

        bool write(const std::string & str);
	};

}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

I3DAPI int I3dLogger_open(const char * file, int overwrite);

#ifdef __cplusplus
}
#endif

#endif
