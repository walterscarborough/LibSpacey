//
//  FlashcardService.h
//  LibSpacey
//
//  Created by Walter Scarborough on 2016/10/22.
//  Copyright © 2016年 Inanimate Studios. All rights reserved.
//

#import <Foundation/Foundation.h>
@class GradeableFlashcard;

@interface FlashcardGrader : NSObject

- (GradeableFlashcard *) gradeFlashcard: (NSUInteger)grade gradeableFlashcard:(GradeableFlashcard *)gradeableFlashcard;

@end
