//
//  ViewController.m
//  Test_FirstApplication_1
//
//  Created by Tanmoy on 07/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    CALayer *btnLayer = [_buttonPropertyChange layer];
    [btnLayer setMasksToBounds:YES];
    [btnLayer setCornerRadius:5.0f];
    btnLayer.backgroundColor = [[UIColor grayColor]CGColor];
    btnLayer.borderWidth = 2.0f;
    btnLayer.borderColor = [[UIColor greenColor]CGColor];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (IBAction)clickOnButton:(id)sender {
    [_showMyLabels setText:@"Hello, How Are You !!"];
}
@end
