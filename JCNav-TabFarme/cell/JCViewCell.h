//
//  JCViewCell.h
//  InstructionExample
//
//  Created by jamesczy on 15/7/27.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface JCViewCell : UITableViewCell
@property (nonatomic,weak,readonly) UIView * cellView;
@property (nonatomic,weak,readonly) UILabel * nameLable;

-(instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier;

@end
