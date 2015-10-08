//
//  JCCollectionCell.h
//  InstructionExample
//
//  Created by jamesczy on 15/7/27.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface JCCollectionCell : UICollectionViewCell
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UILabel *nameLable;
@property (nonatomic, strong) UIButton *button;

-(void)setCellTitle:(NSString *)title Name:(NSString *)name;

@end
