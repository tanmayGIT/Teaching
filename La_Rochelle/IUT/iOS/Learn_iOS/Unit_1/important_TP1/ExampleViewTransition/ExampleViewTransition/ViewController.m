//
//  ViewController.m
//  ExampleViewTransition
//
//  Created by Tanmoy on 15/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(void)setUpView {
    view1 = [[UIView alloc]initWithFrame:self.view.frame];
    view1.backgroundColor = [UIColor lightTextColor];
    view2 = [[UIView alloc]initWithFrame:self.view.frame];
    view2.backgroundColor = [UIColor orangeColor];
    [self.view addSubview:view1];
    [self.view sendSubviewToBack:view1];
}

-(void)doTransitionWithType:(UIViewAnimationTransition)animationTransitionType {
    
    if ([[self.view subviews] containsObject:view2 ]) {
        [UIView transitionFromView:view2
                            toView:view1
                          duration:2
                           options:animationTransitionType
                        completion:^(BOOL finished) {
                            [view2 removeFromSuperview];
                        }];
        [self.view addSubview:view1];
        [self.view sendSubviewToBack:view1];
    } else {
        [UIView transitionFromView:view1
                            toView:view2
                          duration:2
                           options:animationTransitionType
                        completion:^(BOOL finished) {
                            [view1 removeFromSuperview];
                        }];
        [self.view addSubview:view2];
        [self.view sendSubviewToBack:view2];
    }
}


- (IBAction)curlDown:(id)sender {
    [self doTransitionWithType:UIViewAnimationOptionTransitionCurlDown];
}

- (IBAction)curlUp:(id)sender {
    [self doTransitionWithType:UIViewAnimationOptionTransitionCurlUp];
}

- (IBAction)flipFromTop:(id)sender {
    [self doTransitionWithType:UIViewAnimationOptionTransitionFlipFromTop];
}

- (IBAction)flipFromBottom:(id)sender {
    [self doTransitionWithType:UIViewAnimationOptionTransitionFlipFromBottom];
}

- (IBAction)flipFromRight:(id)sender {
    [self doTransitionWithType:UIViewAnimationOptionTransitionFlipFromRight];
}

- (IBAction)flipFromLeft:(id)sender {
    [self doTransitionWithType:UIViewAnimationOptionTransitionFlipFromLeft];
}

- (IBAction)dissolve:(id)sender {
    [self doTransitionWithType:UIViewAnimationOptionTransitionCrossDissolve];
}

- (IBAction)noTransition:(id)sender {
    [self doTransitionWithType:UIViewAnimationOptionTransitionNone];
}

@end
