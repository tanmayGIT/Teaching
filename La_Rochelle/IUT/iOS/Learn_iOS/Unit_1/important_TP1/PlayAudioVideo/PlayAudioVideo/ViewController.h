//
//  ViewController.h
//  PlayAudioVideo
//
//  Created by Tanmoy on 15/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AVKit/AVKit.h>

@interface ViewController : UIViewController{
    AVAudioPlayer *audioPlayer;
    AVPlayer *moviePlayer;
}
@property (strong, nonatomic) AVPlayerViewController *playerViewController;
- (IBAction)playAudioButton:(id)sender;
- (IBAction)playVedioButton:(id)sender;

@end

