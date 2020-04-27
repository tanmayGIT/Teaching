//
//  SampleProtocol_LaRochelle.m
//  Test_Delegates_1
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "SampleProtocol_LaRochelle.h"

@implementation SampleProtocol_LaRochelle
-(void) startSampleProcess{
    [NSTimer scheduledTimerWithTimeInterval:3.0 target:self.delegate
                                   selector:@selector(processCompleted) userInfo:nil repeats:NO];
}
@end
