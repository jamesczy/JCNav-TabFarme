//
//  Pointer.h
//  libim360
//
//  Created by Ben Siroshton on 2/2/12.
//  Copyright (c) 2012 Immersive Media. All rights reserved.
//
#ifndef _libim360_Pointer_h_
#define _libim360_Pointer_h_

#include "im360/core/MarbleDefines.h"

#ifdef __cplusplus
#if defined(I3d_TR1_DIR)
    #include <tr1/memory>
#else
    #include <memory>
#endif

#include "assert.h"

// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace core {

    template <class T> struct SharedPointer
    {
        typedef std::tr1::shared_ptr<T> pointer;
    };

    template <class T> struct WeakPointer
    {
        typedef std::tr1::weak_ptr<T> pointer;
    };

    struct NullDeleter
    {
        void operator()(void const *) const
        {
        }
    };

}}
#endif
#endif
