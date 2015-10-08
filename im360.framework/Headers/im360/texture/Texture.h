/*
 * Texture.h
 *
 *  Created on: Aug 15, 2011
 *      Author: ben
 */

#ifndef _Texture_h_
#define _Texture_h_

#include "im360/core/MarbleConfig.h"
#include "ITexture.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace texture {

	class Texture : virtual public core::I3dObject, virtual public ITexture
	{
	public:
        typedef core::SharedPointer<Texture>::pointer pointer;

        virtual ~Texture();
        virtual std::string getClassName() const;

        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();
        
    protected:
        Texture();

	};

}}
#endif
#endif
