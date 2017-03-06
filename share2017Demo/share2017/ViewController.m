//
//  ViewController.m
//  share2017
//
//  Created by user on 2017/2/23.
//  Copyright © 2017年 李志刚. All rights reserved.
//

#import "ViewController.h"
#import <ShareSDK/ShareSDK.h>
#import <ShareSDKUI/ShareSDK+SSUI.h>
#import <ABLEShareSdk/ABLEShareView.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIButton *shareBut =[[UIButton alloc] initWithFrame:CGRectMake(100, 100, 120, 50)];
    [shareBut setTitle:@"點擊分享" forState:UIControlStateNormal];
    [shareBut setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [shareBut addTarget:self action:@selector(share) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:shareBut];
}

-(void)share
{
    NSArray *titlearr = @[@"微信朋友圈",@"新浪微博",@"Facebook"];
    NSArray *imageArr = @[@"wechat",@"sinaweibo",@"facebook"];
    
    ABLEShareView *actionsheet = [[ABLEShareView alloc] initWithShareHeadOprationWith:titlearr andImageArry:imageArr andProTitle:@"測試" shareTile:@"分享到" cancelTile:@"取消"];
    [actionsheet setBtnClick:^(NSInteger btnTag) {
        
        if(btnTag ==0)
        {
            [self shrre:SSDKPlatformSubTypeWechatSession];
 
        }
        else if(btnTag ==1)
        {
            [self shrre:SSDKPlatformTypeSinaWeibo];

        }
        else if(btnTag ==2)
        {
            [self shrre:SSDKPlatformTypeFacebook];
            
        }
//        NSLog(@"\n点击第几个====%ld\n当前选中的按钮title====%@",btnTag,titlearr[btnTag]);
    }];
    [[UIApplication sharedApplication].keyWindow addSubview:actionsheet];

    
    
}

-(void)shrre:(int)shareType
{
    NSArray* imageArray = @[@"分享的图片url"];
    if (imageArray) {
        
        NSMutableDictionary *shareParams = [NSMutableDictionary dictionary];
        [shareParams SSDKSetupShareParamsByText:@"設置要分享的內容"
                                         images:imageArray
                                            url:[NSURL URLWithString:@"网页url"]
                                          title:@"测试要分享的標題"
                                           type:SSDKContentTypeAuto];
        
        [ShareSDK share:shareType parameters:shareParams onStateChanged:^(SSDKResponseState state, NSDictionary *userData, SSDKContentEntity *contentEntity, NSError *error) {
            
            
            switch (state) {
                case SSDKResponseStateSuccess:
                {
                    
                    NSLog(@"分享成功！");
                    break;
                }
                case SSDKResponseStateFail:
                {
                    
                    NSLog(@"分享失败！");
                    break;
                }
                default:
                    break;
            }
            
            
            
        }];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
