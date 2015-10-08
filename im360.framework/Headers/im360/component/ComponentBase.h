/*
 *  ComponentBase.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 11/21/11.
 *  Copyright 2011 Immersive Media. All rights reserved.
 *
 */
#ifndef _ComponentBase_h_
#define _ComponentBase_h_

#include "im360/core/MarbleConfig.h"
#include "IComponent.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene { class Node; }
namespace component {

    class I3DAPI ComponentBase : virtual public core::I3dObject, virtual public IComponent
	{
    friend class im360::scene::Node;

	public:
        typedef core::SharedPointer<ComponentBase>::pointer pointer;

        virtual ~ComponentBase();
        virtual std::string getClassName() const;

        virtual im360::core::WeakPointer<im360::scene::Node>::pointer getNode();

        virtual void setEnabled(bool enabled);
        virtual bool getEnabled();

	protected:
        ComponentBase();
        virtual bool init();

		virtual	void onAdded(){}
		virtual	void onRemoved(){}
		virtual void onUpdate(){}
		virtual void onRender(){}
		virtual void onAddedToScene(){}
		virtual void onRemovedFromScene(){}

        im360::core::WeakPointer<im360::scene::Node>::pointer  _node;

        bool    _enabled;

    private:
        virtual void setNode(im360::core::WeakPointer<im360::scene::Node>::pointer node);

	};

}}
#endif
#endif
