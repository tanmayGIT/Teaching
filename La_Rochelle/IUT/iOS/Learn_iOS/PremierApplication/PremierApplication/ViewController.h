//
//  ViewController.h
//  PremierApplication
//
//  Created by Tanmoy on 09/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

- (IBAction)myButtonWork:(id)sender;
@property (weak, nonatomic) IBOutlet UILabel *showMyLabel;

@property (weak, nonatomic) IBOutlet UIButton *changeButton;

@end

