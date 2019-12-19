//
//  ViewController.m
//  Test_iOS_App_1
//
//  Created by Tanmoy on 06/01/18.
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


- (IBAction)clickOnButton:(id)sender {
    [_myButtonClickedLabel setText:@"Hello, How are you !!"];
}
@end
