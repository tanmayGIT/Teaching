//
//  ViewController.m
//  TestAlert
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
     [self addAlertView];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)addAlertView {
    UIAlertView *alertView = [[UIAlertView alloc]initWithTitle:
                              @"Title" message:@"This is a test alert" delegate:self
                                             cancelButtonTitle:@"Cancel" otherButtonTitles:@"Ok", nil];
    [alertView show];
}

#pragma mark - Alert view delegate
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:
(NSInteger)buttonIndex {
    switch (buttonIndex) {
        case 0:
            NSLog(@"Cancel button clicked");
            break;
            
        case 1:
            NSLog(@"OK button clicked");
            break;
            
        default:
            break;
    }
}


@end
