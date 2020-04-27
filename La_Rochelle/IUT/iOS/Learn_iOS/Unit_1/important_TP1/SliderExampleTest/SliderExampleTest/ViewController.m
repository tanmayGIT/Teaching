//
//  ViewController.m
//  SliderExampleTest
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *showInTheLabel;

@property (weak, nonatomic) IBOutlet UISlider *makeMySlider;
- (IBAction)sliderValueChanged:(id)sender;

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



- (IBAction)sliderValueChanged:(id)sender {
    // Set the label text to the value of the slider as it changes
    self.showInTheLabel.text = [NSString stringWithFormat:@"%f", self.makeMySlider.value];
}
@end
