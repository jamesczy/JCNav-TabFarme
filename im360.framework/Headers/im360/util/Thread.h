/*
 *  Thread.h
 *  player
 *
 *  Created by Ben Siroshton on 8/19/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Thread_h_
#define _Thread_h_

#include "im360/core/MarbleDefines.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <limits>
#include <string>
#include <list>

namespace im360 {
namespace async {

    class I3DAPI Thread;
    class I3DAPI Mutex;
    class I3DAPI WaitCondition;
    class I3DAPI RecursiveMutex;
    class I3DAPI AutoLock;

    /**
     * Thread
     */
	class I3DAPI Thread
	{
    class PlatformThread;
    friend class PlatformThread;
    friend void * StartThreading(void * data);
    public:
        typedef void (*ThreadFunction)(void * userData);

		enum ThreadPriority {
			IDLE=0,
			LOWEST=5,
			LOW=10,
			NORMAL=20,
			HIGH=25,
			HIGHEST=31
		};

		Thread();
		virtual ~Thread();
        virtual std::string getClassName() const;

        virtual bool start();
        virtual void run() = 0;
        virtual void kill();

		void wait();
		void sleep(unsigned long msecs);
		void setPriority(ThreadPriority priority);
        bool isRunning();

		static unsigned long getCurrentThreadId();
        static void yieldCurrentThread();
        static void runOnThread(ThreadFunction function, void * userData);

	private:
		class Data;        

        Data * 			_data;
        ThreadPriority	_priority;

        void finish();

        // static thread list to be used by runOnThread, this list is checked and emptied
        // as necessary anytime a new ::runOnThread call is made.
        static std::list<Thread*>   _runOnThreads;
        static Mutex                _runOnThreadsMutex;
    };

    /**
     * Mutex
     */
    class I3DAPI Mutex
	{
    friend class WaitCondition;
	public:
        static const int NO_ATTRIBUTES = 0;
        static const int RECURSIVE_LOCKING = 1;
        
        typedef core::SharedPointer<Mutex>::pointer pointer;

        Mutex();
        Mutex(int flags);
		virtual ~Mutex();
        virtual std::string getClassName() const;

		void lock();
		bool tryLock();
		void unlock();

	private:
		class Data;
        Data * _data;
	};
	    
    /**
     * RecursiveMutex
     */
    class I3DAPI RecursiveMutex : public Mutex
    {
    public:
        RecursiveMutex() : Mutex(Mutex::RECURSIVE_LOCKING)
        {
        }
    };

    /**
     * WaitCondition
     */
    class I3DAPI WaitCondition
    {
    public:
        typedef core::SharedPointer<WaitCondition>::pointer pointer;

        WaitCondition();
        virtual ~WaitCondition();
        virtual std::string getClassName() const;

        bool wait(Mutex & mutex, unsigned long timeOut = ULONG_MAX);
        void wakeAll();
        void wakeOne();

    private:
        class Data;
        Data * _data;
    };

    /**
     * AutoLock
     */
    class I3DAPI AutoLock
	{
	public:
        typedef core::SharedPointer<AutoLock>::pointer pointer;

        AutoLock(Mutex * mutex);
		virtual ~AutoLock();
        virtual std::string getClassName() const;

	private:
		Mutex *	_mutex;

	};
	

}}
#endif
#endif
