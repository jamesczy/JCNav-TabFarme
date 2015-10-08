#ifndef _PlayerExtensionEntity_h_
#define _PlayerExtensionEntity_h_

#include "im360/core/MarbleConfig.h"
#include "IEntity.h"

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI PlayerExtensionEntity : virtual public IEntity
    {
    public:
        typedef core::SharedPointer<PlayerExtensionEntity>::pointer pointer;

        std::string extensionName;
        std::string extensionUrl;

        static PlayerExtensionEntity::pointer create();

        virtual ~PlayerExtensionEntity();
        virtual std::string getClassName() const;

        virtual void clear();

        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

        virtual std::string getJson() const;
        virtual void parseJson(std::string json);

    protected:
        PlayerExtensionEntity();
        virtual bool init();
        
    };

}}}
#endif
#endif
