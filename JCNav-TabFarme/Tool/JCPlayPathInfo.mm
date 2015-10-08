//
//  JCPlayPathInfo.m
//  TORNADO EYES
//
//  Created by yingyi on 15/9/6.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import "JCPlayPathInfo.h"
#import "MJExtension.h"

@interface JCPlayPathInfo() <NSCoding>

@end

@implementation JCPlayPathInfo
//把模型中的属性写入／读出沙盒
MJCodingImplementation


//重写次发方法，在删除时调用[_playPathInfo removeObject:playPathInfo]；
-(BOOL)isEqual:(JCPlayPathInfo *)other
{
    return [self.videoName isEqualToString:other.videoName];
}
@end
