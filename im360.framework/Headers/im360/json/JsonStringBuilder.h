//
//  JsonStringBuilder.h
//  libim360
//
//  Created by Ben Siroshton on 2/1/12.
//  Copyright (c) 2012 Immersive Media. All rights reserved.
//
#ifndef _libim360_JsonStringBuilder_h_
#define _libim360_JsonStringBuilder_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/I3dObject.h"
#include "im360/core/Pointer.h"
#include "im360/math/MathTypes.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace json {

    // TODO: remove this class and instead use a VariantMap once it has been added with json capabilities

    class I3DAPI JsonStringBuilder
    {    
    public:
        JsonStringBuilder();
        virtual ~JsonStringBuilder();

        void clear();

        void startSection();
        void startSection(const std::string & name);
        void endSection();

        void startArray();
        void startArray(const std::string & name);
        void endArray();

        void addString(const std::string & name, const std::string & value);
        void addBool(const std::string & name, bool value);
        void addNumber(const std::string & name, int value);
        void addNumber(const std::string & name, long value);
        void addNumber(const std::string & name, float value);
        void addNumber(const std::string & name, double value);
        void addVec2(const std::string & name, const im360::math::vec2 & value);
        void addVec3(const std::string & name, const im360::math::vec3 & value);
        void addMatrix(const std::string & name, const im360::math::matrix & value);
        void addObject(const std::string & name, const core::I3dObject::pointer & object);
        void addObject(const std::string & name, const core::I3dObject * object);
        void addObject(const core::I3dObject::pointer & object);
        void addObject(const core::I3dObject * object);

        const std::string & getJson() const;

        static std::string arrayFromBools(int count, ...);
        static std::string arrayFromInts(int count, ...);
        static std::string arrayFromLongs(int count, ...);
        static std::string arrayFromFloats(int count, ...);
        static std::string arrayFromDoubles(int count, ...);

    private:
        std::string _json;

        bool    _inArray;
        int     _depth;

        void prepareNext(bool endingSection=false);
    };

}}
#endif
#endif
