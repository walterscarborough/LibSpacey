//
//  FlashcardService.m
//  LibSpacey
//
//  Created by Walter Scarborough on 2016/10/22.
//  Copyright © 2016年 Inanimate Studios. All rights reserved.
//

#import "FlashcardGrader.h"
#import "GradeableFlashcard.h"
#import "flashcard.h"
#import "srsengine.h"

@interface FlashcardGrader()

- (Flashcard)convertGradeableFlashcardToRegularFlashcard: (GradeableFlashcard *)gradeableFlashcard;

- (GradeableFlashcard *) convertRegularFlashcardToGradeableFlashcard: (Flashcard)regularFlashcard;

@end

@implementation FlashcardGrader

- (GradeableFlashcard *) gradeFlashcard: (NSUInteger)grade gradeableFlashcard:(GradeableFlashcard *)gradeableFlashcard {


    Flashcard flashcard = [self convertGradeableFlashcardToRegularFlashcard:gradeableFlashcard];

    NSTimeInterval currentDatetime = [[NSDate date] timeIntervalSince1970];

    SrsEngine srsengine = SrsEngine();
    Flashcard outputFlashcard = srsengine.gradeFlashcard(flashcard, (unsigned int)grade, currentDatetime);

    GradeableFlashcard *finishedFlashcard = [self convertRegularFlashcardToGradeableFlashcard:outputFlashcard];


    return finishedFlashcard;
}

- (Flashcard)convertGradeableFlashcardToRegularFlashcard: (GradeableFlashcard *)gradeableFlashcard {

    Flashcard regularFlashcard = Flashcard();
    regularFlashcard.setRepetition((unsigned int)gradeableFlashcard.repetition);
    regularFlashcard.setInterval((unsigned int)gradeableFlashcard.interval);
    regularFlashcard.setEasinessFactor(gradeableFlashcard.easinessFactor.floatValue);
    
    regularFlashcard.setPreviousDate(gradeableFlashcard.previousDate.timeIntervalSince1970);
    regularFlashcard.setNextDate(gradeableFlashcard.nextDate.timeIntervalSince1970);

    return regularFlashcard;
}

- (GradeableFlashcard *) convertRegularFlashcardToGradeableFlashcard: (Flashcard)regularFlashcard {

    GradeableFlashcard *gradeableFlashcard = [[GradeableFlashcard alloc] init];
    gradeableFlashcard.repetition = regularFlashcard.getRepetition();
    gradeableFlashcard.interval = regularFlashcard.getInterval();
    gradeableFlashcard.easinessFactor = [NSNumber numberWithFloat:regularFlashcard.getEasinessFactor()];
    gradeableFlashcard.previousDate = [NSDate dateWithTimeIntervalSince1970:regularFlashcard.getPreviousDate()];
    gradeableFlashcard.nextDate = [NSDate dateWithTimeIntervalSince1970:regularFlashcard.getNextDate()];

    return gradeableFlashcard;
}

@end
