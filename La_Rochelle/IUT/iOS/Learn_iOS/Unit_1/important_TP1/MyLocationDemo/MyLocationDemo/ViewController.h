//
//  ViewController.h
//  MyLocationDemo
//
//  Created by Tanmoy on 15/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface ViewController : UIViewController <CLLocationManagerDelegate>

@property (weak, nonatomic) IBOutlet UILabel *showLatValue;
@property (weak, nonatomic) IBOutlet UILabel *showLongValue;
@property (weak, nonatomic) IBOutlet UILabel *typeAddressHere;

- (IBAction)clickOnButton:(id)sender;
@end

