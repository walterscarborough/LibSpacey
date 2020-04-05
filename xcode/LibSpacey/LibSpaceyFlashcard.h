#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LibSpaceyFlashcard : NSObject

@property(nonatomic) unsigned int repetition;
@property(nonatomic) unsigned int interval;
@property(nonatomic) float easinessFactor;
@property(nonatomic) NSDate* previousDate;
@property(nonatomic) NSDate* nextDate;

@end

NS_ASSUME_NONNULL_END
