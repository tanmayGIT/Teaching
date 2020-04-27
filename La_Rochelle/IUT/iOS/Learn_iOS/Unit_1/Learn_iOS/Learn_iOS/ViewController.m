//
//  ViewController.m
//  Learn_iOS
//
//  Created by Tanmoy on 04/11/17.
//  Copyright © 2017 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

-(IBAction)pressMe:(id)sender{
    self.showHello.text = @"Bonjour, comment tu vas!!";
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
