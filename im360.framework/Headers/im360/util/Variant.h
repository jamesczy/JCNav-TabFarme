/*
 *  Variant.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 07/15/13.
 *  Copyright 2013 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _Variant_h_
#define _Variant_h_

#include "im360/core/I3dObject.h"
#include "im360/core/Pointer.h"
#include "im360/math/MathTypes.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace util {

    class I3DAPI Variant
    {
    public:
        enum ValueType
        {
            EMPTY,
            STRING,
            NUMERIC,
            BOOLEAN,
            CHAR,
            VEC2,
            VEC3,
            MATRIX,
            OBJECT
        };

        Variant();
        Variant(bool value);
        Variant(char value);
        Variant(int value);
        Variant(long value);
        Variant(float value);
        Variant(double value);
        Variant(const std::string & value);
        Variant(const core::I3dObject::pointer & value);
        Variant(const im360::math::vec2 & value);
        Variant(const im360::math::vec3 & value);
        Variant(const im360::math::matrix & value);
        Variant(const Variant & value);
        Variant & operator= (const Variant & value);
        virtual ~Variant();

        bool toBool() const;
        char toChar() const;
        int toInt() const;
        long toLong() const;
        float toFloat() const;
        double toDouble() const;
        std::string toString() const;
        im360::math::vec2 toVec2() const;
        im360::math::vec3 toVec3() const;
        im360::math::matrix toMatrix() const;
        core::I3dObject::pointer toObject() const;

        bool isEmpty() const;
        bool isBool() const;
        bool isChar() const;
        bool isNumeric() const;
        bool isVec2() const;
        bool isVec3() const;
        bool isMatrix() const;
        bool isString() const;
        bool isObject() const;

    private:
        ValueType   _type;

        union
        {
            char                        ch;
            double                      nu;
            bool                        bo;
            std::string *               st;
            im360::math::vec2 *         v2;
            im360::math::vec3 *         v3;
            im360::math::matrix *       mx;
            core::I3dObject::pointer *  ob;
        } _value;

    };

}}
#endif
#endif
