//
//  ViewController.m
//  Test_Delegates_1
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
    SampleProtocol_LaRochelle *sampleProtocol_Paris = [[SampleProtocol_LaRochelle alloc]init];
    sampleProtocol_Paris.delegate = self;
    [_connectToTheLabel setText:@"Processing My Dear, Please wait ..."];
    [sampleProtocol_Paris startSampleProcess];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
#pragma mark - Sample Protocol LaRochelle Delegate
-(void)processCompleted{
    [_connectToTheLabel setText:@"Yaaa Huuuu; Process is Completed Now"];
}

@end
