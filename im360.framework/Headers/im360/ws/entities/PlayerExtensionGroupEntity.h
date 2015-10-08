#ifndef _PlayerExtensionGroupEntity_h_
#define _PlayerExtensionGroupEntity_h_

#include "im360/core/MarbleConfig.h"
#include "PlayerExtensionEntity.h"

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI PlayerExtensionGroupEntity : virtual public IEntity
    {
    public:
        typedef core::SharedPointer<PlayerExtensionGroupEntity>::pointer pointer;

        std::string                                         extensionGroupName;
        std::vector<PlayerExtensionGroupEntity::pointer>    extensionGroups;
        std::vector<PlayerExtensionEntity::pointer>         extensions;

        static PlayerExtensionGroupEntity::pointer create();
        
        virtual ~PlayerExtensionGroupEntity();
        virtual std::string getClassName() const;

        virtual void clear();

        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

        virtual std::string getJson() const;
        virtual void parseJson(std::string json);

    protected:
        PlayerExtensionGroupEntity();
        virtual bool init();

    };

}}}
#endif
#endif
