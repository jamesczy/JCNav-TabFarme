/*
 *  Url.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 05/27/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Url_h_
#define _Url_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace net {

	class I3DAPI Url
	{
	public:
		Url();
		Url(std::string url);
		virtual ~Url();
        virtual std::string getClassName() const;

		std::string getProtocol();
		std::string getHost();
		unsigned int getPort();
		std::string getPath();
		std::string getFile();
		std::string getQuery(bool encode=false);

        std::string getRootUrl();
		std::string getFilePath();
		std::string toString();
        
        Url resolvePath(const std::string & path);
        
        bool isValid();

		static Url parse(std::string url);
		static std::string encodeParam(std::string param);

	private:
		std::string		_protocol;
		std::string		_host;
		unsigned int	_port;
		std::string		_path;
		std::string		_file;
		std::string		_query;
        
        bool            _isValid;

	};

}}
#endif
#endif
