//
//  GradeableFlashcard.m
//  LibSpacey
//
//  Created by Walter Scarborough on 2016/10/22.
//  Copyright © 2016年 Inanimate Studios. All rights reserved.
//

#import "GradeableFlashcard.h"

@implementation GradeableFlashcard

@synthesize repetition;
@synthesize interval;
@synthesize easinessFactor;
@synthesize previousDate;
@synthesize nextDate;


- (id)init {
    if (self = [super init])  {
        self.repetition = 0;
        self.interval = 0;
        self.easinessFactor = [NSNumber numberWithFloat:2.5];
        self.previousDate = [NSDate date];
        self.nextDate = [NSDate date];
    }
    return self;
}

@end
