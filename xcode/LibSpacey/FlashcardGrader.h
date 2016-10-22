#import <Foundation/Foundation.h>
@class GradeableFlashcard;

@interface FlashcardGrader : NSObject

- (GradeableFlashcard *) gradeFlashcard: (NSUInteger)grade gradeableFlashcard:(GradeableFlashcard *)gradeableFlashcard;

@end
