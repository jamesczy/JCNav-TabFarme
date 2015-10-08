//
//  PlayerAppView.h
//  im360
//
//  Created by Ben Siroshton on 7/22/13.
//  Copyright (c) 2013 Immersive Media. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "im360/im360.h"

using namespace im360;

@interface PlayerAppView : UIView<UIWebViewDelegate, IM360ViewDelegate, EventListenerDelegate>

@property (nonatomic) player::Player::pointer player;

- (void)loadUrl:(NSString*)url;
//- (void)onEvent:(im360::event::Event::pointer)event;

- (void)didRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation;

@end
