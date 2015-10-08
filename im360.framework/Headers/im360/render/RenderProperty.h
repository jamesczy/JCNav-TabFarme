/*
 *  RenderProperty.h
 *  marble360
 *
 *  Created by Ben Siroshton on 11/9/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _RenderProperty_h_
#define _RenderProperty_h_

#include "im360/core/MarbleConfig.h"
#include "im360/math/MathUtils.h"
#include "im360/util/Debug.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace render {
	
	class I3DAPI IRenderPropertyBase
	{
	public:
        typedef core::SharedPointer<IRenderPropertyBase>::pointer pointer;

		virtual ~IRenderPropertyBase(){}
		virtual std::string getName() = 0;
		virtual void apply() = 0;
	protected:
		virtual void applyValue() = 0;
	};
	
	template <typename T, unsigned int Count> class RenderProperty : virtual public core::I3dObject, virtual public IRenderPropertyBase
	{
    friend class RenderPass;
	public:
		virtual ~RenderProperty()
		{
		}
		
        virtual std::string getClassName() const
        {
            return "im360.render.RenderProperty";
        }

		std::string getName()
		{
			return _name;
		}
		
		T getValue(unsigned int index=0)
		{
			return _value[index];
		}
		
		void setValue(T value, unsigned int index=0)
		{
			_value[index] = value;
		}
		
		void setValues(unsigned int count, ...)
		{
			assert(count<Count);
			
			va_list values;
			va_start(values, count); 
			
			for(unsigned int index=0;index<count;index++)
				_value[index] = va_arg(values, T);
			
			va_end(values);
		}
		
		unsigned int getElementCount()
		{
			return Count;
		}
		
		void apply()
		{
			applyValue();
		}
		
	protected:
		RenderProperty() : I3dObject()
		{
		}
		
		void init(T value, std::string name="")
		{
			_name = name;
			_value[0] = value;
		}
		
		void init(std::string name, unsigned int count, ...)
		{
			assert(count>=Count);
			
			_name = name;
			
			va_list values;
			va_start(values, count);
			
			for(unsigned int index=0;index<count;index++)
				_value[index] = va_arg(values, T);
			
			va_end(values);
		}
        
		std::string	_name;
		T			_value[Count];
		int			_glLocation;
		
	};
	
	class I3DAPI ShaderProperty1i : public RenderProperty<int,1>
	{
	public:
        typedef core::SharedPointer<ShaderProperty1i>::pointer pointer;
        
		static ShaderProperty1i::pointer create(int value, std::string name="");
        virtual std::string getClassName() const;

	protected:
        ShaderProperty1i();
		void applyValue();
	};
	
	class I3DAPI ShaderProperty1f : public RenderProperty<float,1>
	{
	public:
        typedef core::SharedPointer<ShaderProperty1f>::pointer pointer;
        
		static ShaderProperty1f::pointer create(float value, std::string name="");
        virtual std::string getClassName() const;

	protected:
        ShaderProperty1f();
		void applyValue();
	};
	
    class I3DAPI ShaderPropertyMatrix : public RenderProperty<math::matrix,1>
	{
	public:
        typedef core::SharedPointer<ShaderPropertyMatrix>::pointer pointer;
        
        static ShaderPropertyMatrix::pointer create(math::matrix value, std::string name="");
        virtual std::string getClassName() const;

	protected:
        ShaderPropertyMatrix();
		void applyValue();
	};
	
	class I3DAPI GLPropertyEnable : public RenderProperty<unsigned int,1>
	{
	public:
        typedef core::SharedPointer<GLPropertyEnable>::pointer pointer;
        
		static GLPropertyEnable::pointer create(unsigned int value, std::string name="");
        virtual std::string getClassName() const;

	protected:
        GLPropertyEnable();
		void applyValue();
	};
	
	class I3DAPI GLPropertyDisable : public RenderProperty<unsigned int,1>
	{
	public:
        typedef core::SharedPointer<GLPropertyDisable>::pointer pointer;
        
		static GLPropertyDisable::pointer create(unsigned int value, std::string name="");
        virtual std::string getClassName() const;

	protected:
        GLPropertyDisable();
		void applyValue();
	};
	
	class I3DAPI GLPropertyBlendFunc : public RenderProperty<unsigned int,2>
	{
	public:
        typedef core::SharedPointer<GLPropertyBlendFunc>::pointer pointer;
        
		static GLPropertyBlendFunc::pointer create(unsigned int src, unsigned int dest, std::string name="");
        virtual std::string getClassName() const;

	protected:
        GLPropertyBlendFunc();
		void applyValue();
	};

	class I3DAPI GLPropertyDepthFunc : public RenderProperty<unsigned int,1>
	{
	public:
        typedef core::SharedPointer<GLPropertyDepthFunc>::pointer pointer;
        
		static GLPropertyDepthFunc::pointer create(unsigned int value, std::string name="");
        virtual std::string getClassName() const;

	protected:
        GLPropertyDepthFunc();
		void applyValue();
	};

}}
#endif
#endif
