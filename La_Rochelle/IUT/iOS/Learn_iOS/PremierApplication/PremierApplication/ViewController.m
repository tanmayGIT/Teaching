//
//  ViewController.m
//  PremierApplication
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
    
    CALayer *btnLayer = [_changeButton layer];
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


- (IBAction)myButtonWork:(id)sender {
    [_showMyLabel setText:@"Hello, How Are You !!"];
}
@end
