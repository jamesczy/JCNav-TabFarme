/*
 *  ObjectMap.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 07/15/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _ObjectMap_h_
#define _ObjectMap_h_

#include "im360/core/i3dObject.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <map>
namespace im360 {
namespace util {

    class I3DAPI ObjectMap
    {
    public:
        ObjectMap();
        virtual ~ObjectMap();

        long add(core::I3dObject::pointer object);

        core::I3dObject::pointer find(long handle);
        long find(const core::I3dObject::pointer & object);

        void remove(long handle);
        void remove(const core::I3dObject::pointer & object);

        void clear();

    private:
        typedef std::map<long, core::I3dObject::pointer> Objects;
        typedef std::map<core::I3dObject::pointer, long> Handles;

        Objects _objects;
        Handles _handles;

    };

}}
#endif
#endif
