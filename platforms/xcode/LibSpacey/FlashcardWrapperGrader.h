#import <Foundation/Foundation.h>
#import "FlashcardWrapper.h"
#import "Grade.h"

@interface FlashcardWrapperGrader : NSObject

+ (FlashcardWrapper *)gradeFlashcardWrapper:(FlashcardWrapper *)flashcardWrapper
                                      grade:(Grade)grade
                                currentDate: (NSDate *)currentDate;

@end
