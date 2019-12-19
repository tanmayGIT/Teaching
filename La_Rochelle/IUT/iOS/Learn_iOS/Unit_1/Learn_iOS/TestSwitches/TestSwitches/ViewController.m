//
//  ViewController.m
//  TestSwitches
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
    [self addSwitch];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)addSwitch {
    _usethisSwitch = [[UISwitch alloc] init];
    [self.view addSubview:_usethisSwitch];
    _usethisSwitch.center = CGPointMake(400, 200);
    [_usethisSwitch addTarget:self action:@selector(switched:)
       forControlEvents:UIControlEventValueChanged];
}
-(IBAction)switched:(id)sender {
    NSLog(@"Switch current state %@", _usethisSwitch.on ? @"On" : @"Off");
}
@end
