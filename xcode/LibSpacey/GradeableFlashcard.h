//
//  GradeableFlashcard.h
//  LibSpacey
//
//  Created by Walter Scarborough on 2016/10/22.
//  Copyright © 2016年 Inanimate Studios. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GradeableFlashcard : NSObject

@property (nonatomic) NSUInteger repetition;
@property (nonatomic) NSUInteger interval;
@property (nonatomic) NSNumber *easinessFactor;
@property (nonatomic) NSDate *previousDate;
@property (nonatomic) NSDate *nextDate;

@end
