import Foundation

public class GradeableFlashcard: NSObject {
    @objc public var repetition = 0
    @objc public var interval: UInt = 0
    @objc public var easinessFactor = 2.5
    @objc public var previousDate = NSDate()
    @objc public var nextDate = NSDate()
}
