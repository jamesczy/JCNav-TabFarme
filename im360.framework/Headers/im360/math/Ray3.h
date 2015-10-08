/*
 *  Ray3.h
 *  marble360
 *
 *  Created by Ben Siroshton on 11/17/11.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Ray3_h_
#define _Ray3_h_

#include "im360/core/MarbleConfig.h"
#include "MathTypes.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace math {

    class I3DAPI Ray3
    {
    public:
        typedef core::SharedPointer<Ray3>::pointer pointer;

        vec3	origin;
        vec3	direction;

        Ray3();
        Ray3(const vec3 & origin, const vec3 & direction);
        virtual ~Ray3();
        virtual std::string getClassName() const;
    };

}}
#endif
#endif
