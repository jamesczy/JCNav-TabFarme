//
//  IM360View.h
//  player
//
//  Created by Ben Siroshton on 8/4/10.
//  Copyright Immersive Ventures 2010. All rights reserved.
//
/*

 Needed Frameworks:
	AudioToolbox
	CoreAudio
	CoreLocation
	CoreMotion (as weak reference)
	Foundation
	OpenAL
	OpenGLES
	QuartzCore
	UIKit

 Be sure the source file including this is of type ".mm" and not ".m"

 In "Other Linker Flags" add "-ObjC" otherwise the UIViews in libmarble360 will
 not be linked in for use during runtime.

*/

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/ES2/gl.h>

#include "im360/input/HumanInput.h"
#include "im360/player/Player.h"
#include "im360/util/Timer.h"

using namespace im360;

@protocol IM360ViewDelegate;

@interface IM360View : UIView<UIGestureRecognizerDelegate>

@property (nonatomic, readonly) player::Player::pointer player;
@property (nonatomic, readonly) UIInterfaceOrientation currentOrientation;
@property (readonly, nonatomic) BOOL animating;
@property (nonatomic) NSInteger animationFrameInterval;
@property (nonatomic, copy) NSString * domId;
@property (nonatomic, assign) id <IM360ViewDelegate> im360ViewDelegate;
@property (nonatomic, readonly) EAGLContext * context;

+ (id)viewWithFrame:(CGRect)frame;
+ (id)viewWithFrame:(CGRect)frame shareContextWithView:(IM360View *)playerView;
+ (id)viewWithFrame:(CGRect)frame shareContextWith:(EAGLContext *)context;
+ (NSPointerArray*)playerViews;

- (id)initWithFrame:(CGRect)rect;
- (id)initWithFrame:(CGRect)rect shareContextWith:(EAGLContext*)context;

- (void)startAnimation;
- (void)stopAnimation;
- (void)setOrientation:(UIInterfaceOrientation)orientation;
- (void)cleanup;

@end

@protocol IM360ViewDelegate <NSObject>
@optional
- (void)playerInitialized:(id)sender;
- (void)playerTapped:(id)sender numberOfPoints:(int)numberOfPoints numberOfTaps:(int)numberOfTaps;
- (void)playerBeforeRender:(id)sender sceneRoot:(math::matrix*)sceneRoot;
- (void)playerAfterRender:(id)sender;
@end
