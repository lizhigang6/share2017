//
//  ABLEShareView.h
//  share2017
//
//  Created by user on 2017/2/23.
//  Copyright © 2017年 李志刚. All rights reserved.
//



/* 需要添加的sdk
 libz
 libicucore
 libsqlite3
 libstdc
 
 
 -ObjC
 
 
 info.plist  文件添加 
 LSApplicationQueriesSchemes
 weixin
 weibosdk
 sinaweibo
 weibosdk2.5
 
 <?xml version="1.0" encoding="UTF-8"?>
 <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
 <plist version="1.0">
 <dict>
	<key>NSAllowsArbitraryLoads</key>
	<true/>
	<key>sina.com.cn</key>
	<dict>
 <key>NSExceptionAllowsInsecureHTTPLoads</key>
 <true/>
 <key>NSExceptionMinimumTLSVersion</key>
 <string>TLSv1.0</string>
 <key>NSExceptionRequiresForwardSecrecy</key>
 <false/>
 <key>NSIncludesSubdomains</key>
 <true/>
	</dict>
	<key>weibo.cn</key>
	<dict>
 <key>NSExceptionAllowsInsecureHTTPLoads</key>
 <true/>
 <key>NSExceptionMinimumTLSVersion</key>
 <string>TLSv1.0</string>
 <key>NSExceptionRequiresForwardSecrecy</key>
 <false/>
 <key>NSIncludesSubdomains</key>
 <true/>
	</dict>
	<key>weibo.com</key>
	<dict>
 <key>NSExceptionAllowsInsecureHTTPLoads</key>
 <true/>
 <key>NSExceptionMinimumTLSVersion</key>
 <string>TLSv1.0</string>
 <key>NSExceptionRequiresForwardSecrecy</key>
 <false/>
 <key>NSIncludesSubdomains</key>
 <true/>
	</dict>
 </dict>
 </plist>

 */



#import <UIKit/UIKit.h>

@interface ABLEShareView : UIView
//点击按钮block回调
@property (nonatomic,copy) void(^btnClick)(NSInteger);



//头部提示文字
@property (nonatomic,copy) NSString *proStr;

//头部提示文字的字体大小
@property (nonatomic,assign) NSInteger proFont;

//取消按钮的颜色
@property (nonatomic,strong) UIColor *cancelBtnColor;

//取消按钮的字体大小
@property (nonatomic,assign) NSInteger cancelBtnFont;

//除了取消按钮其他按钮的颜色
@property (nonatomic,strong) UIColor *otherBtnColor;

//除了取消按钮其他按钮的字体大小
@property (nonatomic,assign) NSInteger otherBtnFont;

//设置弹窗背景蒙板灰度(0~1)
@property (nonatomic,assign) CGFloat duration;

/**
 *  初始化actionView
 *
 *  @param titleArray 标题数组
 *  @param imageArr   图片数组(如果不需要的话传空数组(@[])进来)
 *  @param protitle   最顶部的标题  不需要的话传@""
 *
 *  @return wu
 */

- (id)initWithShareHeadOprationWith:(NSArray *)titleArray andImageArry:(NSArray *)imageArr andProTitle:(NSString *)protitle shareTile:(NSString *)shareTile cancelTile:(NSString *)cancelTile;
@end
