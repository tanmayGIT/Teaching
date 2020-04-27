//
//  ViewController.h
//  Test_iOS_App_1
//
//  Created by Tanmoy on 06/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (weak, nonatomic) IBOutlet UILabel *myButtonClickedLabel;
- (IBAction)clickOnButton:(id)sender;
@end

