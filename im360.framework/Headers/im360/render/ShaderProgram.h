/*
 *  ShaderProgram.h
 *  player
 *
 *  Created by Ben Siroshton on 8/10/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _ShaderProgram_h_
#define _ShaderProgram_h_

#include "im360/core/MarbleConfig.h"
#include "im360/math/MathUtils.h"
#include "im360/core/Pointer.h"
#include "im360/resource/Resource.h"
#include "Shader.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
#include <string>
namespace im360 {
namespace render {

    class I3DAPI ShaderVariables
	{
	public:
		// set the values in ShaderProgram.cpp
		static const char * const sceneTransform;
		static const char * const xyz;
		static const char * const xy;
		static const char * const uv;
        static const char * const alpha;
    private:
        ShaderVariables(){} // don't allow construction of this class
	};

    class I3DAPI ShaderProgram : virtual public core::I3dObject, virtual public resource::Resource
	{		
	public:
        typedef core::SharedPointer<ShaderProgram>::pointer pointer;

		static ShaderProgram::pointer create();
		virtual ~ShaderProgram();
        virtual std::string getClassName() const;
		
        void attachShader(Shader::pointer shader);
        void detachShader(Shader::pointer shader);
        Shader::pointer detachShaderAtIndex(unsigned int index);
        Shader::pointer getShaderAtIndex(unsigned int index);
		unsigned int getShaderCount();

		int getAttribLocation(std::string name);
		int getUniformLocation(std::string name);
		
		void bindAttribLocation(unsigned int index, std::string name);
		
        void setUniformFloat(unsigned int location, float value);
        void setUniformMatrix4(unsigned int location, const math::matrix & m);
		
		void useProgram();
		bool linkProgram();
		bool isValid();

		unsigned int getGlHandle();

        // IResource interface
        virtual resource::IResource::RestoreResult restoreResource(unsigned int restoreCount);

    protected:
        ShaderProgram();
        virtual bool init();
        
	private:
        typedef std::list<Shader::pointer>	shaderList;
		
        struct Attribute
        {
        	unsigned int 	index;
        	std::string		name;
        };

        unsigned int			_glProgram;
        shaderList 				_shaders;
        std::vector<Attribute>	_attributes;

	};
	
}}
#endif
#endif
