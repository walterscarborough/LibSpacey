#import "FlashcardGraderWrapper.h"
#import "flashcard.h"
#import "flashcardGrader.h"

@interface FlashcardGraderWrapper()

+ (Flashcard) convertGradeableFlashcardToRegularFlashcard: (LibSpaceyFlashcard *)libSpaceyFlashcard;

+ (LibSpaceyFlashcard *) convertRegularFlashcardToGradeableFlashcard: (Flashcard)regularFlashcard;

@end

@implementation FlashcardGraderWrapper

+ (LibSpaceyFlashcard *) gradeFlashcard:(LibSpaceyFlashcard *)libSpaceyFlashcard
                         grade: (Grade)grade
                         currentDateTime: (NSDate *)currentDateTime
{
    Flashcard flashcard = [self convertGradeableFlashcardToRegularFlashcard:libSpaceyFlashcard];

    unsigned long long convertedCurrentDateTime = currentDateTime.timeIntervalSince1970;

    Flashcard outputFlashcard = FlashcardGrader::gradeFlashcard(flashcard, grade, convertedCurrentDateTime);

    LibSpaceyFlashcard *finishedFlashcard = [self convertRegularFlashcardToGradeableFlashcard:outputFlashcard];

    return finishedFlashcard;
}

+ (Flashcard)convertGradeableFlashcardToRegularFlashcard: (LibSpaceyFlashcard *)libSpaceyFlashcard {

    Flashcard regularFlashcard = Flashcard();
    regularFlashcard.repetition = (unsigned int)libSpaceyFlashcard.repetition;
    regularFlashcard.interval = (unsigned int)libSpaceyFlashcard.interval;
    regularFlashcard.easinessFactor = libSpaceyFlashcard.easinessFactor;

    regularFlashcard.previousDate = libSpaceyFlashcard.previousDate.timeIntervalSince1970;
    regularFlashcard.nextDate = libSpaceyFlashcard.nextDate.timeIntervalSince1970;

    return regularFlashcard;
}

+ (LibSpaceyFlashcard *) convertRegularFlashcardToGradeableFlashcard: (Flashcard)regularFlashcard {

    LibSpaceyFlashcard *libSpaceyFlashcard = [[LibSpaceyFlashcard alloc] init];
    libSpaceyFlashcard.repetition = regularFlashcard.repetition;
    libSpaceyFlashcard.interval = regularFlashcard.interval;
    libSpaceyFlashcard.easinessFactor = regularFlashcard.easinessFactor;
    libSpaceyFlashcard.previousDate = [NSDate dateWithTimeIntervalSince1970:regularFlashcard.previousDate];
    libSpaceyFlashcard.nextDate = [NSDate dateWithTimeIntervalSince1970:regularFlashcard.nextDate];

    return libSpaceyFlashcard;
}

@end
