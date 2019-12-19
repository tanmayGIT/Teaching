//
//  ViewController.m
//  ExampleEmailSend
//
//  Created by Tanmoy on 14/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
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


- (IBAction)clickSendEmail:(id)sender {
    mailComposer = [[MFMailComposeViewController alloc]init];
    mailComposer.mailComposeDelegate = self;
    [mailComposer setSubject:@"Test mail"];
    [mailComposer setMessageBody:@"Testing message for the test mail" isHTML:NO];
     [self presentModalViewController:mailComposer animated:YES];
}
     
#pragma mark - mail compose delegate
     -(void)mailComposeController:(MFMailComposeViewController *)controller
             didFinishWithResult:(MFMailComposeResult)result error:(NSError *)error{
                 if (result) {
                     NSLog(@"Result : %d",result);
                 }
                 
                 if (error) {
                     NSLog(@"Error : %@",error);
                 }
                 
                 [self dismissModalViewControllerAnimated:YES];
}
     
@end
