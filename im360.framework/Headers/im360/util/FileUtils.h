/*
 *  FileUtils.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 3/8/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _FileUtils_h_
#define _FileUtils_h_

#include "im360/core/MarbleConfig.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
#include <vector>
namespace im360 {
namespace file {

	I3DAPI bool isDirectory(std::string path);
	I3DAPI bool fileExists(std::string path, bool * isDirectory=NULL);
	I3DAPI bool createDirectory(std::string path, bool createRecursive=true);
	I3DAPI unsigned long getFileSize(std::string file);
	I3DAPI bool copyFile(std::string source, std::string destination, bool overwriteExisting=false);
	I3DAPI bool renameFile(std::string source, std::string destination, bool overwriteExisting=false);
	I3DAPI bool deleteFile(std::string path, bool deleteRecursive=false);
	I3DAPI int getFiles(std::string path, std::vector<std::string> & list);
	I3DAPI bool isNameValidForFile(std::string name);
    I3DAPI bool isRemoteFile(const std::string & path);
    I3DAPI std::string getTempFile(const std::string & extension = std::string(""));

    I3DAPI bool markForBackup(std::string path, bool backup);
    I3DAPI bool markForBackup(std::string path, bool backup, bool recursive);

}}
#endif
#endif
