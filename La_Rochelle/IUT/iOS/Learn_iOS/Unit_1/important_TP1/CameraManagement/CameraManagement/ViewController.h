//
//  ViewController.h
//  CameraManagement
//
//  Created by Tanmoy on 14/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController<UIImagePickerControllerDelegate>{
    UIImagePickerController *imagePicker;

    IBOutlet UIImageView *imageView;
}

- (IBAction)getCamera:(id)sender;

@end

