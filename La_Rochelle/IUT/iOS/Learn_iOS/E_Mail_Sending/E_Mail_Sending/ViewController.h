//
//  ViewController.h
//  E_Mail_Sending
//
//  Created by Tanmoy on 09/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
@interface ViewController : UIViewController<MFMailComposeViewControllerDelegate> {
    MFMailComposeViewController *mailComposer;
  - (IBAction)sendEmail:(id)sender;  
}

@end

