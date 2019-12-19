//
//  ViewController.m
//  TestVariousButtons
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    //The custom method to create our different types of button is called
    [self addDifferentTypesOfButton];
    // [self addLabel];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(void)addLabel {
    UILabel *aLabel = [[UILabel alloc]initWithFrame:
                       CGRectMake(20, 200, 280, 80)];
    aLabel.numberOfLines = 0;
    aLabel.textColor = [UIColor blueColor];
    aLabel.backgroundColor = [UIColor clearColor];
    aLabel.textAlignment = UITextAlignmentCenter;
    aLabel.text = @"This is a sample text\n of multiple lines. Here number of lines is not limited.";
    [self.view addSubview:aLabel];
}

-(void)addDifferentTypesOfButton {
  
    
    
    
    // A rounded Rect button created by using class method
    UIButton *roundRectButton = [UIButton buttonWithType:
                                 UIButtonTypeRoundedRect];
    [roundRectButton setFrame:CGRectMake(60, 50, 200, 40)];
    [roundRectButton setBackgroundColor: [UIColor blueColor]];
    roundRectButton.layer.cornerRadius = 10;
    // sets title for the button
    [roundRectButton setTitle:@"Rounded Rect Button" forState:
     UIControlStateNormal];
    [self.view addSubview:roundRectButton];
  
    
    

    UIButton *customButton = [UIButton buttonWithType: UIButtonTypeCustom];
    [customButton setBackgroundColor: [UIColor lightGrayColor]];
    [customButton setTitleColor:[UIColor blackColor] forState:
     UIControlStateHighlighted];
    
    //sets background image for normal state
    [customButton setBackgroundImage:[UIImage imageNamed:
                                      @"button_images.jpeg"]
                            forState:UIControlStateNormal];
    
    //sets background image for highlighted state
    [customButton setBackgroundImage:[UIImage imageNamed:
                                      @"images.jpeg"]
                            forState:UIControlStateHighlighted];
    [customButton setFrame:CGRectMake(60, 100, 200, 40)];
    [customButton setTitle:@"Custom Button" forState:UIControlStateNormal];
    [self.view addSubview:customButton];
    
    
    
    
    
    UIButton *detailDisclosureButton = [UIButton buttonWithType:
                                        UIButtonTypeDetailDisclosure];
    [detailDisclosureButton setFrame:CGRectMake(60, 150, 200, 40)];
    [detailDisclosureButton setTitle:@"Detail disclosure" forState:
     UIControlStateNormal];
    [self.view addSubview:detailDisclosureButton];
 
    
    
    
    
    UIButton *contactButton = [UIButton buttonWithType:
                               UIButtonTypeContactAdd];
    [contactButton setFrame:CGRectMake(60, 200, 200, 40)];
    [self.view addSubview:contactButton];
    
 
    
    
    
    UIButton *infoDarkButton = [UIButton buttonWithType:
                                UIButtonTypeInfoDark];
    [infoDarkButton setFrame:CGRectMake(60, 250, 200, 40)];
    [self.view addSubview:infoDarkButton];
    
   
    
    
    
    UIButton *infoLightButton = [UIButton buttonWithType:
                                 UIButtonTypeInfoLight];
    [infoLightButton setFrame:CGRectMake(60, 300, 200, 40)];
    [self.view addSubview:infoLightButton];
}
@end
