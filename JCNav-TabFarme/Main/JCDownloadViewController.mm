//
//  JCDownloadViewController.m
//  InstructionExample
//
//  Created by jamesczy on 15/7/27.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//  下载界面

#import "JCDownloadViewController.h"
#import "UIView+Extension.h"
#import "UIBarButtonItem+Extension.h"


@interface JCDownloadViewController ()

@end

@implementation JCDownloadViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIButton *downLoadTitleButton = [[UIButton alloc]init];
    downLoadTitleButton.width = 150;
    downLoadTitleButton.height = 30;
    
    [downLoadTitleButton setTitle:@"视频下载" forState:UIControlStateNormal];
    [downLoadTitleButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    downLoadTitleButton.titleLabel.font = [UIFont systemFontOfSize:17];
    
    self.navigationItem.titleView = downLoadTitleButton;
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"菜单"
                                                                             style:UIBarButtonItemStylePlain
                                                                            target:self
                                                                            action:@selector(presentLeftMenuViewController:)];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {

    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {

    // Return the number of rows in the section.
    return 20;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *ID = @"cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:ID ];
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:ID];
    }
//    cell.textLabel.text = [NSString stringWithFormat:@"视频下载－－－－－》%d",indexPath.row];
    return cell;
}




@end
