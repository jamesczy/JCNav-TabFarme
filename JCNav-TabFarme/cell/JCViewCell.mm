//
//  JCViewCell.m
//  InstructionExample
//
//  Created by jamesczy on 15/7/27.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import "JCViewCell.h"
#import "UIView+Extension.h"

@implementation JCViewCell

- (void)awakeFromNib {
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}


-(instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];

    if (self != nil) {
        UIView *cellView = [[UIView alloc]init];
        cellView.frame = CGRectMake(5, 5, 100, 100);
        [self.contentView addSubview: cellView];
        _cellView = cellView;
        
        UILabel *nameLable = [[UILabel alloc]init];
        nameLable.frame = CGRectMake(5, 75, 90, 15);
        [self.cellView addSubview:nameLable];
        _nameLable = nameLable;
        
    }
    return self;
}


@end
