/*
 *  IResource.h
 *  libmarble360
 *
 *  Created by Ben Siroshton on 4/5/12.
 *  Copyright 2012 Immersive Media. All rights reserved.
 *
 */

#ifndef _libim360_IResource_h_
#define _libim360_IResource_h_

#include "im360/core/MarbleDefines.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace resource {

    class I3DAPI IResource
	{
	public:
		enum RestoreResult
		{
			NOT_NEEDED,
			FAILED,
            SUCCESS
		};

		virtual bool needsRestore(unsigned int restoreCount) = 0;
		virtual RestoreResult restoreResource(unsigned int restoreCount) = 0;
		virtual unsigned int getRestoreCount() = 0;

	protected:

	};

}}
#endif
#endif

