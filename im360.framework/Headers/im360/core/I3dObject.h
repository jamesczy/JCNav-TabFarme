/*
 *  I3dObject.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 2/15/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _I3dObject_h_
#define _I3dObject_h_

#include "im360/core/MarbleDefines.h"
#include "im360/core/Pointer.h"
#include "im360/core/PropertyHolder.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// Java Interface
// -----------------------------------------------------------------------
#if defined(I3d_JNI)
#include <jni.h>
#define JNI_SPTR_TO_HANDLE(p) reinterpret_cast<jlong>(p)
#define JNI_HANDLE_TO_OBJPTR(p) reinterpret_cast<im360::core::I3dObject::pointer*>(p)
#define JNI_HANDLE_TO_CLASS(c,p) (p ? (*reinterpret_cast<im360::core::I3dObject::pointer*>(p))->getPointer<c>() : c::pointer())
#define JNI_VALIDATE_PTR_VOID(p) if(!p){ I3d_debugF(im360::util::DBG_WARNING,"invalid pointer") return;}
#define JNI_VALIDATE_PTR(p,ret) if(!p){ I3d_debugF(im360::util::DBG_WARNING,"invalid pointer") return ret;}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#define C_SPTR_TO_HANDLE(p) reinterpret_cast<long>(p)
#define C_HANDLE_TO_OBJPTR(p) reinterpret_cast<im360::core::I3dObject::pointer*>(p)
#define C_HANDLE_TO_CLASS(c,p) (p ? (*reinterpret_cast<im360::core::I3dObject::pointer*>(p))->getPointer<c>() : c::pointer())
#define C_VALIDATE_PTR_VOID(p) if(!p){ I3d_debugF(im360::util::DBG_WARNING,"invalid pointer") return;}
#define C_VALIDATE_PTR(p,ret) if(!p){ I3d_debugF(im360::util::DBG_WARNING,"invalid pointer") return ret;}

// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace util { class Variant; class Command; }
namespace core {

    class I3DAPI I3dObject : public PropertyHolder, public std::tr1::enable_shared_from_this<I3dObject>
	{
	public:
        typedef core::SharedPointer<I3dObject>::pointer pointer;
		        
#if defined(I3d_JNI)
		I3dObject(const I3dObject & object);
		I3dObject & operator=(const I3dObject & object);
#endif
		virtual ~I3dObject();
        
#if defined(I3d_JNI)
		void jniInit(jobject obj);
#endif
        
        template<typename T>
		std::tr1::shared_ptr<T> getPointer()
		{
			try
			{
				return std::tr1::dynamic_pointer_cast<T>(getSharedFromThis());
			}
			catch(std::exception x)
			{
				return std::tr1::shared_ptr<T>();
			}
		}

        I3dObject::pointer getSharedFromThis();

		std::string getName();
		void setName(std::string name);

        virtual std::string getClassName() const = 0;

        virtual util::Variant evaluate(const util::Command & command);

    protected:
        I3dObject();
        virtual bool init();
        
#if defined(I3d_JNI)
		jobject		_jobj;
		JNIEnv *	_env;
		bool		_jniThreadAttached;

		bool jniGetEnv();
		void jniReleaseEnv();

		void jniCallVoid(const char * name, const char * sig, ...);
		long jniCallLong(const char * name, const char * sig, ...);
		bool jniCallBool(const char * name, const char * sig, ...);

		virtual void onJniSet(){}
#endif
    
    private:
        std::string _name;

	};

}}
#endif
#endif

