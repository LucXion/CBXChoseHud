//
//  CBXChoseHud.h
//  tishikuang
//
//  Created by 陆正现 on 2018/2/27.
//  Copyright © 2018年 陆正现. All rights reserved.
//  一个提示框的封装

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 用户点击左右按钮对应的代理放方法
 */
@protocol CBXChoseHudDelegate <NSObject>

- (void)cbxChoseHudClickLeftBtn;

- (void)cbxChoseHudClickRightBtn;

@end

@interface CBXChoseHud : NSObject

@property(nonatomic,weak)id<CBXChoseHudDelegate> delegate;

/**
 1. 创建单例

 @return <#return value description#>
 */
+ (instancetype)shareHud;

/**
 2. 展示提示框

 @param titleArr 标题每行显示的内容
 @param fontArr 标题每行对应的字体大小
 @param leftStr 左选项内容
 @param leftColor 左选项颜色
 @param rightStr 右选项内容
 @param rightColor 右选项颜色
 @param vc 加载到的控制器（用于方法交换，隐藏界面时移除提示框）
 */
- (void)showHudWithContentTitle:(NSArray<NSString*>*)titleArr andFontArr:(NSArray<NSNumber*>*)fontArr andLeftChose:(NSString*)leftStr andLeftColor:(UIColor*)leftColor andRightChose:(NSString*)rightStr andRightColor:(UIColor*)rightColor inViewController:(UIViewController*)vc;


/**
 3.手动隐藏提示框
 */
- (void)hiddeHud ;


//- (void)showHudMessage:(NSArray<NSString*>*)TitleArr andLeftChoseContent:(NSString*)leftContent andLeftContentColor:(UIColor*)leftColor andRightChoseContent:(NSString*)RightContent andRightContentColor:(UIColor*)rightColor InView:(UIViewController*)view;
@end
