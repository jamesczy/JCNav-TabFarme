
//
//  MotionProviderDelgate.h
//  marble360
//
//  Created by Ben Siroshton on 11/3/10.
//  Copyright 2010 Immersive Ventures. All rights reserved.
//
#include "im360/math/MathUtils.h"

@class MotionProvider;

@protocol MotionProviderDelegate<NSObject>

@optional

- (void)motionOccured:(MotionProvider *)provider;

@end
