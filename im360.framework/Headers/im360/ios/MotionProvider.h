//
//  MotionProvider.h
//  marble360
//
//  Created by Ben Siroshton on 11/3/10.
//  Copyright 2010 Immersive Ventures. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreMotion/CoreMotion.h>
#import "MotionProviderDelegate.h"

#include "im360/math/MathUtils.h"

@interface MotionProvider : NSObject<UIAccelerometerDelegate, CLLocationManagerDelegate>

@property (nonatomic) BOOL compassCalibEnabled;
@property (nonatomic, assign) id <MotionProviderDelegate> motionDelegate;
@property (nonatomic) UIInterfaceOrientation currentOrientation;
@property (nonatomic) bool enabled;

- (void)start:(float)rate;
- (void)stop;
- (im360::math::vec3)getGravity;
- (im360::math::vec3)getUp;
- (im360::math::vec3)getDown;
- (im360::math::vec3)getForward;
- (im360::math::vec3)getBack;
- (im360::math::vec3)getRight;
- (im360::math::vec3)getLeft;
- (float)getYaw;
- (float)getPitch;
- (float)getRoll;
- (bool)usingCompass;

@end
