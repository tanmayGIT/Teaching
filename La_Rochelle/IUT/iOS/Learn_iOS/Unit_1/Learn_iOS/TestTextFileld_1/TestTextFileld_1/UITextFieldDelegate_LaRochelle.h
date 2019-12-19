//
//  UITextFieldDelegate_LaRochelle.h
//  TestTextFileld_1
//
//  Created by Tanmoy on 08/01/18.
//  Copyright © 2018 Tanmoy. All rights reserved.
//

#ifndef UITextFieldDelegate_LaRochelle_h
#define UITextFieldDelegate_LaRochelle_h

@protocol MakingParisDelegate<NSObject> // definir le protocol
    @required
    -(void) processCompleted; //declarer un fonction
@end // Definition de protocol finir ici

@interface UITextFieldDelegate_LaRochelle : NSObject{
    // Delegate pour répondre
    id <MakingParisDelegate> _delegate;
}
@property (nonatomic, strong) id delegate;
-(void) startSampleProcess;
@end


#endif /* UITextFieldDelegate_LaRochelle_h */
