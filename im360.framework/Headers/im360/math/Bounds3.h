/*
 *  Bounds3.h
 *  marble360
 *
 *  Created by Ben Siroshton on 11/17/11.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _Bounds3_h_
#define _Bounds3_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"
#include "MathTypes.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace math {

    class I3DAPI Bounds3
    {
    public:
        typedef core::SharedPointer<Bounds3>::pointer pointer;

        vec3 min;
        vec3	max;

        Bounds3();
        Bounds3(const vec3 & min, const vec3 & max);
        virtual ~Bounds3();
        virtual std::string getClassName() const;

        vec3 getCenter() const;

        void set(const vec3 & min, const vec3 & max);
        void setByHalfExtents(const vec3 & halfExtents);

        void reset();
        void reset(const vec3 & point);

        void expand(const vec3 & point);
        bool contains(const vec3 & point);
    
        static Bounds3 zeroBounds();
    };

}}
#endif
#endif
