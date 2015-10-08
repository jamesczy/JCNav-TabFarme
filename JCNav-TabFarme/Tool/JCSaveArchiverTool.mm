//
//  JCSaveArchiverTool.m
//  TORNADO EYES
//
//  Created by yingyi on 15/9/6.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#define JCPlayPath [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"PlayPathInfo.archive"]

#import "JCSaveArchiverTool.h"
#import "JCPlayPathInfo.h"

static NSMutableArray *_playPathInfo;

@implementation JCSaveArchiverTool
+(void)initialize
{
    _playPathInfo = [NSKeyedUnarchiver unarchiveObjectWithFile:JCPlayPath];
    if (_playPathInfo == nil) {
        _playPathInfo = [NSMutableArray array];
    }
}

+(void)addPlayPath:(JCPlayPathInfo *)playPathInfo
{
    //加载沙盒中的播放数据
    [_playPathInfo removeObject:playPathInfo];
    //将播放数据放到数组的最前面
    [_playPathInfo insertObject:playPathInfo atIndex:0];
    //将所有播放数据写入沙盒
    [NSKeyedArchiver archiveRootObject:_playPathInfo toFile:JCPlayPath];
    
}
//返回装有playPathInfo的数组
+(NSArray *)playPathInfo
{
    return _playPathInfo;
}
@end
