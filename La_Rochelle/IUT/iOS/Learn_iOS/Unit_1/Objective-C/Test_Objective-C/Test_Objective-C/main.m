//
//  main.m
//  Test_Objective-C
//
//  Created by Tanmoy on 11/12/17.
//  Copyright © 2017 Tanmoy. All rights reserved.
//

//#import <Foundation/Foundation.h>
//
//@interface SampleClass:NSObject
//- (NSNumber *)multiplyA: (NSNumber *)a withB:(NSNumber *)b;
//@end
//
//@implementation SampleClass
//
//-(NSNumber *)multiplyA:(NSNumber *)a withB:(NSNumber *)b
//{
//    float number1 = [a floatValue]; // converting a into float value
//    float number2 = [b floatValue]; // converting b into float value
//    float product = number1 * number2;
//    NSNumber *result = [NSNumber numberWithFloat:product];
//    return result;
//}
//@end


//int main(int argc, const char * argv[]) {
//    @autoreleasepool {
//        
//        SampleClass *sampleClass = [[SampleClass alloc]init];
//        NSNumber *a = [NSNumber numberWithFloat:10.5]; // name the object then the function name and parameter
//        NSNumber *b = [NSNumber numberWithFloat:10.0];
//        NSNumber *result = [sampleClass multiplyA:a withB:b]; // name the object, function name:param1 joining statement:param2
//        NSString *resultString = [result stringValue]; // converting NSNumber into NSString
//        
//        
//        NSString *str1 = @"Bonjour";
//        NSString *str2 = @"Salut ça va";
//        NSString *str3;
//        NSString *str4;
//        
//        
//        NSNumber *number = [NSNumber numberWithDouble:10.89555];
//        NSLog(@"%f",[number floatValue]); // To convert from NSNumber into float value
//        NSLog(@"%f",[number doubleValue]); // To convert from NSNulber into double value
//        
//        NSNumber *numberInt = [NSNumber numberWithInteger:8955];
//        NSLog(@"%d",[numberInt intValue]); // To convert from NSNumber into integer value
//        
//        
//        /* total length of str3 after concatenation */
//        NSUInteger len = [str2 integerValue];
//        NSLog(@"Length of Str2 :  %lu", (unsigned long)len );
//        
//        /* Converting into Upper Case String */
//        str3 = [str2 uppercaseString];
//        NSLog(@"The Uppercase String is :  %@",str3);
//        
//        /* Converting into Lower Case String */
//        str4 = [str1 lowercaseString];
//        NSLog(@"The Lowercase String is :  %@",str4);
//        
//        
//      //  NSInteger getInt = [ inttegerValue];
//        NSLog(@"\n The Product is %@",resultString);
//        
//        
//        NSString *otherString = @"TestString";
//        
//        unichar myVal = [otherString characterAtIndex:5];
//        NSLog(@"The char is :  %hu",myVal);
//        
//        
//        NSString *myString = @"some text:  ";
//        myString = [myString stringByAppendingFormat:@" à quelle heure, Tu vas aller pour badminton = %d", 3];
//        NSLog(@"%@",myString);
//        
//    }
//    return 0;
//}
