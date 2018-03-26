//
//  CBXHudViewTool.h
//  CaiBao
//
//  Created by 陆正现 on 2018/3/26.
//  Copyright © 2018年 91cb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CBXHudViewTool : NSObject

// 选择框 点击左右按钮的判断枚举
typedef enum : NSUInteger {
    clickLeft = 1,
    clickRight = 2,
} ClickType;

// 选择框 点击左右按钮后的回调
typedef void(^Block)(ClickType);

/**
 创建单例
 
 @return <#return value description#>
 */
+ (instancetype)shareHud;


/**
 1. 选择框

 @param titleArr 标题数组 （最多五行）
 @param fontArr 标题字体大小数组 （默认15）
 @param leftStr 左按钮内容
 @param leftColor 左按钮颜色 （默认黑色）
 @param rightStr 右按钮内容
 @param rightColor 右按钮颜色 （默认黑色）
 @param vc 当前控制器 （用于方法交换）
 @param block 点击选择按钮回调
 */
- (void)showHudWithContentTitle:(NSArray<NSString*>*)titleArr andFontArr:(NSArray<NSNumber*>*)fontArr andLeftChose:(NSString*)leftStr andLeftColor:(UIColor*)leftColor andRightChose:(NSString*)rightStr andRightColor:(UIColor*)rightColor inViewController:(UIViewController*)vc clickBlock:(void(^)(ClickType))block;


/**
 2. 带图片的提示框

 @param image 图片
 @param content 内容
 @param time 持续时间
 @param vc 当前控制器 （用于方法交换）
 */
- (void)showHudWithImage:(UIImage*)image andContent:(NSString*)content andTime:(int)time inVc:(UIViewController*)vc;


/**
 3. 进度提示框

 @param content 内容
 @param vc 当前控制器 （用于方法交换）
 */
- (void)showProgressHudViewWithContent:(NSString*)content andVc:(UIViewController*)vc;

/**
 4.成功提示框

 @param content <#content description#>
 */
- (void)showSuccessHudViewWithContent:(NSString*)content;

/**
 5.失败提示框

 @param content <#content description#>
 */
- (void)showFailHudViewWithContent:(NSString*)content;

/**
 手动隐藏提示框
 */
- (void)hiddeHud ;

@end
