/*
 *  RenderEffect.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 11/30/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _RenderEffect_h_
#define _RenderEffect_h_

#include "RenderPass.h"
#include "im360/json/IJsonHandler.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace render {

	class I3DAPI RenderEffect : virtual public core::I3dObject
	{		
	public:
        typedef core::SharedPointer<RenderEffect>::pointer    pointer;
        typedef std::list<RenderPass::pointer>          passList;
        typedef passList::iterator                      passListIterator;
		
        static RenderEffect::pointer create();
        
		virtual ~RenderEffect();
        virtual std::string getClassName() const;

        void addRenderPass(RenderPass::pointer pass);

        RenderPass::pointer getRenderPassAt(unsigned int index);
        unsigned int getRenderPassIndex(RenderPass::pointer pass);

        void removeRenderPass(RenderPass::pointer pass);
		void removeRenderPassAtIndex(unsigned int index);
		void clearRenderPasses();

		unsigned int getRenderPassCount();
		
        passListIterator begin();
        passListIterator end();
		
        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & jsonNode);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & jsonNode);
        virtual void jsonPropertiesEnd();

    protected:
        RenderEffect();
        virtual bool init();
        
	private:
        passList	_passes;
		
	};
		
}}
#endif
#endif

