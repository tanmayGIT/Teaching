//
//  ViewController.h
//  Learn_iOS_TextField
//
//  Created by Tanmoy on 01/12/17.
//  Copyright © 2017 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (weak, nonatomic) IBOutlet UILabel *myLabel;
@property (weak, nonatomic) IBOutlet UITextField *myTextbox;

- (IBAction)btnAction:(id)sender;
- (IBAction)alsoClick:(id)sender;

@end

