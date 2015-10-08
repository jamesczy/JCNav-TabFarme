/*
 *  TimeSequenceManager.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 9/28/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef _TimeSequenceMangaer_h_
#define _TimeSequenceMangaer_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/Pointer.h"
#include "im360/util/Thread.h"
#include "im360/event/EventDispatcher.h"
#include "ITimeSequence.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace sequence {

    class I3DAPI TimeSequenceManager : virtual public event::EventDispatcher
    {
    public:
        typedef core::SharedPointer<TimeSequenceManager>::pointer pointer;

        static TimeSequenceManager::pointer create();
        
        virtual ~TimeSequenceManager();
        virtual std::string getClassName() const;

        void addSequence(ITimeSequence::pointer sequence);
        void removeSequence(ITimeSequence::pointer sequence);
        int getSequenceCount();

        void update(float time);

    protected:
        TimeSequenceManager();
        virtual bool init();
        
    private:
        typedef std::list<ITimeSequence::pointer> TimeSequenceList;

        TimeSequenceList    _sequences;
        async::Mutex        _sequenceMutex;

    };

}}
#endif
#endif
