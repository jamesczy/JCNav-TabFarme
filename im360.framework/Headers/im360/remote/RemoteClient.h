//
//  RemoteClient.h
//  libim360
//
//  Created by Ben Siroshton on 1/30/12.
//  Copyright (c) 2012 Immersive Media. All rights reserved.
//

#ifndef _libim360_RemoteClient_h_
#define _libim360_RemoteClient_h_

#include "im360/util/Thread.h"
#include "RemoteController.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
#include <list>
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace remote {

    class I3DAPI RemoteClient : virtual public core::I3dObject, virtual public async::Thread
    {
    friend class RemoteController;

    public:
        typedef core::SharedPointer<RemoteClient>::pointer pointer;

        static RemoteClient::pointer create();
        
        virtual ~RemoteClient();
        virtual std::string getClassName() const;
        
        bool connect(std::string ip, unsigned int port=360);
        bool isConnected();
        void disconnect();
        
        std::string getHost();
        unsigned int getPort();
        
        bool registerController(RemoteController::pointer controller);
        bool unRegisterController(RemoteController::pointer controller);

        // Thread
        void run();

    protected:
        RemoteClient();
        virtual bool init();
        
    private:
        typedef std::list<RemoteController::pointer> ControllerList;

        class Data;
        Data * _data;
        
        std::string     _ip;
        unsigned int    _port;
        
        void destroy();        

        ControllerList   _controllers;

        void sendMessageAsync(const std::string & msg);
        std::string sendMessageForResponse(const std::string & msg);
    };

}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
    // ... functions ...
#ifdef __cplusplus
}
#endif

#endif
