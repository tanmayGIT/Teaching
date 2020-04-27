//
//  ViewController.m
//  AddTextView
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
    [self addTextView];
    // Do any additional setup after loading the view, typically from a nib.
}
-(void)addTextView {

    [_showTextView setText:@"Lorem ipsum dolor sit er elit lamet, consectetaur cillium adipisicing pecu, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitationullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure."];
     _showTextView.delegate = self;
     [self.view addSubview:_showTextView];
}

#pragma mark - Text View delegates
     
     -(BOOL)textView:(UITextView *)textView shouldChangeTextInRange:
     (NSRange)range replacementText:(NSString *)text {
         
         if ([text isEqualToString:@"\n"]) {
             [textView resignFirstResponder];
         }
         return YES;
     }
     
     -(void)textViewDidBeginEditing:(UITextView *)textView {
         NSLog(@"Did begin editing");
     }
     
     -(void)textViewDidChange:(UITextView *)textView {
         NSLog(@"Did Change");
     }
     
     -(void)textViewDidEndEditing:(UITextView *)textView {
         NSLog(@"Did End editing");
         
     }
     
     -(BOOL)textViewShouldEndEditing:(UITextView *)textView {
         [textView resignFirstResponder];
         return YES;
     }
     
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
