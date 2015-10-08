/*
 *  ResourcePool.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 4/5/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */

#ifndef _libim360_ResourcePool_h_
#define _libim360_ResourcePool_h_

#include "im360/core/MarbleDefines.h"
#include "im360/core/I3dObject.h"
#include "im360/util/Singleton.h"
#include "im360/core/Pointer.h"
#include "IResource.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <set>
namespace im360 {
namespace resource {

    class I3DAPI ResourcePool : virtual public core::I3dObject, virtual public util::Singleton<ResourcePool>
	{
    friend class util::Singleton<ResourcePool>;
	public:
		virtual ~ResourcePool();
        virtual std::string getClassName() const;

        void addResource(core::WeakPointer<IResource>::pointer resource);
        void removeResource(core::WeakPointer<IResource>::pointer resource);

		void restoreResources();
		unsigned int getRestoreCount();

    protected:
        ResourcePool();

	private:
        typedef std::set<IResource*> ResourceList;

        ResourceList    _resources;
        unsigned int    _restoreCount;
	};

}}
#endif
#endif
