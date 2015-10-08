#ifndef _TimeSequenceComponent_h_
#define _TimeSequenceComponent_h_

#include "im360/core/MarbleConfig.h"
#include "ComponentBase.h"
#include "im360/sequence/TimeSequence.h"
#include "im360/util/Timer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene { class Node; }
namespace component {

    class I3DAPI TimeSequenceComponent : virtual public ComponentBase, virtual public im360::sequence::TimeSequence
    {
    public:
        typedef core::SharedPointer<TimeSequenceComponent>::pointer pointer;

        static TimeSequenceComponent::pointer create();
        virtual ~TimeSequenceComponent();
        virtual std::string getClassName() const;

        virtual void setEnabled(bool enabled);
        virtual bool getEnabled();

        void setControlDelayMs(unsigned long time);
        unsigned long getControlDelayMs();

    protected:
        TimeSequenceComponent();
        virtual bool init();

        virtual void onUpdate();

    private:
        float               _lastTime;
        int                 _lastFromIndex;
        int                 _lastToIndex;
        unsigned long       _controlDelay;
        im360::util::Timer  _timeTimer;
        float               _avgTimeChange;
        float               _stepTime;
        bool                _wasPaused;
    };

}}
#endif
#endif
