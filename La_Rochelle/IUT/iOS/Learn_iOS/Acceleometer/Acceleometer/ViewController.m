//
//  ViewController.m
//  Acceleometer
//
//  Created by Tanmoy on 09/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [[UIAccelerometer sharedAccelerometer]setDelegate:self];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:
(UIAcceleration *)acceleration {
    [_myLabelX setText:[NSString stringWithFormat:@"%f",acceleration.x]];
    [_myLabelY setText:[NSString stringWithFormat:@"%f",acceleration.y]];
    [_myLabelZ setText:[NSString stringWithFormat:@"%f",acceleration.z]];
}


@end
