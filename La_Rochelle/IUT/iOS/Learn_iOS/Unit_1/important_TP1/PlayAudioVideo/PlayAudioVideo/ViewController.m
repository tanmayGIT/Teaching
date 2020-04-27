//
//  ViewController.m
//  PlayAudioVideo
//
//  Created by Tanmoy on 15/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController (){
    NSURL *vedioURL;
}
@end

@implementation ViewController
@synthesize playerViewController;
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)playAudioButton:(id)sender {
    NSString *path = [[NSBundle mainBundle]
                      pathForResource:@"audioTest" ofType:@"mp3"];
    audioPlayer = [[AVAudioPlayer alloc]initWithContentsOfURL:
                   [NSURL fileURLWithPath:path] error:NULL];
    [audioPlayer play];
}

- (IBAction)playVedioButton:(id)sender {
    NSString *fullpath = [[self documentsDirectory] stringByAppendingPathComponent:@"yourdate.3gp"];
    vedioURL =[NSURL fileURLWithPath:fullpath];
    AVPlayerItem* playerItem = [AVPlayerItem playerItemWithURL:vedioURL];
    AVPlayer* playVideo = [[AVPlayer alloc] initWithPlayerItem:playerItem];
    playerViewController = [[AVPlayerViewController alloc] init];
    playerViewController.player = playVideo;
    playerViewController.player.volume = 0;
    playerViewController.view.frame = self.view.bounds;
    [self.view addSubview:playerViewController.view];
    [playVideo play];
}

-(NSString *)documentsDirectory{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    return documentsDirectory;
}
@end
