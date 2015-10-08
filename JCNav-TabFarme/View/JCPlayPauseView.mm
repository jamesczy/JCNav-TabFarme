//
//  JCPlayPauseView.m
//  InstructionExample
//
//  Created by yingyi on 15/8/11.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import "JCPlayPauseView.h"
#import "UIView+Extension.h"

@interface JCPlayPauseView()


@end

@implementation JCPlayPauseView

#define buttomViewH 100

-(instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"compose_toolbar_background"]];
        self.moveBackBtn =  [self setupBtn:@"movieBackward@2x.png" hightImage:@"movieBackwardSelected@2x.png" type:JCPlayPauseViewButtonTypeBackward];
        self.playPauseBtn =  [self setupBtn:@"moviePause@2x.png" hightImage:@"moviePlay@2x.png" type:JCPlayPauseViewButtonTypePlayPause];
        self.moveForwordBtn = [self setupBtn:@"movieForward@2x.png" hightImage:@"movieForwardSelected@2x.png" type:JCPlayPauseViewButtonTypeForward];
        UISlider *progressBarView = [[UISlider alloc] init];
        self.progressBarView = progressBarView;
        [self addSubview:progressBarView];
    }
    return self;
}

//创建按钮
-(UIButton *) setupBtn:(NSString *)image hightImage:(NSString *)hightImage type:(JCPlayPauseViewButtonType)type
{
    UIButton *btn = [[UIButton alloc]init];
    [btn setImage:[UIImage imageNamed:image] forState:UIControlStateNormal];
    [btn setImage:[UIImage imageNamed:hightImage] forState:UIControlStateHighlighted];
    [btn addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    btn.tag = type;
    [self addSubview:btn];
    return btn;
}

-(void)btnClick:(UIButton *)btn
{
    if ([self.delegate respondsToSelector:@selector(JCPlayPauseView:didClickButton:)]) {
        [self.delegate JCPlayPauseView:self didClickButton:(JCPlayPauseViewButtonType)btn.tag];
    }
}
-(void)layoutSubviews
{
    [super layoutSubviews];
    //设置所有按钮的frame
    NSUInteger count = self.subviews.count;
    CGFloat btnW = self.width * 0.5 / count;
    CGFloat btnH = self.height;
    
    for (NSUInteger i = 0; i < count; i++) {
        if (i != count - 1) {
            UIButton *btn = self.subviews[i];
            btn.y = 0;
            btn.x = i * btnW;
            btn.width = btnW;
            btn.height = btnH;
        }else{
            UISlider *progressBarView = self.subviews[i];
            progressBarView.x = self.width * 0.5 + 10;
            progressBarView.y = (self.height - progressBarView.height) * 0.5;
            progressBarView.width = self.width * 0.5 - 20;
//            progressBarView.height = self.height * 0.5 ;
        }
        
    }
}


@end
