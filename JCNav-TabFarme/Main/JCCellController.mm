//
//  JCCellController.m
//  InstructionExample
//
//  Created by jamesczy on 15/7/27.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//   我的视频界面，播放记录

#import "JCCellController.h"
#import "JCCollectionCell.h"
#import "JC360Controller.h"
#import "JCNavigationController.h"
#import "JCLocalVideoController.h"
#import "JCConst.h"
#import "UIView+Extension.h"

#import "JCSaveArchiverTool.h"
#import "JCPlayPathInfo.h"

@interface JCCellController ()
@property (nonatomic ,assign)NSUInteger count;

@property (nonatomic ,strong)NSMutableArray *titleArray;
@property (nonatomic ,strong)NSMutableArray *titlePathArray;
@end

@implementation JCCellController

static NSString * const reuseIdentifier = @"Cell";

-(instancetype)init
{
    UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc]init];
    layout.itemSize = CGSizeMake(150, 200);
    
//    layout.minimumInteritemSpacing = 5;
    layout.minimumLineSpacing = 5;
    //设置itme的左右两边间距
    layout.sectionInset = UIEdgeInsetsMake(0, 5, 0, 5);
    //被选中的通知
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(selectedPlayList) name:selectedPlayListName object:nil];
    
    return [super initWithCollectionViewLayout:layout];
}
#pragma mark - 监听方法
-(void)selectedPlayList
{
    
    self.playList = nil;
    self.titleArray = nil;
    self.titlePathArray = nil;
    
    self.playList = [JCSaveArchiverTool playPathInfo];
    
    for (int i = 0; i < self.playList.count; i++) {
        JCPlayPathInfo *jcInfo = self.playList[i];
        NSLog(@"jcInfo->%@:%@,%@",jcInfo,jcInfo.videoName,jcInfo.videoURL);
        [self.titleArray addObject:jcInfo.videoName];
        [self.titlePathArray addObject:jcInfo.videoURL];
        
    }
    NSLog(@"titlePathArray ->%@",self.titlePathArray );
    [self.view setNeedsLayout];
}

-(void)setPlayList:(NSArray *)playList
{
    _playList = playList;
    self.count = playList.count;
    
}
- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations
    // self.clearsSelectionOnViewWillAppear = NO;
//    self.collectionView.backgroundColor = [UIColor whiteColor];
    self.collectionView.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"Stars"]];
    UIButton *infoTitleButton = [[UIButton alloc]init];
    infoTitleButton.width = 150;
    infoTitleButton.height =30;
    
    [infoTitleButton setTitle:@"我的视频" forState:UIControlStateNormal];
    [infoTitleButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    infoTitleButton.titleLabel.font = [UIFont systemFontOfSize:17];
    
    self.navigationItem.titleView = infoTitleButton;
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"菜单"
                                                                             style:UIBarButtonItemStylePlain
                                                                            target:self
                                                                            action:@selector(presentLeftMenuViewController:)];
    // Register cell classes
//    [self.collectionView registerClass:[JCCollectionCell class] forCellWithReuseIdentifier:reuseIdentifier];
//    // Do any additional setup after loading the view.
//    self.playList = [JCSaveArchiverTool playPathInfo];
    
//    for (int i = 0; i < self.playList.count; i++) {
//        JCPlayPathInfo *jcInfo = self.playList[i];
//        NSLog(@"jcInfo->%@:%@,%@",jcInfo,jcInfo.videoName,jcInfo.videoURL);
//        [self.titleArray addObject:jcInfo.videoName];
//        [self.titlePathArray addObject:jcInfo.videoURL];
//        NSLog(@"titleArray=%@",self.titleArray[i]);
//        NSLog(@"titlePathArray=%@",self.titlePathArray[i]);
//    }
//    NSLog(@"viewDidLoad==>titlePathArray-> %@",self.titlePathArray);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark <UICollectionViewDataSource>

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {

    return 1;
}


- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {

    return self.count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    JCCollectionCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:reuseIdentifier forIndexPath:indexPath];
    
    if (cell == nil) {
        cell = [[JCCollectionCell alloc]init];
        cell.backgroundColor = [UIColor clearColor];
    }

    JCPlayPathInfo *playInfo = self.playList[indexPath.row];
    [cell setCellTitle:playInfo.videoName Name:playInfo.videoName];
    return cell;

    
}

#pragma mark <UICollectionViewDelegate>
//UICollectionView被选中时调用的方法
//-(void)collectionView:(UICollectionView *)collectionView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath
//{
//    NSLog(@"这是第 %d 行被点击了。",indexPath.row);
//    JC360Controller *vc = [[JC360Controller alloc]init];
//    [self presentViewController:vc animated:YES completion:nil];
////    [self presentModalViewController:vc animated:YES];
////    [self.navigationController pushViewController:vc animated:TRUE];
//    
//}

-(void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    /**
    NSLog(@"这是第 %d 行被点击了。",indexPath.row);
    JC360Controller *vc = [[JC360Controller alloc]init];
//    ViewController *vc = [[ViewController alloc]init];
    JCNavigationController *nav = [[JCNavigationController alloc]initWithRootViewController:vc];
    [self presentViewController:nav animated:YES completion:nil];
//    [self.navigationController pushViewController:vc animated:TRUE];
    */
    NSLog(@"这是第 %d 行被点击了。",indexPath.row);
    JCLocalVideoController *vc = [[JCLocalVideoController alloc]init];
    vc.videoURL = self.titlePathArray[indexPath.row];
    NSLog(@"%@",vc.videoURL);
    JCPlayPathInfo * info = [[JCPlayPathInfo alloc]init];
    info.videoURL = vc.videoURL;
    info.videoName = self.titleArray[indexPath.row];
    
    [JCSaveArchiverTool addPlayPath:info];
    //发出视频被选中的通知
    NSMutableDictionary *userInfo = [NSMutableDictionary dictionary];
    userInfo[selectedPlayListKye] = info;
    [[NSNotificationCenter defaultCenter] postNotificationName:selectedPlayListName object:nil userInfo:userInfo];
    
    
    JCNavigationController *nav = [[JCNavigationController alloc]initWithRootViewController:vc];
    [self presentViewController:nav animated:YES completion:nil];
}


@end
