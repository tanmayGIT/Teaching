//
//  ViewController.h
//  Test_FirstApplication_1
//
//  Created by Tanmoy on 07/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
- (IBAction)clickOnButton:(id)sender;
@property (weak, nonatomic) IBOutlet UILabel *showMyLabels;
@property (weak, nonatomic) IBOutlet UIButton *buttonPropertyChange;


@end

