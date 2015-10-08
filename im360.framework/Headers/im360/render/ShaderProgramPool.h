/*
 *  ShaderProgramPool.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 12/1/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _ShaderProgramPool_h_
#define _ShaderProgramPool_h_

#include "im360/util/Singleton.h"
#include "ShaderProgram.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <map>
#include <string>
namespace im360 {
namespace render {

    class I3DAPI ShaderProgramPool : virtual public core::I3dObject, virtual public util::Singleton<ShaderProgramPool>
	{
    friend class util::Singleton<ShaderProgramPool>;
	public:
		typedef core::SharedPointer<ShaderProgramPool>::pointer pointer;
		~ShaderProgramPool();
        virtual std::string getClassName() const;
		
        ShaderProgram::pointer getShader(std::string vertexFile, std::string fragmentFile);
		
		void setRootPath(std::string path);
		std::string getRootPath();
		
		void clear();
        void clearAll();

    protected:
        ShaderProgramPool();
        
	private:
        typedef std::map<std::string, ShaderProgram::pointer>	ShaderPoolList;
        typedef ShaderPoolList::iterator                        ShaderPoolIterator;
		
        typedef std::map<long, ShaderPoolList>                  ContextPool;

        ContextPool _pool;
        std::string _rootPath;
		
        void createDefaultShaders();
        ShaderProgram::pointer createShader(std::string vertexKey, std::string vertexSource, std::string fragmentKey, std::string fragmentSource);
	};
	
}}
#endif
#endif
