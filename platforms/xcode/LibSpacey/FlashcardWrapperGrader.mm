#import "FlashcardWrapperGrader.h"
#import "flashcard.h"
#import "flashcardGrader.h"

@interface FlashcardWrapperGrader()

+ (Flashcard)convertFlashcardWrapperToFlashcard: (FlashcardWrapper *)flashcardWrapper;

+ (FlashcardWrapper *)convertFlashcardToFlashcardWrapper: (Flashcard)flashcard;

@end

@implementation FlashcardWrapperGrader

+ (FlashcardWrapper *)gradeFlashcardWrapper:(FlashcardWrapper *)flashcardWrapper
                                      grade:(Grade)grade
                                currentDate: (NSDate *)currentDate
{
    Flashcard flashcard = [self convertFlashcardWrapperToFlashcard:flashcardWrapper];

    unsigned long long convertedCurrentDateTime = currentDate.timeIntervalSince1970;

    Flashcard gradedFlashcard = FlashcardGrader::gradeFlashcard(flashcard, grade, convertedCurrentDateTime);

    FlashcardWrapper *gradedFlashcardWrapper = [self convertFlashcardToFlashcardWrapper:gradedFlashcard];

    return gradedFlashcardWrapper;
}

+ (Flashcard)convertFlashcardWrapperToFlashcard: (FlashcardWrapper *)flashcardWrapper {

    Flashcard flashcard = Flashcard();
    flashcard.repetition = (unsigned int)flashcardWrapper.repetition;
    flashcard.interval = (unsigned int)flashcardWrapper.interval;
    flashcard.easinessFactor = flashcardWrapper.easinessFactor;

    flashcard.previousDate = flashcardWrapper.previousDate.timeIntervalSince1970;
    flashcard.nextDate = flashcardWrapper.nextDate.timeIntervalSince1970;

    return flashcard;
}

+ (FlashcardWrapper *)convertFlashcardToFlashcardWrapper: (Flashcard)flashcard {

    FlashcardWrapper *flashcardWrapper = [[FlashcardWrapper alloc] init];
    flashcardWrapper.repetition = flashcard.repetition;
    flashcardWrapper.interval = flashcard.interval;
    flashcardWrapper.easinessFactor = flashcard.easinessFactor;
    flashcardWrapper.previousDate = [NSDate dateWithTimeIntervalSince1970:flashcard.previousDate];
    flashcardWrapper.nextDate = [NSDate dateWithTimeIntervalSince1970:flashcard.nextDate];

    return flashcardWrapper;
}

@end
