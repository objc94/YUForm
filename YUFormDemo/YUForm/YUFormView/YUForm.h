//
//  ShellKitSelectTableView.h
//  ShellKitDemo
//
//  Created by jimi on 2018/5/25.
//  Copyright © 2018年 jimi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ShellKitSelectTableViewDataSource.h"
#import "YUFormCellModel.h"
#import "YUFormSectionModel.h"
#import "UITableView+YUTableViewAddition.h"
@class YUForm;
typedef NS_ENUM(NSUInteger, RegClassType) {
    RegClassTypeCell = 1 ,
    RegClassTypeHeadView = 2
};

//选择项cell需要实现我
@protocol ShellKitSelectTableView<NSObject>
@required
- (void)shell_setModel:(YUFormCellModel *) model;
- (void)shell_selectedStatus;
- (void)shell_unSelectStatus;
@end

//文本框需要实现我
@protocol YUCheckBoxRowTextCellDelegate<NSObject>
@required
- (void)shell_setModel:(YUFormCellModel *) model;
- (UIView *)shell_inputView ;
@end

// sectionView 要实现我
@protocol YUCheckBoxSectionDelegate<NSObject>
@required
- (void)shell_setModel:(YUFormSectionModel *) model;
@end

@interface YUForm : UIView
@property (strong,nonatomic) ShellKitSelectTableViewDataSource * tableViewDataSource;
@property (strong,nonatomic) UITableView *tableView;
- (void)addSectionModel:(YUFormSectionModel *)sectionModel;
- (void)reloadData ;
@end
