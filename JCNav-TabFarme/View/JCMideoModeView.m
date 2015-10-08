//
//  JCMideoModeView.m
//  TORNADO EYES
//
//  Created by yingyi on 15/8/19.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import "JCMideoModeView.h"
#import "UIView+Extension.h"

@implementation JCMideoModeView

-(instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        [self setupBtn:@"标准" type:JCMideoModeTypeStandard];
        [self setupBtn:@"3DSide/Side" type:JCMideoModeTypeIs3DSide];
        [self setupBtn:@"取消" type:JCMideoModeTypeCancel];
        
    }
    
    return self;
}
//创建按钮
-(void) setupBtn:(NSString *)title type:(JCMideoModeType)type
{
    UIButton *btn = [[UIButton alloc]init];
    [btn setTitle:title forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor blueColor] forState:UIControlStateHighlighted];
    [btn setBackgroundImage:[UIImage imageNamed:@"tabbar_background@2x.png"] forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    btn.tag = type;
    [self addSubview:btn];
}
-(void)btnClick:(UIButton *)btn
{
    if ([self.delegate respondsToSelector:@selector(JCMideoModeView: didClickButton:)]) {
        [self.delegate JCMideoModeView:self didClickButton:(JCMideoModeType)btn.tag];
    }
}
-(void)layoutSubviews
{
    [super layoutSubviews];
    //设置所有按钮的frame
    NSUInteger count = self.subviews.count;
    CGFloat btnW = (self.width - 11) / count;
    CGFloat btnH = self.height;
    
    for (NSUInteger i = 0; i < count; i++) {
        UIButton *btn = self.subviews[i];
        btn.width = btnW;
        btn.height = btnH;
        btn.y = 0;
        if (i == count - 1) {
            btn.x = i * btnW + 9;
        }else{
            btn.x = i * btnW;
        }
    }
}
@end
