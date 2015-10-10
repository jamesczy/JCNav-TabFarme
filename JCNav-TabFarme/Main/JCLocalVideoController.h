//
//  JCLocalVideoController.h
//  TORNADO EYES
//
//  Created by yingyi on 15/8/18.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <im360/im360.h>

@interface JCLocalVideoController : UIViewController <IM360ViewDelegate>{
    IM360View *                     _im360View;
    im360::player::Player::pointer  _player;
    NSTimer*                        _starTimer;
    void *                          _mediaData;
}
@property (nonatomic ,copy)NSString *videoURL;
@property (nonatomic ,copy)NSString *audeoURL;
// Player media events 播放器 播放事件
- (void)onMediaPlayStateChange:(im360::event::MediaEvent::pointer)event;
- (void)onMediaTimeChange:(im360::event::TimeChangeEvent::pointer)event;



@end
