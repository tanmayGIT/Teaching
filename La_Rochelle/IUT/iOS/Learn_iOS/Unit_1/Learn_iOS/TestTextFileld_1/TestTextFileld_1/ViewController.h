//
//  ViewController.h
//  TestTextFileld_1
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UITextFieldDelegate_LaRochelle.h"
@interface ViewController : UIViewController <UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UITextField *writeOnText;


@end

