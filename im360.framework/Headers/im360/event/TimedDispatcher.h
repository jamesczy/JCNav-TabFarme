#ifndef _TimedDispatcher_h_
#define _TimedDispatcher_h_

#include "EventDispatcher.h"
#include "im360/util/Thread.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace event {

    class I3DAPI TimedDispatcher : virtual public EventDispatcher, public async::Thread
    {
    public:
        typedef core::SharedPointer<TimedDispatcher>::pointer pointer;

        static TimedDispatcher::pointer create(long interval, bool repeats);

        virtual ~TimedDispatcher();
        virtual std::string getClassName() const;

        unsigned long getInterval();
        void setInterval(unsigned long interval);

        bool getRepeats();
        void setRepeats(bool repeats);

        virtual void run();
        void stop();

    protected:
        TimedDispatcher();
        virtual bool init(long interval, bool repeats);

        unsigned long   _interval;
        bool            _repeats;
        bool            _isRunning;
    };

}}
#endif
#endif

