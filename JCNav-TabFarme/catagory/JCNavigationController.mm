//
//  JCNavigationController.m
//  微博
//
//  Created by jamesczy on 15/7/13.
//  Copyright (c) 2015年 jamesczy. All rights reserved.
//

#import "JCNavigationController.h"
#import "UIView+Extension.h"
#import "UIBarButtonItem+Extension.h"

@interface JCNavigationController ()

@end

@implementation JCNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
}
+(void)initialize
{
    //设置item的样式
    UIBarButtonItem *item = [UIBarButtonItem appearance];
    //设置普通状态
    NSMutableDictionary *textAttrs = [NSMutableDictionary dictionary];
    textAttrs[NSForegroundColorAttributeName] = [UIColor blueColor];
    textAttrs[NSFontAttributeName] = [UIFont systemFontOfSize:13];
    [item setTitleTextAttributes:textAttrs forState:UIControlStateNormal];
    //设置不可用状态
    NSMutableDictionary *disableTextAttrs = [NSMutableDictionary dictionary];
    disableTextAttrs[NSForegroundColorAttributeName] = [UIColor grayColor];
    disableTextAttrs[NSFontAttributeName] = [UIFont systemFontOfSize:13];
    [item setTitleTextAttributes:disableTextAttrs forState:UIControlStateDisabled];
}
-(void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated
{
    if (self.viewControllers.count > 1) {
        UIBarButtonItem *leftItem = [UIBarButtonItem itemWithTarget:self action:@selector(back) image:@"navigationbar_back" highImage:@"navigationbar_back_highlighted"];
        viewController.navigationItem.leftBarButtonItem = leftItem;
        
    }
    [super pushViewController:viewController animated:YES];
    
}
-(void)back
{
    [self popViewControllerAnimated:YES];
    
}

@end
