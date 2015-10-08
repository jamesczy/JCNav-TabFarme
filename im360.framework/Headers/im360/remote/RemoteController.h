//
//  RemoteController.h
//  libim360
//
//  Created by Ben Siroshton on 2/1/12.
//  Copyright (c) 2012 Immersive Media. All rights reserved.
//
#ifndef _libim360_RemoteController_h_
#define _libim360_RemoteController_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace remote {

    class RemoteClient;

    class RemoteController : virtual public core::I3dObject
    {
    friend class RemoteClient;
    public:
        typedef core::SharedPointer<RemoteController>::pointer pointer;
        
        virtual ~RemoteController();
        virtual std::string getClassName() const;

    protected:
        RemoteController(); // don't allow direct instances of this class.        

        void sendMessageAsync(const std::string & msg);
        std::string sendMessageForResponse(const std::string & msg);

    private:
        RemoteClient *  _client;

    };

}}
#endif
#endif

