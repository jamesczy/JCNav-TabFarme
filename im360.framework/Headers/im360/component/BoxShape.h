/*
 *  BoxShape.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _BoxShape_h_
#define _BoxShape_h_

#include "CollisionObject.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace component {

    class I3DAPI BoxShape : virtual public CollisionObject
    {
    public:
        typedef core::SharedPointer<BoxShape>::pointer pointer;

        static BoxShape::pointer create();
        virtual ~BoxShape();
        virtual std::string getClassName() const;

        void setExtents(const im360::math::vec3 & halfExtents);

        virtual void fitShape();

    protected:
        BoxShape();
        virtual bool init();

        class Data;
        Data * _data;
    };

}}
#endif
#endif
