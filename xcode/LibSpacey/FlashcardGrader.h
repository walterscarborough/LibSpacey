#import <Foundation/Foundation.h>
#import "LibSpaceyFlashcard.h"
#import "Grade.h"

@interface FlashcardGrader : NSObject

+ (LibSpaceyFlashcard *) gradeFlashcard:(LibSpaceyFlashcard *)libSpaceyFlashcard
                         grade: (Grade)grade
                         currentDateTime: (NSDate *)currentDateTime;

@end
