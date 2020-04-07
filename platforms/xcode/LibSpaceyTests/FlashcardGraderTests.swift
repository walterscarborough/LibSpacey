import XCTest
@testable import LibSpacey

class LibSpaceyTests: XCTestCase {

    func test_flashcardGrader_canGrade_flashcards() {
        let flashcardWrapper = FlashcardWrapper()

        if let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(flashcardWrapper, grade: Grade.Unknown, currentDate: Date()) {
            XCTAssertNotNil(gradedFlashcardWrapper)
        }
        else {
            XCTFail()
        }
    }

    func test_flashcardGrader_grade0() {

        let october_24_2016 = 1477294292;
        let october_25_2016 = 1477380692;

        let flashcardWrapper = FlashcardWrapper()
        flashcardWrapper.previousDate = Date(timeIntervalSince1970: TimeInterval(october_24_2016))
        flashcardWrapper.nextDate = Date(timeIntervalSince1970: TimeInterval(october_24_2016))

        let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(flashcardWrapper, grade: Grade.Unknown, currentDate: Date(timeIntervalSince1970: TimeInterval(october_24_2016)))

        XCTAssertEqual(gradedFlashcardWrapper?.repetition, 0)
        XCTAssertEqual(gradedFlashcardWrapper?.interval, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.easinessFactor, 1.7)
        XCTAssertEqual(gradedFlashcardWrapper?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
        XCTAssertEqual(gradedFlashcardWrapper?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_25_2016)))
    }

    func test_flashcardGrader_grade1() {

        let october_23_2016 = 1477207892;
        let october_24_2016 = 1477294292;

        let flashcardWrapper = FlashcardWrapper()
        flashcardWrapper.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcardWrapper.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(flashcardWrapper, grade: Grade.VeryHard, currentDate: Date(timeIntervalSince1970: TimeInterval(october_23_2016)))

        XCTAssertEqual(gradedFlashcardWrapper?.repetition, 0)
        XCTAssertEqual(gradedFlashcardWrapper?.interval, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.easinessFactor, 1.96)
        XCTAssertEqual(gradedFlashcardWrapper?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcardWrapper?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
    }

    func test_flashcardGrader_grade2() {

        let october_24_2016 = 1477294292;
        let october_25_2016 = 1477380692;

        let flashcardWrapper = FlashcardWrapper()
        flashcardWrapper.previousDate = Date(timeIntervalSince1970: TimeInterval(october_24_2016))
        flashcardWrapper.nextDate = Date(timeIntervalSince1970: TimeInterval(october_24_2016))

        let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(flashcardWrapper, grade: Grade.Hard, currentDate: Date(timeIntervalSince1970: TimeInterval(october_24_2016)))

        XCTAssertEqual(gradedFlashcardWrapper?.repetition, 0)
        XCTAssertEqual(gradedFlashcardWrapper?.interval, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.easinessFactor, 2.18)
        XCTAssertEqual(gradedFlashcardWrapper?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
        XCTAssertEqual(gradedFlashcardWrapper?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_25_2016)))
    }

    func test_flashcardGrader_grade3() {

        let october_23_2016 = 1477207892;
        let october_24_2016 = 1477294292;

        let flashcardWrapper = FlashcardWrapper()
        flashcardWrapper.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcardWrapper.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(flashcardWrapper, grade: Grade.Medium, currentDate: Date(timeIntervalSince1970: TimeInterval(october_23_2016)))

        XCTAssertEqual(gradedFlashcardWrapper?.repetition, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.interval, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.easinessFactor, 2.36)
        XCTAssertEqual(gradedFlashcardWrapper?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcardWrapper?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
    }

    func test_flashcardGrader_grade4() {

        let october_23_2016 = 1477207892;
        let october_24_2016 = 1477294292;

        let flashcardWrapper = FlashcardWrapper()
        flashcardWrapper.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcardWrapper.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(flashcardWrapper, grade: Grade.Easy, currentDate: Date(timeIntervalSince1970: TimeInterval(october_23_2016)))

        XCTAssertEqual(gradedFlashcardWrapper?.repetition, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.interval, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.easinessFactor, 2.5)
        XCTAssertEqual(gradedFlashcardWrapper?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcardWrapper?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
    }

    func test_flashcardGrader_grade5() {

        let october_23_2016 = 1477207892;
        let october_24_2016 = 1477294292;

        let flashcardWrapper = FlashcardWrapper()
        flashcardWrapper.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcardWrapper.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(flashcardWrapper, grade: Grade.VeryEasy, currentDate: Date(timeIntervalSince1970: TimeInterval(october_23_2016)))

        XCTAssertEqual(gradedFlashcardWrapper?.repetition, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.interval, 1)
        XCTAssertEqual(gradedFlashcardWrapper?.easinessFactor, 2.6)
        XCTAssertEqual(gradedFlashcardWrapper?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcardWrapper?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
    }

    func test_flashcardGrader_grade_long_repetition() {

        let october_23_2016 = 1477207892;
        let october_27_2016 = 1477553492;

        let flashcardWrapper = FlashcardWrapper()
        flashcardWrapper.interval = 6
        flashcardWrapper.repetition = 6
        flashcardWrapper.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcardWrapper.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(flashcardWrapper, grade: Grade.VeryEasy, currentDate: Date(timeIntervalSince1970: TimeInterval(october_23_2016)))

        XCTAssertEqual(gradedFlashcardWrapper?.repetition, 7)
        XCTAssertEqual(gradedFlashcardWrapper?.interval, 4)
        XCTAssertEqual(gradedFlashcardWrapper?.easinessFactor, 2.6)
        XCTAssertEqual(gradedFlashcardWrapper?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcardWrapper?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_27_2016)))
    }
}
