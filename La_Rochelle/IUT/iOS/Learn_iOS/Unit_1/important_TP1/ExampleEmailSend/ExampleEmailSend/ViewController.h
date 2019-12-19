//
//  ViewController.h
//  ExampleEmailSend
//
//  Created by Tanmoy on 14/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

@interface ViewController : UIViewController<MFMailComposeViewControllerDelegate>{
   MFMailComposeViewController *mailComposer;
}
- (IBAction)clickSendEmail:(id)sender;

@end

