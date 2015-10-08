//
//  JCPlayPauseView.h
//  InstructionExample
//
//  Created by yingyi on 15/8/11.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef enum {
    JCPlayPauseViewButtonTypePlayPause, //播放
    JCPlayPauseViewButtonTypeBackward,  //回退
    JCPlayPauseViewButtonTypeForward    //快进
}JCPlayPauseViewButtonType;

@class JCPlayPauseView;
@protocol JCPlayPauseViewDelegate <NSObject>
@optional
-(void)JCPlayPauseView:(JCPlayPauseView *)toolbar didClickButton:(JCPlayPauseViewButtonType)buttonType;
@end
@interface JCPlayPauseView : UIView
/** 暂停播放界面 */
@property (nonatomic ,weak)UIView *buttomView;
/** 播放暂停按钮 */
@property (nonatomic ,weak)UIButton *playPauseBtn;
/** 回退按钮 */
@property (nonatomic ,weak)UIButton *moveBackBtn;
/** 快进按钮 */
@property (nonatomic ,weak)UIButton *moveForwordBtn;
/** 进度条 */
@property (nonatomic ,weak)UISlider *progressBarView;
@property (nonatomic ,weak)id <JCPlayPauseViewDelegate> delegate;
@end
