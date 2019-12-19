//
//  main.m
//  Types
//
//  Created by EBook on 4/24/13.
//  Copyright (c) 2013 EBook. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        printf("char : %ld\n", sizeof(char));
        printf("short : %ld\n", sizeof(short));
        printf("int : %ld\n", sizeof(int));
        printf("long : %ld\n", sizeof(long));
        printf("long long : %ld\n", sizeof(long long));
        printf("void : %ld\n", sizeof(void));
        printf("void* : %ld\n", sizeof(void*));
        printf("BOOL : %ld\n", sizeof(BOOL));
        printf("\n");
        printf("float : %ld\n", sizeof(float));
        printf("double : %ld\n", sizeof(double));
        printf("long double : %ld\n", sizeof(long double));
        
        //true and false are defined, but in Obj - C, we
        //most often use YES and NO
        
        BOOL aBoolean = YES;
        printf("YES is %d, NO is %d\n", aBoolean, !aBoolean);
        
        //unsigned:
        char sChar = 0;
        unsigned char uChar = 0;
        printf("sChar - 1 = %d\nuChar - 1 = %d\n", --sChar, --uChar);
        
        char* charArray = "Hello, C String";
        printf("%s\n", charArray);
        printf("charArray[7] = %c\n", charArray[7]);
       
        //----------- Objects -------------
        printf("\n---------------\n");
        NSString *myString = @"Hello, World!";
        printf("%s", [myString UTF8String]);
        // Or...
        NSLog(@"%@", myString);
        
    }
    return 0;
}

