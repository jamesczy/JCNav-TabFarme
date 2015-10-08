//
//  JCSaveArchiverTool.h
//  TORNADO EYES
//
//  Created by yingyi on 15/9/6.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import <Foundation/Foundation.h>
@class JCPlayPathInfo;

@interface JCSaveArchiverTool : NSObject
+(void)addPlayPath:(JCPlayPathInfo *)playPathInfo;

//返回装有playPathInfo的数组
+(NSArray *)playPathInfo;
@end
