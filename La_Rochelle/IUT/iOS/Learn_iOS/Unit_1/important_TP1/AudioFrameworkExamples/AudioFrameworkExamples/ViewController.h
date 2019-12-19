//
//  ViewController.h
//  AudioFrameworkExamples
//
//  Created by Tanmoy on 15/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface ViewController : UIViewController <AVAudioRecorderDelegate, AVAudioPlayerDelegate>

@property (weak, nonatomic) IBOutlet UIButton *recordButton;
@property (weak, nonatomic) IBOutlet UIButton *stopButton;
@property (weak, nonatomic) IBOutlet UIButton *playButton;

- (IBAction)recordButtonTapped:(id)sender;
- (IBAction)stopButtonTapped:(id)sender;

- (IBAction)playButtonTapped:(id)sender;

@end

