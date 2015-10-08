/*
 *  RemoteServer.h
 *  libim360
 *
 *  Created by Ben Siroshton on 1/27/12.
 *  Copyright 2012 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _libim360_RemoteServer_h_
#define _libim360_RemoteServer_h_

#include "im360/core/MarbleConfig.h"
#include "im360/player/Player.h"
#include "im360/core/Pointer.h"
#include "im360/util/Thread.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace remote {

    class I3DAPI RemoteServer : virtual public core::I3dObject, virtual public async::Thread
    {
    public:
        typedef core::SharedPointer<RemoteServer>::pointer pointer;

        static RemoteServer::pointer create();
        
        virtual ~RemoteServer();
        virtual std::string getClassName() const;

        bool start();
        bool start(int listenPort);
        void stop();

        void setPlayer(player::Player::pointer player);

        // Thread
        void run();

    protected:
        RemoteServer();
        virtual bool init();
        
    private:
        class Data;
        Data * _data;

        player::Player::pointer  _player;

        void destroy();       
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
