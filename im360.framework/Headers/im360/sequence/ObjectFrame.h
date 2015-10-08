/*
 *  ObjectFrame.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 10/01/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef _ObjectFrame_h_
#define _ObjectFrame_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"
#include "im360/math/MathTypes.h"
#include "im360/json/JsonStringBuilder.h"
#include "im360/json/IJsonHandler.h"
#include "im360/event/EventDispatcher.h"

#include "ITimeSequenceFrame.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace sequence {

    class I3DAPI ObjectFrame : virtual public ITimeSequenceFrame, virtual public event::EventDispatcher
    {
    public:        
        typedef core::SharedPointer<ObjectFrame>::pointer pointer;

        static const int FLAG_NONE = 0;
        static const int FLAG_ROTATION = 1;
        static const int FLAG_NO_INTERPOLATION = 2;

        static ObjectFrame::pointer create();
        
        virtual ~ObjectFrame();
        virtual std::string getClassName() const;

        virtual ITimeSequenceFrame::pointer clone();

        float getTime();
        void setTime(float time);

        virtual ITimeSequenceFrame::pointer getInterpolatedFrame(const ITimeSequenceFrame::pointer & frameTo, float amount);
        virtual ObjectFrame::pointer getInterpolatedFrame(const ObjectFrame::pointer & frameTo, float amount);

        void addByteProperty(const std::string & name, char value, int flags=FLAG_NONE);
        void addBoolProperty(const std::string & name, bool value, int flags=FLAG_NONE);
        void addIntProperty(const std::string & name, int value, int flags=FLAG_NONE);
        void addFloatProperty(const std::string & name, float value, int flags=FLAG_NONE);
        void addDoubleProperty(const std::string & name, double value, int flags=FLAG_NONE);
        void addVec2Property(const std::string & name, const im360::math::vec2 & value, int flags=FLAG_NONE);
        void addVec3Property(const std::string & name, const im360::math::vec3 & value, int flags=FLAG_NONE);
        void addMatrixProperty(const std::string & name, const im360::math::matrix & value, int flags=FLAG_NONE);

        virtual bool getInterpolateToEnabled();
        virtual void setInterpolateToEnabled(bool enabled);

        virtual void updateTarget(core::I3dObject::pointer & target, float amount=1.f);

        // IEventDispatcher
        virtual void addEventListener(event::EventListener::pointer listener);
        virtual void removeEventListener(event::EventListener::pointer listener);

        // IJsonHandler
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);

    protected:
        ObjectFrame();
        ObjectFrame(const ObjectFrame & object);
        ObjectFrame & operator=(const ObjectFrame & object);
        virtual bool init();
        
        virtual void innerJson(im360::json::JsonStringBuilder & json) const;

    private:
        class Data;
        Data *  _data;
        float   _time;
        bool    _enabled;

    };

}}
#endif
#endif
