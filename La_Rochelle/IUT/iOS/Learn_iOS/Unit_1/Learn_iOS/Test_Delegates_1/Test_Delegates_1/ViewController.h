//
//  ViewController.h
//  Test_Delegates_1
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SampleProtocol_LaRochelle.h"
@interface ViewController : UIViewController<SampleProtocol_LaRochelleDelegate>
@property (weak, nonatomic) IBOutlet UILabel *connectToTheLabel;


@end

