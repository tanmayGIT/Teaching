//
//  ViewController.h
//  TestDelegates
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SampleProtocol.h"
@interface ViewController : UIViewController<SampleProtocolDelegate> {

IBOutlet UILabel *showLabelValues;
}
@end

