//
//  ViewController.m
//  UISwitchTutorialTest
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *myTextField;
@property (weak, nonatomic) IBOutlet UISwitch *mySwitch;
- (IBAction)buttonClicked:(id)sender;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self.mySwitch addTarget:self
                      action:@selector(stateChanged:) forControlEvents:UIControlEventValueChanged];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)buttonClicked:(UIButton *)sender {
    if ([self.mySwitch isOn]) {
        self.myTextField.text = @"The Switch is Off";
        NSLog(@"Switch is on");
        [self.mySwitch setOn:NO animated:YES];
    } else {
        self.myTextField.text = @"The Switch is On";
        [self.mySwitch setOn:YES animated:YES];
    }
}

- (void)stateChanged:(UISwitch *)switchState
{
    if ([switchState isOn]) {
        self.myTextField.text = @"The Switch is On";
    } else {
        self.myTextField.text = @"The Switch is Off";
    }
}

@end
