/*
 *  IComponent.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _IComponent_h_
#define _IComponent_h_

#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene { class Node; }
namespace component {

	class I3DAPI IComponent
	{
    friend class scene::Node;

	public:
        typedef core::SharedPointer<IComponent>::pointer pointer;
		virtual ~IComponent(){}
		
        virtual im360::core::WeakPointer<im360::scene::Node>::pointer getNode() = 0;

        virtual void setEnabled(bool enabled) = 0;
        virtual bool getEnabled() = 0;

	protected:
		virtual	void onAdded() = 0;
		virtual	void onRemoved() = 0;
        virtual void onUpdate() = 0;
		virtual void onRender() = 0;
		virtual void onAddedToScene() = 0;
		virtual void onRemovedFromScene() = 0;

	private:
        virtual void setNode(im360::core::WeakPointer<im360::scene::Node>::pointer node) = 0;

	};

}}
#endif
#endif
