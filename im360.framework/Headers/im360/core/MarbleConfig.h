
#ifndef _MarbleConfig_h_
#define _MarbleConfig_h_

#include "MarbleDefines.h"

#include "im360/util/Singleton.h"
#include "im360/util/PropertyBag.h"
#include "im360/core/MarbleTypes.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <stddef.h>
namespace im360 {
namespace core {

    class I3DAPI MarbleConfig : virtual public util::PropertyBag, virtual public util::Singleton<MarbleConfig>
	{
    friend class util::Singleton<MarbleConfig>;
	public:
        typedef core::SharedPointer<MarbleConfig>::pointer pointer;

		virtual ~MarbleConfig();
        virtual std::string getClassName() const;

	protected:
        MarbleConfig();
        virtual bool init();

        virtual void propertyAdded(Property & property);
		virtual void propertyValueSet(Property & property);

    private:
        bool    _hidden;

        void updatePropertyPath(const std::string & propName);
    };

}}
#endif
#endif

