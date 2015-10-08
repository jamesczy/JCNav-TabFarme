/*
 *  Singleton.h
 *  libmarble360
 *
 *  Created by Ben Siroshton
 *  Copyright 2010 Immersive Media. All rights reserved.
 *
 */

#ifndef _Singleton_h_
#define _Singleton_h_

#include "im360/core/Pointer.h"
#include "Thread.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace util {

    template <class T> class Singleton
	{
	public:
		static T & instance()
		{
			if( !_instance )
			{            
                _mutex.lock();
                if( !_instance )
                {
                    _instance = std::tr1::shared_ptr<T>(new T);
                }
                _mutex.unlock();
			}
            
			return *_instance.get();
		}

		static std::tr1::shared_ptr<T> sharedInstance()
		{
			if( !_instance )
			{
                _mutex.lock();
                if( !_instance )
                {
                    _instance = std::tr1::shared_ptr<T>(new T);
                }
                _mutex.unlock();
			}

			return _instance;
		}

		virtual ~Singleton()
        {
        }
        
	protected:
		Singleton()
		{
		}
        
	private:
        static std::tr1::shared_ptr<T>  _instance;
        static im360::async::Mutex      _mutex;
	};

    template <class T> std::tr1::shared_ptr<T> Singleton<T>::_instance;
    template <class T> im360::async::Mutex Singleton<T>::_mutex;

}}
#endif
#endif
