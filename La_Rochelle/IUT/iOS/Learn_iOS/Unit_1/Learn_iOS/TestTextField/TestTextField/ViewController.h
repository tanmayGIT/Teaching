//
//  ViewController.h
//  TestTextField
//
//  Created by Tanmoy on 06/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController<UITextFieldDelegate>

@property (weak, nonatomic) IBOutlet UILabel *showMyLabel;
- (IBAction)clickOneTheButton:(id)sender;


@end

