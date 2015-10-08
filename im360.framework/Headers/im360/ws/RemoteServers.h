/*
 *  RemoteServers.h
 *  libim360
 *
 *  Created by Ben Siroshton on 01/31/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef libim360_RemoteServers_h_
#define libim360_RemoteServers_h_

#include "im360/core/MarbleConfig.h"
#include "WsUtil.h"
#include "im360/net/Url.h"
#include "entities/RemoteServerEntity.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <vector>
namespace im360 {
namespace ws {

    // DEPRECATED

    class RemoteServers : virtual public core::I3dObject
    {
    public:
        typedef core::SharedPointer<RemoteServers>::pointer pointer;

        static RemoteServers::pointer create();

        virtual ~RemoteServers();
        virtual std::string getClassName() const;

    protected:
        RemoteServers();
        virtual bool init();
    
    };

}}
#endif
#endif
