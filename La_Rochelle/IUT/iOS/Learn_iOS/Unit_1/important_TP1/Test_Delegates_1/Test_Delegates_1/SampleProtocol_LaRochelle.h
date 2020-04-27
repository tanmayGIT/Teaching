//
//  SampleProtocol_LaRochelle.h
//  Test_Delegates_1
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//
#import <Foundation/Foundation.h>

#ifndef SampleProtocol_LaRochelle_h
#define SampleProtocol_LaRochelle_h

@protocol SampleProtocol_LaRochelleDelegate <NSObject>  // definir le procotol
@required
-(void) processCompleted; // declarer un fonction
@end  // Definition de Protocol finir ici

@interface  SampleProtocol_LaRochelle : NSObject{
    // the "_delegate" varaible comply with the delegate
    id <SampleProtocol_LaRochelleDelegate> _delegate;
}

@property (nonatomic, strong) id delegate;

-(void)startSampleProcess; // Méthode d'instance
@end


#endif /* SampleProtocol_LaRochelle_h */
