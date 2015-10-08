/*
 *  Interval.h
 *  libim360
 *
 *  Created by Ben Siroshton on 05/02/11.
 *  Copyright 2010 Immersive Media. All rights reserved.
 *
 */
#ifndef _MatrixStack_h_
#define _MatrixStack_h_

#include "im360/core/MarbleConfig.h"
#include "MathTypes.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <stack>
namespace im360 {
namespace math {

    class I3DAPI MatrixStack
    {
	public:
        MatrixStack();
        virtual ~MatrixStack();

		void push(const matrix & m);
		void pushIdentity();
		void pop();
		matrix value();

		void clear();
		unsigned int count();

	private:
		std::stack<matrix>	_stack;
		matrix				_ident;

	};

}}
#endif
#endif
