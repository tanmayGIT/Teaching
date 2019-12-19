//
//  main.m
//  Jeton_Signe_Numerique
//
//  Created by Tanmoy on 09/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import <Foundation/Foundation.h>

#define  message_for(a, b)  \
NSLog(@#a " and " #b ": We love you!\n")

#define tokenpaster(n) NSLog (@"token" #n " = %d", token##n)


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        int token444 = 40;
        tokenpaster(444);

        
        message_for(Carole, Debra);
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
