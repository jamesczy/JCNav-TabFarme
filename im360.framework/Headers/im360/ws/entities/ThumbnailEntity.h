/*
 *  ThumbnailEntity.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 09/06/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */
#ifndef _ThumbnailEntity_h_
#define _ThumbnailEntity_h_

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

    class I3DAPI ThumbnailEntity : virtual public IEntity
	{
	public:
        typedef core::SharedPointer<ThumbnailEntity>::pointer pointer;

		int 		thumbWidth;
		int 		thumbHeight;
		std::string	thumbFile;
		std::string	thumbUrl;

        static ThumbnailEntity::pointer create();
        
		virtual ~ThumbnailEntity();
        virtual std::string getClassName() const;

		virtual void clear();

        virtual void jsonPropertiesStart();
		virtual void handleJsonNode(std::string name, json::JsonInfo & json);
		virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

		virtual std::string getJson() const;
		virtual void parseJson(std::string json);

    protected:
		ThumbnailEntity();
        virtual bool init();
	};

}}}
#endif
#endif
