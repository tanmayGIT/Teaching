//
//  main.m
//  Learn_Obj-C
//
//  Created by Tanmoy on 03/12/17.
//  Copyright © 2017 Tanmoy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SampleClass:NSObject
- (void)sampleMethod;
@end

@implementation SampleClass

- (void)sampleMethod{
    NSLog(@"Hello, World! \n");
}

@end

int main()
{
    /* my first program in Objective-C */
    SampleClass *sampleClass = [[SampleClass alloc]init];
    [sampleClass sampleMethod];
    return 0;
}
