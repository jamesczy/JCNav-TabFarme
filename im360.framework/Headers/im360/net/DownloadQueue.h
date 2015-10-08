/*
 *  DownloadQueue.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 7/9/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _DownloadQueue_h_
#define _DownloadQueue_h_

#include "im360/core/MarbleConfig.h"
#include "im360/event/EventDispatcher.h"
#include "im360/util/Thread.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace net {

    size_t DownloadQueue_downloadCallback(char * data, size_t size, size_t count, void * userData);

    class I3DAPI DownloadQueue : virtual public event::EventDispatcher, virtual public async::Thread
    {
    friend size_t DownloadQueue_downloadCallback(char * data, size_t size, size_t count, void * userData);
    public:
        typedef core::SharedPointer<DownloadQueue>::pointer pointer;

        static DownloadQueue::pointer create();

        virtual ~DownloadQueue();
        virtual std::string getClassName() const;

        void queueItem(const std::string & url, const std::string & destination, void * userData = NULL);
        void cancelItem(const std::string & url);
        void cancelAllItems();

    protected:
        DownloadQueue();
        virtual bool init();
        virtual void run();

    private:
        class Data;
        friend class Data;
        Data * _data;

        struct
        {
            bool    isRunning;
        } _info;

    };

}}
#endif
#endif

