//
//  CBXChoseHud.m
//  tishikuang
//
//  Created by 陆正现 on 2018/2/27.
//  Copyright © 2018年 陆正现. All rights reserved.
//

#import "CBXChoseHud.h"
#import<objc/runtime.h>
#import "CBXChoseHudView.h"

@interface CBXChoseHud()<CBXChoseHudViewDelegate>

/**
 提示框视图
 */
@property(nonatomic,weak)CBXChoseHudView *hudView;

/**
 进行方法交换的控制器，监控控制器视图隐藏，移除提示框
 */
@property(nonatomic,weak)UIViewController *vc;

@end

static CBXChoseHud *shareInstance;

@implementation CBXChoseHud

/**
 创建单例对象

 @return <#return value description#>
 */
+ (instancetype)shareHud {
    
    if (shareInstance == nil) {
        shareInstance = [[CBXChoseHud alloc]init];
    }
    return shareInstance;
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        shareInstance = [super allocWithZone:zone];
    });
    
    return shareInstance;
}


/**
 提示框展示

 @param titleArr <#titleArr description#>
 @param fontArr <#fontArr description#>
 @param leftStr <#leftStr description#>
 @param leftColor <#leftColor description#>
 @param rightStr <#rightStr description#>
 @param rightColor <#rightColor description#>
 @param vc <#vc description#>
 */
- (void)showHudWithContentTitle:(NSArray<NSString *> *)titleArr andFontArr:(NSArray<NSNumber *> *)fontArr andLeftChose:(NSString *)leftStr andLeftColor:(UIColor *)leftColor andRightChose:(NSString *)rightStr andRightColor:(UIColor *)rightColor inViewController:(UIViewController *)vc {
    
    
    // 避免重复调用
    if (self.hudView == nil) {
        
        CBXChoseHudView *view= [[CBXChoseHudView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
        
        view.titleFontArr = fontArr;
        view.titleArr = titleArr;
        view.leftTitle = leftStr;
        view.rightTitle = rightStr;
        view.leftColor = leftColor;
        view.rightColor = rightColor;
        
        [[UIApplication sharedApplication].keyWindow addSubview:view];
        view.delegate = self;
        self.hudView = view;
        
        
        // 方法交换，监听控制器视图消失的方法
        Method originalM = class_getInstanceMethod([vc class], @selector(viewWillDisappear:));
        
        Method exchangeM = class_getInstanceMethod([self class], @selector(replaceMethod));
        
        method_exchangeImplementations(originalM, exchangeM);
    }
}


- (void)replaceMethod {
    
    // 界面消失，移除提示框
    [[CBXChoseHud shareHud] hiddeHud];
    
    Method originalM = class_getInstanceMethod([self class], @selector(viewWillDisappear:));
    
    Method exchangeM = class_getInstanceMethod([[CBXChoseHud shareHud] class], @selector(replaceMethod));

    /** 恢复已交换的方法 */
    method_exchangeImplementations(originalM, exchangeM);
    
    // 执行替换的方法 避免方法交换导致原方法不能执行的问题
    [self performSelector:@selector(viewWillDisappear:)];
}

/**
 手动隐藏view
 */
- (void)hiddeHud {
 
    [self.hudView removeFromSuperview];
    self.hudView = nil;
}

#pragma mark CBXChoseHudViewDelegate
- (void)clickLeftBtn {
    
    if([self.delegate respondsToSelector:@selector(cbxChoseHudClickLeftBtn)]){
        [self.delegate cbxChoseHudClickLeftBtn];
    }
}

- (void)clickRightBtn {
    
    if([self.delegate respondsToSelector:@selector(cbxChoseHudClickRightBtn)]){
        [self.delegate cbxChoseHudClickRightBtn];
    }
}


@end
