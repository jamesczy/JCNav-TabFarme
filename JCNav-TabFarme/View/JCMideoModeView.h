//
//  JCMideoModeView.h
//  TORNADO EYES
//
//  Created by yingyi on 15/8/19.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    JCMideoModeTypeStandard,//标准
    JCMideoModeTypeIs3DSide,//是否3
    JCMideoModeTypeCancel   //取消
}JCMideoModeType;
@class JCMideoModeView;
@protocol JCMideoModeViewDelegate <NSObject>
@optional
-(void)JCMideoModeView:(JCMideoModeView *)toolbar didClickButton:(JCMideoModeType)buttonType;
@end

@interface JCMideoModeView : UIView
@property (nonatomic ,weak) id<JCMideoModeViewDelegate> delegate;
@end
