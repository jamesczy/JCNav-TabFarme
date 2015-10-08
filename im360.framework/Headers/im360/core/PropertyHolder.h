/*
 *  PropertyHolder.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 10/01/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */

#ifndef _PropertyHolder_h_
#define _PropertyHolder_h_

#include "im360/core/MarbleDefines.h"
#include "im360/core/Pointer.h"
#include "im360/json/IJsonHandler.h"
#include "im360/math/MathTypes.h"

#ifdef __cplusplus

#if defined(I3d_TR1_DIR)
    #include <tr1/functional>
#else
    #include <functional>
#endif

#include <map>

// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace json { class JsonStringBuilder; }
namespace util { class Variant; }
namespace core {

    class I3dObject;

    class I3DAPI PropertyHolder : virtual public im360::json::IJsonHandler
    {
    friend class json::JsonStringBuilder;
    public:
        typedef I3dObject *                     ObjectPointer;
        typedef std::tr1::shared_ptr<I3dObject> SharedObject;

        typedef std::tr1::function<std::string(void)>                       StringGetter;
        typedef std::tr1::function<void(const std::string &)>               StringSetter;
        typedef std::tr1::function<char(void)>                              ByteGetter;
        typedef std::tr1::function<void(char)>                              ByteSetter;
        typedef std::tr1::function<bool(void)>                              BoolGetter;
        typedef std::tr1::function<void(bool)>                              BoolSetter;
        typedef std::tr1::function<int(void)>                               IntGetter;
        typedef std::tr1::function<void(int)>                               IntSetter;
        typedef std::tr1::function<long(void)>                              LongGetter;
        typedef std::tr1::function<void(long)>                              LongSetter;
        typedef std::tr1::function<float(void)>                             FloatGetter;
        typedef std::tr1::function<void(float)>                             FloatSetter;
        typedef std::tr1::function<double(void)>                            DoubleGetter;
        typedef std::tr1::function<void(double)>                            DoubleSetter;
        typedef std::tr1::function<im360::math::vec2(void)>                 Vec2Getter;
        typedef std::tr1::function<void(const im360::math::vec2 &)>         Vec2Setter;
        typedef std::tr1::function<im360::math::vec3(void)>                 Vec3Getter;
        typedef std::tr1::function<void(const im360::math::vec3 &)>         Vec3Setter;
        typedef std::tr1::function<im360::math::matrix(void)>               MatrixGetter;
        typedef std::tr1::function<void(const im360::math::matrix &)>       MatrixSetter;
        typedef std::tr1::function<SharedObject(void)>                      SharedGetter;
        typedef std::tr1::function<void(SharedObject)>                      SharedSetter;
        typedef std::tr1::function<ObjectPointer(void)>                     ObjectGetter;
        typedef std::tr1::function<void(ObjectPointer)>                     ObjectSetter;

        // type of property
        enum PropertyType
        {
            STRING,
            BYTE,
            BOOL,
            INT,
            LONG,
            FLOAT,
            DOUBLE,
            VEC2,
            VEC3,
            MATRIX,
            SHARED_OBJECT,
            OBJECT_POINTER
        };

        // property flags
        static const int Direct;
        static const int Getter;
        static const int Setter;

        // property info
        struct PropertyInfo
        {
            std::string     name;
            PropertyType    type;
            int             flags;
        };

        // methods
        PropertyHolder();
        PropertyHolder(const PropertyHolder & object);
        virtual ~PropertyHolder();
        virtual std::string getClassName() const;

        void setString(const std::string & name, const std::string & value);
        void setByte(const std::string & name, char value);
        void setBool(const std::string & name, bool value);
        void setInt(const std::string & name, int value);
        void setLong(const std::string & name, long value);
        void setFloat(const std::string & name, float value);
        void setDouble(const std::string & name, double value);
        void setVec2(const std::string & name, const im360::math::vec2 & value);
        void setVec3(const std::string & name, const im360::math::vec3 & value);
        void setMatrix(const std::string & name, const im360::math::matrix & value);
        //void setSharedObject(const std::string & name, const SharedObject & value);

        void setStrings(const std::map<std::string, std::string> & values);
        void setBytes(const std::map<std::string, char> & values);
        void setBools(const std::map<std::string, bool> & values);
        void setInts(const std::map<std::string, int> & values);
        void setLongs(const std::map<std::string, long> & values);
        void setFloats(const std::map<std::string, float> & values);
        void setDoubles(const std::map<std::string, double> & values);
        void setVec2s(const std::map<std::string, im360::math::vec2> & values);
        void setVec3s(const std::map<std::string, im360::math::vec3> & values);
        void setMatrices(const std::map<std::string, im360::math::matrix> & values);

        std::string getString(const std::string & name) const;
        char getByte(const std::string & name) const;
        bool getBool(const std::string & name) const;
        int getInt(const std::string & name) const;
        long getLong(const std::string & name) const;
        float getFloat(const std::string & name) const;
        double getDouble(const std::string & name) const;
        im360::math::vec2 getVec2(const std::string & name) const;
        im360::math::vec3 getVec3(const std::string & name) const;
        im360::math::matrix getMatrix(const std::string & name) const;
        //SharedObject getSharedObject(const std::string & name) const;

        bool hasGetter(const std::string & name, PropertyType * type = NULL);
        bool hasSetter(const std::string & name, PropertyType * type = NULL);
        bool hasProperty(const std::string & name, PropertyType * type = NULL, int * flags = NULL);

        void setProperty(const std::string & name, const util::Variant & value);
        util::Variant getProperty(const std::string & name);

        int queryProperties(std::vector<PropertyInfo> & properties);
        int queryProperties(std::vector<PropertyInfo> & properties, PropertyType type);

        bool fromJson(const std::string & json);
        std::string toJson() const;
        bool fromFile(const std::string & file);
        bool toFile(const std::string & file);

        // IJsonHandler
        void jsonPropertiesStart();
        void handleJsonNode(std::string name, json::JsonInfo & json);
        void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        void jsonPropertiesEnd();

        // operators
        virtual PropertyHolder & operator=(const PropertyHolder & object);

        // helpers
        // example:
        //addSharedGetSet("camera",
        //std::tr1::bind(&PropertyHolder::getObject<ICamera::pointer, BasicScene>, this, &BasicScene::getCamera),
        //std::tr1::bind(&PropertyHolder::setObject<ICamera, ICamera::pointer, BasicScene>, this, &BasicScene::setCamera, std::tr1::placeholders::_1)
        //);
        template<typename ReturnType, class BaseClass>
        SharedObject getObject(ReturnType (BaseClass::*Getter)(void))
        {
            try
            {
                std::tr1::function<ReturnType()> getter = std::tr1::bind(Getter, dynamic_cast<BaseClass*>(this));
                return std::tr1::dynamic_pointer_cast<I3dObject>(getter());
            }
            catch(std::exception x)
            {
                return SharedObject();
            }
        }

        template<typename ReturnType, class BaseClass>
        SharedObject getObjectConst(ReturnType (BaseClass::*Getter)(void) const)
        {
            try
            {
                std::tr1::function<ReturnType()> getter = std::tr1::bind(Getter, dynamic_cast<BaseClass*>(this));
                return std::tr1::dynamic_pointer_cast<I3dObject>(getter());
            }
            catch(std::exception x)
            {
                return SharedObject();
            }
        }

        template<class ObjectType, typename PointerType, class BaseClass>
        void setObject(void (BaseClass::*Setter)(PointerType), SharedObject object)
        {
            try
            {
                std::tr1::function<void(PointerType)> setter = std::tr1::bind(Setter, dynamic_cast<BaseClass*>(this), std::tr1::placeholders::_1);
                setter( std::tr1::dynamic_pointer_cast<ObjectType>(object) );
            }
            catch(std::exception x)
            {
            }
        }

        template<typename EnumType, class BaseClass>
        int getEnumInt(EnumType (BaseClass::*Getter)(void))
        {
            std::tr1::function<EnumType()> getter = std::tr1::bind(Getter, dynamic_cast<BaseClass*>(this));
            return (int)getter();
        }

        template<typename EnumType, class BaseClass>
        int getEnumIntConst(EnumType (BaseClass::*Getter)(void) const)
        {
            std::tr1::function<EnumType()> getter = std::tr1::bind(Getter, dynamic_cast<BaseClass*>(this));
            return (int)getter();
        }

        template<typename EnumType, class BaseClass>
        void setEnumInt(void (BaseClass::*Setter)(EnumType), int value)
        {
            std::tr1::function<void(EnumType)> setter = std::tr1::bind(Setter, dynamic_cast<BaseClass*>(this), std::tr1::placeholders::_1);
            setter((EnumType)value);
        }

    protected:
        void addString(const std::string & name, std::string * property);
        void addStringGetSet(const std::string & name, StringGetter getter, StringSetter setter);
        void addStringGet(const std::string & name, StringGetter getter);
        void addStringSet(const std::string & name, StringSetter setter);

        void addByte(const std::string & name, char * property);
        void addByteGetSet(const std::string & name, ByteGetter getter, ByteSetter setter);
        void addByteGet(const std::string & name, ByteGetter getter);
        void addByteSet(const std::string & name, ByteSetter setter);

        void addBool(const std::string & name, bool * property);
        void addBoolGetSet(const std::string & name, BoolGetter getter, BoolSetter setter);
        void addBoolGet(const std::string & name, BoolGetter getter);
        void addBoolSet(const std::string & name, BoolSetter setter);

        void addInt(const std::string & name, int * property);
        void addIntGetSet(const std::string & name, IntGetter getter, IntSetter setter);
        void addIntGet(const std::string & name, IntGetter getter);
        void addIntSet(const std::string & name, IntSetter setter);

        void addLong(const std::string & name, long * property);
        void addLongGetSet(const std::string & name, LongGetter getter, LongSetter setter);
        void addLongGet(const std::string & name, LongGetter getter);
        void addLongSet(const std::string & name, LongSetter setter);

        void addFloat(const std::string & name, float * property);
        void addFloatGetSet(const std::string & name, FloatGetter getter, FloatSetter setter);
        void addFloatGet(const std::string & name, FloatGetter getter);
        void addFloatSet(const std::string & name, FloatSetter setter);

        void addDouble(const std::string & name, double * property);
        void addDoubleGetSet(const std::string & name, DoubleGetter getter, DoubleSetter setter);
        void addDoubleGet(const std::string & name, DoubleGetter getter);
        void addDoubleSet(const std::string & name, DoubleSetter setter);

        void addVec2(const std::string & name, im360::math::vec2 * property);
        void addVec2GetSet(const std::string & name, Vec2Getter getter, Vec2Setter setter);
        void addVec2Get(const std::string & name, Vec2Getter getter);
        void addVec2Set(const std::string & name, Vec2Setter setter);

        void addVec3(const std::string & name, im360::math::vec3 * property);
        void addVec3GetSet(const std::string & name, Vec3Getter getter, Vec3Setter setter);
        void addVec3Get(const std::string & name, Vec3Getter getter);
        void addVec3Set(const std::string & name, Vec3Setter setter);

        void addMatrix(const std::string & name, im360::math::matrix * property);
        void addMatrixGetSet(const std::string & name, MatrixGetter getter, MatrixSetter setter);
        void addMatrixGet(const std::string & name, MatrixGetter getter);
        void addMatrixSet(const std::string & name, MatrixSetter setter);

        void addShared(const std::string & name, SharedObject property);
        void addSharedGetSet(const std::string & name, SharedGetter getter, SharedSetter setter);
        void addSharedGet(const std::string & name, SharedGetter getter);
        void addSharedSet(const std::string & name, SharedSetter setter);

        void addObject(const std::string & name, ObjectPointer property);
        void addObjectGetSet(const std::string & name, ObjectGetter getter, ObjectSetter setter);
        void addObjectGet(const std::string & name, ObjectGetter getter);
        void addObjectSet(const std::string & name, ObjectSetter setter);

        void removeProperty(const std::string & name);

        virtual void innerJson(im360::json::JsonStringBuilder & json) const;

    private:
        class Data;
        Data * _data;

    };

}}
#endif
#endif
