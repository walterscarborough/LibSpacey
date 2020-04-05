#import <Foundation/Foundation.h>
#import "LibSpaceyFlashcard.h"
#import "Grade.h"

@interface FlashcardGraderWrapper : NSObject

+ (LibSpaceyFlashcard *) gradeFlashcard:(LibSpaceyFlashcard *)libSpaceyFlashcard
                         grade: (Grade)grade
                         currentDateTime: (NSDate *)currentDateTime;

@end
