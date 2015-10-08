//
//  JCInfoController.m
//  InstructionExample
//
//  Created by jamesczy on 15/7/27.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//  个人信息

#import "JCInfoController.h"
#import "UIView+Extension.h"
#import "UIBarButtonItem+Extension.h"


@interface JCInfoController ()

@end

@implementation JCInfoController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIButton *infoTitleButton = [[UIButton alloc]init];
    infoTitleButton.width = 150;
    infoTitleButton.height =30;
    
    [infoTitleButton setTitle:@"个人中心" forState:UIControlStateNormal];
    [infoTitleButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    infoTitleButton.titleLabel.font = [UIFont systemFontOfSize:17];
    
    self.navigationItem.titleView = infoTitleButton;

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
//    cell.textLabel.text = [NSString stringWithFormat:@"个人中心----->%d",indexPath.row];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSLog(@"this is %d line",indexPath.row);

}

@end
