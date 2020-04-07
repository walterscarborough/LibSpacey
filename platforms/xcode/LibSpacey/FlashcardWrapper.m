#import "FlashcardWrapper.h"
#import "flashcardDefaults.h"

@implementation FlashcardWrapper

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
