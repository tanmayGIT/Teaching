//
//  ViewController.m
//  Learn_iOS_TextField
//
//  Created by Tanmoy on 01/12/17.
//  Copyright © 2017 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}


- (IBAction)btnAction:(id)sender {
    _myLabel.text =[NSString stringWithFormat: @"Tumi Jano Nah"];
}

- (IBAction)alsoClick:(id)sender {
    _myLabel.text =[NSString stringWithFormat: @"Naki Bojho Nah"];
}
@end
