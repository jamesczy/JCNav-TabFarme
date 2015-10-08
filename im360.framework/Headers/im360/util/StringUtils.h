/*
 *  StringUtils.h
 *  player
 *
 *  Created by Ben Siroshton on 8/25/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _StringUtils_h_
#define _StringUtils_h_

#include "im360/core/MarbleConfig.h"
#include "im360/math/MathTypes.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
#include <vector>
namespace im360 {
namespace string {

    I3DAPI struct TimeFlags
    {
        static const int MicroSeconds = 1;
    };

	// parsing
	I3DAPI bool startsWith(std::string source, std::string search, bool caseSensitive=true);
	I3DAPI bool endsWith(std::string source, std::string search, bool caseSensitive=true);

	I3DAPI std::string toLowercase(std::string str);
	I3DAPI std::string toUppercase(std::string str);

	I3DAPI std::string trim(std::string str, std::string seq=" ");
    I3DAPI std::string repeat(std::string str, unsigned int count);
					 
	I3DAPI int strPos(std::string str, std::string seq);
	
	I3DAPI unsigned int tokenize(std::vector<std::string> & tokens, std::string str, std::string delimiter);

    // replacing
    I3DAPI std::string replaceAll(std::string source, std::string search, std::string replace);
    
	// conversions
    I3DAPI std::string fromCStr(char * str);
	I3DAPI bool isNumeric(std::string str);

	I3DAPI std::string fromFloat(float value);
	I3DAPI float toFloat(std::string str, float default_=0.f);
	
	I3DAPI std::string fromDouble(double value);
	I3DAPI double toDouble(std::string str, double default_=0.f);

	I3DAPI std::string fromInt(int value);
    I3DAPI std::string fromUInt(unsigned int value);
	I3DAPI int toInt(std::string str, int default_=0);

	I3DAPI std::string fromLong(long value);
	I3DAPI long toLong(std::string str, long default_=0);

    I3DAPI std::string fromLongLong(long long value);
    I3DAPI long long toLongLong(std::string str, long long default_=0);

	I3DAPI std::string fromULong(unsigned long value);
	I3DAPI unsigned long toULong(std::string str, unsigned long default_=0);    

	I3DAPI bool isBoolean(std::string str);
	I3DAPI std::string fromBoolean(bool value);
	I3DAPI bool toBoolean(std::string str, bool default_=false);

    I3DAPI std::string fromPtr(void * ptr);

    // time
    I3DAPI std::string secondsToTime(float seconds, int flags=0);

	// misc
	I3DAPI std::string byteSizeToString(unsigned long byteSize);
	I3DAPI unsigned long getHash(std::string str);

	// file names paths
	I3DAPI std::string getFileExtension(std::string file);
	I3DAPI std::string getFilePath(std::string file);
	I3DAPI std::string getFilePart(std::string file);
    I3DAPI std::string getFilePartWithoutExtension(std::string file);
	I3DAPI std::string cleanPath(std::string path, bool platformSpecific=false);
    I3DAPI std::string resolvePath(std::string from, std::string to);

    // url paths
    I3DAPI std::string getURLPath(std::string url);
    
	// reading writing
    I3DAPI std::string fromFile(std::string file);
    I3DAPI std::string fromFile(std::string file, bool * succeeded);
	I3DAPI std::string fromFile(FILE * file);
	I3DAPI unsigned int readLinesFromFile(std::vector<std::string> & lines, std::string file, bool skipEmptyLines=true);
	
    I3DAPI bool toFile(std::string str, std::string path);
	I3DAPI unsigned int toFile(std::string str, FILE * file);

	I3DAPI unsigned int toMem(std::string str, void * ptr, unsigned int bufferSize);
	I3DAPI std::string fromMem(void * ptr);

    // argument conversion
    I3DAPI int stringToArgs(std::string argStr, char *** args, const char * delimiter = " ");
    I3DAPI void freeArgs(char *** args, int argCount);

}}
#endif
#endif
