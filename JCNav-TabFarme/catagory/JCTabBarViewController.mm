//
//  JCTabBarViewController.m
//  微博
//
//  Created by jamesczy on 15/7/12.
//  Copyright (c) 2015年 jamesczy. All rights reserved.
//

#import "JCTabBarViewController.h"
#import "JCNavigationController.h"
#import "JCConst.h"
#import "ViewController.h"
#import "JCOnlineViewController.h"
#import "JCDownloadViewController.h"
#import "JCInfoController.h"
#import "JCCellController.h"
//#import "JCTabBar.h"
//
//@interface JCTabBarViewController ()<JCTabBarDelegate>
//
//@end

@implementation JCTabBarViewController


-(void)addChildVc:(UIViewController *)childVc title:(NSString *)title image:(NSString *)image selectedImage:(NSString *)selectedImage
{
    childVc.title = title;
    
    
    childVc.tabBarItem.image = [UIImage imageNamed:image];
    childVc.tabBarItem.selectedImage = [[UIImage imageNamed:selectedImage]imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    
    //设置文字的样式
    NSMutableDictionary *textAttrs = [NSMutableDictionary dictionary];
    textAttrs[NSForegroundColorAttributeName] = JCColor(123, 123, 123);
    NSMutableDictionary *selectTextAttrs = [NSMutableDictionary dictionary];
    selectTextAttrs[NSForegroundColorAttributeName] = [UIColor blueColor];
    
    [childVc.tabBarItem setTitleTextAttributes:textAttrs forState:UIControlStateNormal];
    [childVc.tabBarItem setTitleTextAttributes:selectTextAttrs forState:UIControlStateSelected];
    [childVc.tabBarItem setTitleTextAttributes:textAttrs forState:UIControlStateNormal];
    [childVc.tabBarItem setTitleTextAttributes:selectTextAttrs forState:UIControlStateSelected];
    
//    childVc.view.backgroundColor = JCRandomColor;
    //先把外面传进来的控制器包装一个导航器
    UINavigationController *nav = [[JCNavigationController alloc]initWithRootViewController:childVc];
    //添加自控制器
    [self addChildViewController:nav];
}
- (void)viewDidLoad {
    [super viewDidLoad];
    
    JCCellController *home = [[JCCellController alloc]init];
    [self addChildVc:home title:@"我的视频" image:@"tabbar_home" selectedImage:@"tabbar_home_selected"];

    JCOnlineViewController *onLine =[[JCOnlineViewController alloc]init];
    [self addChildVc:onLine title:@"本地视频" image:@"tabbar_message_center" selectedImage:@"tabbar_message_center_selected"];
    
    JCDownloadViewController *downLoad = [[JCDownloadViewController alloc]init];
    [self addChildVc:downLoad title:@"视频下载" image:@"tabbar_discover" selectedImage:@"tabbar_discover_selected"];
    
    JCInfoController *info = [[JCInfoController alloc]init];
    [self addChildVc:info title:@"个人中心" image:@"tabbar_profile" selectedImage:@"tabbar_profile_selected"];
    
  
    //更换系统自带的tabbar
//    JCTabBar *tabBar = [[JCTabBar alloc]init];
//    tabBar.delegate = self;
//    [self setValue:tabBar forKeyPath:@"tabBar"];
    // Do any additional setup after loading the view.
}


//#pragma mark -JCtabBar的代理
//-(void)tababBarDidClickPlusButton:(JCTabBar *)tabBar
//{
//    UIViewController *vc = [[UIViewController alloc]init];
//    vc.view.backgroundColor = [UIColor yellowColor];
//    [self presentViewController:vc animated:YES completion:nil];
//}

@end
