//
//  JCOnlineViewController.m
//  InstructionExample
//
//  Created by jamesczy on 15/7/27.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//  本地视频界面

#import "JCOnlineViewController.h"
#import "UIView+Extension.h"
#import "UIBarButtonItem+Extension.h"
#import "JCCollectionCell.h"
#import "JC360Controller.h"
#import "JCNavigationController.h"
#import "JCLocalVideoController.h"
#import "JCConst.h"

#import "JCSaveArchiverTool.h"
#import "JCPlayPathInfo.h"

@interface JCOnlineViewController ()
@property (nonatomic ,strong)NSMutableArray *titleArray;
@property (nonatomic ,strong)NSMutableArray *titlePathArray;
//沙盒中存放的播放列表
@property (nonatomic ,strong)NSArray *playList;
@end

static NSString * const reuseIdentifier = @"Cell";

@implementation JCOnlineViewController

-(instancetype)init
{
    UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc]init];
    layout.itemSize = CGSizeMake(150, 200);
    
    //    layout.minimumInteritemSpacing = 5;
    layout.minimumLineSpacing = 5;
    //设置itme的左右两边间距
    layout.sectionInset = UIEdgeInsetsMake(0, 5, 0, 5);

    
    return [super initWithCollectionViewLayout:layout];
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    // self.clearsSelectionOnViewWillAppear = NO;
//    self.collectionView.backgroundColor = [UIColor whiteColor];
    //拉伸背景图片
    UIImage *image = [UIImage imageNamed:@"MenuBackground"];
    image = [image resizableImageWithCapInsets:UIEdgeInsetsMake(5,5,5,5) resizingMode:UIImageResizingModeStretch];
    self.collectionView.layer.contents = (id)image.CGImage;
    
    self.collectionView.layer.backgroundColor = [UIColor clearColor].CGColor;
    
    // Register cell classes
    [self.collectionView registerClass:[JCCollectionCell class] forCellWithReuseIdentifier:reuseIdentifier];
    
    //获取沙盒中的播放列表
//    self.playList = [JCSaveArchiverTool playPathInfo];
//    NSLog(@"%@",self.playList);
    UIButton *infoTitleButton = [[UIButton alloc]init];
    infoTitleButton.width = 150;
    infoTitleButton.height =30;
    
    [infoTitleButton setTitle:@"本地视频" forState:UIControlStateNormal];
    [infoTitleButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    infoTitleButton.titleLabel.font = [UIFont systemFontOfSize:17];
    
    self.navigationItem.titleView = infoTitleButton;
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"菜单"
                                                                             style:UIBarButtonItemStylePlain
                                                                            target:self
                                                                            action:@selector(presentLeftMenuViewController:)];
    
}
-(void)viewWillAppear:(BOOL)animated
{
    NSString *docsDir = [NSHomeDirectory() stringByAppendingPathComponent:  @"Documents"];
//    [self logFilePathInDocumentsDir];
 
    self.titlePathArray = [self getFilenamelistOfType:@"mp4" fromDirPath:docsDir];
}
/**
 读取本地文件列表
 */
-(NSArray *)getFilenamelistOfType:(NSString *)type fromDirPath:(NSString *)dirPath
{
    NSString *docsDir = [NSHomeDirectory() stringByAppendingPathComponent:  @"Documents"];
    
    NSMutableArray *filenamelist = [NSMutableArray arrayWithCapacity:10];
    NSMutableArray *filenamePathlist = [NSMutableArray arrayWithCapacity:10];
    NSArray *tmplist = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:dirPath error:nil];
    
    for (NSString *filename in tmplist) {
        NSString *fullpath = [dirPath stringByAppendingPathComponent:filename];
        if ([self isFileExistAtPath:fullpath]) {
            if ([[filename pathExtension] isEqualToString:type]) {
                [filenamelist  addObject:filename];
                [filenamePathlist  addObject:[docsDir stringByAppendingPathComponent:filename]];
            }
        }
    }
    
    self.titleArray = filenamelist;
//    NSLog(@"filenamelist -->%@",filenamelist);
    
    return filenamePathlist;
}
-(BOOL)isFileExistAtPath:(NSString*)fileFullPath {
    BOOL isExist = NO;
    isExist = [[NSFileManager defaultManager] fileExistsAtPath:fileFullPath];
    return isExist;
}
/**
//读取本地文件
- (void)logFilePathInDocumentsDir
{
    NSString *docsDir = [NSHomeDirectory() stringByAppendingPathComponent:  @"Documents"];
    NSLog(@"docsDir ---> %@",docsDir);
    NSFileManager *fileManager = [NSFileManager defaultManager];
    //枚举出目录的内容
    NSDirectoryEnumerator *dirEnum = [fileManager enumeratorAtPath:docsDir];
    
    NSArray *array = [fileManager contentsOfDirectoryAtPath:docsDir error:nil];
    NSString *fileName;
    NSString *fileNamePath;
    int i = 0;
    
    while (fileName = [dirEnum nextObject]) {
        i++;
        
        NSLog(@"FielName : %@" , fileName);
        NSLog(@"FileFullPath : %@" , [docsDir stringByAppendingPathComponent:fileName]) ;
        fileNamePath = [docsDir stringByAppendingPathComponent:fileName];
    }
    
    self.titleArray = array;
    NSLog(@"%d",self.titleArray.count);
}
 */
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark <UICollectionViewDataSource>

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {

    return 1;
}


- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    
    return self.titleArray.count;
}


- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    JCCollectionCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:reuseIdentifier forIndexPath:indexPath];
    
    if (cell == nil) {
        cell = [[JCCollectionCell alloc]init];
    }
    [cell setCellTitle:self.titleArray[indexPath.row] Name:self.titleArray[indexPath.row]];
    return cell;
}

-(void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    JCLocalVideoController *vc = [[JCLocalVideoController alloc]init];
    vc.videoURL = self.titlePathArray[indexPath.row];
    
    JCPlayPathInfo * info = [[JCPlayPathInfo alloc]init];
//    info.videoURL = vc.videoURL;
//    info.videoName = self.titleArray[indexPath.row];
//    
//    
//    [JCSaveArchiverTool addPlayPath:info];
    //发出视频被选中的通知
    NSMutableDictionary *userInfo = [NSMutableDictionary dictionary];
    userInfo[selectedPlayListKye] = info;
    [[NSNotificationCenter defaultCenter] postNotificationName:selectedPlayListName object:nil userInfo:userInfo];
    
    JCNavigationController *nav = [[JCNavigationController alloc]initWithRootViewController:vc];
    [self presentViewController:nav animated:YES completion:nil];
//        [self.navigationController pushViewController:vc animated:TRUE];
}

@end
