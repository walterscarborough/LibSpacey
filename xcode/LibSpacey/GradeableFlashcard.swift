import Foundation

public class GradeableFlashcard: NSObject {
    public var repetition = 0
    public var interval: UInt = 0
    public var easinessFactor = 2.5
    public var previousDate = NSDate()
    public var nextDate = NSDate()
}
