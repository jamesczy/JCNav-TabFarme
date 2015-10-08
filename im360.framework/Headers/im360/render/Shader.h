/*
 *  Shader.h
 *  player
 *
 *  Created by Ben Siroshton on 8/10/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Shader_h_
#define _Shader_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"
#include "im360/resource/Resource.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace render {

    enum ShaderType
	{
		VERTEX_SHADER,
        FRAGMENT_SHADER
	};
	
    class I3DAPI Shader : virtual public core::I3dObject, virtual public resource::Resource
	{	
	friend class ShaderProgram;

	public:
        typedef core::SharedPointer<Shader>::pointer pointer;

        static Shader::pointer create(ShaderType type);
        static Shader::pointer create(ShaderType type, std::string source);
        
		virtual ~Shader();
        virtual std::string getClassName() const;
		
		ShaderType	getType();
		std::string	getSource();

        static Shader::pointer fromSource(ShaderType type, std::string source);

        // IResource interface
        virtual resource::IResource::RestoreResult restoreResource(unsigned int restoreCount);

    protected:
        Shader();
        virtual bool init(ShaderType type);
        virtual bool init(ShaderType type, std::string source);

	private:
		unsigned int	_glShader;
		ShaderType		_type;
		std::string		_source;
	
		bool initShader(ShaderType type, std::string source);

	};

}}
#endif
#endif
