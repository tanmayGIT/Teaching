//
//  ViewController.h
//  ExampleViewTransition
//
//  Created by Tanmoy on 15/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
{
    UIView *view1;
    UIView *view2;
}
- (IBAction)curlDown:(id)sender;
- (IBAction)curlUp:(id)sender;
- (IBAction)flipFromTop:(id)sender;
- (IBAction)flipFromBottom:(id)sender;
- (IBAction)flipFromRight:(id)sender;
- (IBAction)flipFromLeft:(id)sender;
- (IBAction)dissolve:(id)sender;
- (IBAction)noTransition:(id)sender;

@end

