//
//  IOSEventListener.h
//  libim360
//
//  Created by Ben Siroshton on 7/23/13.
//  Copyright (c) 2013 Immersive Ventures. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "im360/event/EventListener.h"
#include "im360/event/Event.h"

@protocol EventListenerDelegate <NSObject>
@optional
- (void)onEvent:(im360::event::Event::pointer)event;
@end

@interface IOSEventListener : NSObject

@property (assign, nonatomic) id<EventListenerDelegate> delegate;

- (im360::event::EventListener::pointer)getListener;

@end
