/*
 *  Resource.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 4/5/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */

#ifndef _libim360_Resource_h_
#define _libim360_Resource_h_

#include "IResource.h"
#include "im360/core/I3dObject.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace resource {

    class I3DAPI Resource : /*virtual public core::I3dObject,*/ virtual public IResource
	{
	public:
        typedef core::SharedPointer<Resource>::pointer pointer;
		
		virtual ~Resource();
        //virtual std::string getClassName() const;

		// IResource interface
		virtual bool needsRestore(unsigned int restoreCount);
		virtual RestoreResult restoreResource(unsigned int restoreCount);
		virtual unsigned int getRestoreCount();

    protected:
        Resource();
        /*virtual bool init();*/

	private:
		unsigned int _restoreCount;

	};

}}
#endif
#endif
