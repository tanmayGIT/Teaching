//
//  ViewController.m
//  ExampleToolBar
//
//  Created by Tanmoy on 15/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    UINavigationBar* navbar = [[UINavigationBar alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 50)];
    
    UINavigationItem* navItem = [[UINavigationItem alloc] initWithTitle:@"Tanmoy"];
    // [navbar setBarTintColor:[UIColor lightGrayColor]];
    UIBarButtonItem* cancelBtn = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(onTapCancel:)];
    navItem.leftBarButtonItem = cancelBtn;
    
    UIBarButtonItem* doneBtn = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(onTapDone:)];
    navItem.rightBarButtonItem = doneBtn;
    
    [navbar setItems:@[navItem]];
    [self.view addSubview:navbar];
}

-(void)onTapDone:(UIBarButtonItem*)item{
    
}

-(void)onTapCancel:(UIBarButtonItem*)item{
    
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
