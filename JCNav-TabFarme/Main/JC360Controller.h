//
//  JC360Controller.h
//  InstructionExample
//
//  Created by jamesczy on 15/7/28.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <im360/im360.h>

@interface JC360Controller : UIViewController <IM360ViewDelegate>{
    IM360View * _im360View;
    im360::player::Player::pointer _player;
}

@property (nonatomic ,copy)NSString *videoURL;
@property (nonatomic ,copy)NSString *audeoURL;
// Player media events 播放器 播放事件
- (void)onMediaPlayStateChange:(im360::event::MediaEvent::pointer)event;
- (void)onMediaTimeChange:(im360::event::TimeChangeEvent::pointer)event;

@end
