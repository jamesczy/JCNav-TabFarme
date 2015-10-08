//
//  UIBarButtonItem+Extension.h
//  微博
//
//  Created by jamesczy on 15/7/13.
//  Copyright (c) 2015年 jamesczy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (Extension)


+(UIBarButtonItem *)itemWithTarget:(id)target action:(SEL)action image:(NSString *)image highImage:(NSString *)highImage;
@end
