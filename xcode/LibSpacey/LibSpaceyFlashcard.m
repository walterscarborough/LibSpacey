#import "LibSpaceyFlashcard.h"
#import "flashcardDefaults.h"

@implementation LibSpaceyFlashcard

-(id)init {
     if (self = [super init])  {
         self.repetition = defaultRepetition;
         self.interval = defaultInterval;
         self.easinessFactor = defaultEasinessFactor;
         self.previousDate = NSDate.date;
         self.nextDate = NSDate.date;
     }
     return self;
}

@end
