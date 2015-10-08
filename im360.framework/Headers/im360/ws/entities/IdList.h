//
//  IdList.h
//  libim360
//
//  Created by Ben Siroshton on 2/26/13.
//  Copyright (c) 2013 Immersive Ventures. All rights reserved.
//

#ifndef __libim360__IdList__
#define __libim360__IdList__

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

    class I3DAPI IdList : virtual public IEntity
	{
	public:
        typedef core::SharedPointer<IdList>::pointer pointer;

        std::vector<long> ids;
        
        static IdList::pointer create();

		virtual ~IdList();
        virtual std::string getClassName() const;
        
		virtual void clear();
        
        virtual void jsonPropertiesStart();
		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();
        
		virtual std::string getJson() const;
		virtual void parseJson(std::string json);

    protected:
		IdList();
        virtual bool init();
	};
    
}}}
#endif
#endif /* defined(__libim360__IdList__) */
