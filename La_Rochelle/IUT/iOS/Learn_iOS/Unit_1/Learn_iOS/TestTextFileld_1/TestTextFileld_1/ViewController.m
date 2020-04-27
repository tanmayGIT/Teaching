//
//  ViewController.m
//  TestTextFileld_1
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
- (void) addTextField;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self addTextField];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)addTextField {
    
    // This allocates a label
    UILabel *prefixLabel = [[UILabel alloc]initWithFrame:CGRectZero];
    
    //This sets the label text
    prefixLabel.text =@"## ";
    
    // This sets the font for the label
    [prefixLabel setFont:[UIFont boldSystemFontOfSize:14]];
    
    // This fits the frame to size of the text
    [prefixLabel sizeToFit];
    
    // This allocates the textfield and sets its frame
    UITextField *textField = [[UITextField  alloc] initWithFrame:
                              CGRectMake(20, 50, 280, 30)];
    
    // This sets the border style of the text field
    textField.borderStyle = UITextBorderStyleRoundedRect;
    textField.contentVerticalAlignment =
    UIControlContentVerticalAlignmentCenter;
    [textField setFont:[UIFont boldSystemFontOfSize:12]];
    
    //Placeholder text is displayed when no text is typed
    textField.placeholder = @"Simple Text field";
    
    //Prefix label is set as left view and the text starts after that
    textField.leftView = prefixLabel;
    
    //It set when the left prefixLabel to be displayed
    textField.leftViewMode = UITextFieldViewModeAlways;
    
    // Adds the textField to the view.
    [self.view addSubview:textField];
    
    // sets the delegate to the current class
    textField.delegate = self;
}
// pragma mark is used for easy access of code in Xcode
#pragma mark - TextField Delegates

// This method is called once we click inside the textField
-(void)textFieldDidBeginEditing:(UITextField *)textField {
    NSLog(@"Text field did begin editing");
}

// This method is called once we complete editing
-(void)textFieldDidEndEditing:(UITextField *)textField {
    NSLog(@"Text field ended editing");
}

// This method enables or disables the processing of return key
-(BOOL) textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}

- (void)viewDidUnload {
    _writeOnText = nil;
    [super viewDidUnload];
}
@end
