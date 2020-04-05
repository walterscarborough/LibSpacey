import XCTest
@testable import LibSpacey

class LibSpaceyTests: XCTestCase {

    func test_flashcardGrader_canGrade_flashcards() {
        let flashcard = LibSpaceyFlashcard()

        if let outputCard = FlashcardGraderWrapper.gradeFlashcard(
            flashcard,
            grade: Grade.Unknown,
            currentDateTime: Date()
        ) {
            XCTAssertNotNil(outputCard)
        }
        else {
            XCTFail()
        }
    }

    func test_flashcardGrader_grade0() {

        let october_24_2016 = 1477294292;
        let october_25_2016 = 1477380692;

        let flashcard = LibSpaceyFlashcard()
        flashcard.previousDate = Date(timeIntervalSince1970: TimeInterval(october_24_2016))
        flashcard.nextDate = Date(timeIntervalSince1970: TimeInterval(october_24_2016))

        let gradedFlashcard = FlashcardGraderWrapper.gradeFlashcard(
            flashcard,
            grade: Grade.Unknown,
            currentDateTime: Date(timeIntervalSince1970: TimeInterval(october_24_2016))
        )

        XCTAssertEqual(gradedFlashcard?.repetition, 0)
        XCTAssertEqual(gradedFlashcard?.interval, 1)
        XCTAssertEqual(gradedFlashcard?.easinessFactor, 1.7)
        XCTAssertEqual(gradedFlashcard?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
        XCTAssertEqual(gradedFlashcard?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_25_2016)))
    }

    func test_flashcardGrader_grade1() {

        let october_23_2016 = 1477207892;
        let october_24_2016 = 1477294292;

        let flashcard = LibSpaceyFlashcard()
        flashcard.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcard.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcard = FlashcardGraderWrapper.gradeFlashcard(
            flashcard,
            grade: Grade.VeryHard,
            currentDateTime: Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        )

        XCTAssertEqual(gradedFlashcard?.repetition, 0)
        XCTAssertEqual(gradedFlashcard?.interval, 1)
        XCTAssertEqual(gradedFlashcard?.easinessFactor, 1.96)
        XCTAssertEqual(gradedFlashcard?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcard?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
    }

    func test_flashcardGrader_grade2() {

        let october_24_2016 = 1477294292;
        let october_25_2016 = 1477380692;

        let flashcard = LibSpaceyFlashcard()
        flashcard.previousDate = Date(timeIntervalSince1970: TimeInterval(october_24_2016))
        flashcard.nextDate = Date(timeIntervalSince1970: TimeInterval(october_24_2016))

        let gradedFlashcard = FlashcardGraderWrapper.gradeFlashcard(
            flashcard,
            grade: Grade.Hard,
            currentDateTime: Date(timeIntervalSince1970: TimeInterval(october_24_2016))
        )

        XCTAssertEqual(gradedFlashcard?.repetition, 0)
        XCTAssertEqual(gradedFlashcard?.interval, 1)
        XCTAssertEqual(gradedFlashcard?.easinessFactor, 2.18)
        XCTAssertEqual(gradedFlashcard?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
        XCTAssertEqual(gradedFlashcard?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_25_2016)))
    }

    func test_flashcardGrader_grade3() {

        let october_23_2016 = 1477207892;
        let october_24_2016 = 1477294292;

        let flashcard = LibSpaceyFlashcard()
        flashcard.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcard.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcard = FlashcardGraderWrapper.gradeFlashcard(
            flashcard,
            grade: Grade.Medium,
            currentDateTime: Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        )

        XCTAssertEqual(gradedFlashcard?.repetition, 1)
        XCTAssertEqual(gradedFlashcard?.interval, 1)
        XCTAssertEqual(gradedFlashcard?.easinessFactor, 2.36)
        XCTAssertEqual(gradedFlashcard?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcard?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
    }

    func test_flashcardGrader_grade4() {

        let october_23_2016 = 1477207892;
        let october_24_2016 = 1477294292;

        let flashcard = LibSpaceyFlashcard()
        flashcard.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcard.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcard = FlashcardGraderWrapper.gradeFlashcard(
            flashcard,
            grade: Grade.Easy,
            currentDateTime: Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        )

        XCTAssertEqual(gradedFlashcard?.repetition, 1)
        XCTAssertEqual(gradedFlashcard?.interval, 1)
        XCTAssertEqual(gradedFlashcard?.easinessFactor, 2.5)
        XCTAssertEqual(gradedFlashcard?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcard?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
    }

    func test_flashcardGrader_grade5() {

        let october_23_2016 = 1477207892;
        let october_24_2016 = 1477294292;

        let flashcard = LibSpaceyFlashcard()
        flashcard.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcard.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcard = FlashcardGraderWrapper.gradeFlashcard(
            flashcard,
            grade: Grade.VeryEasy,
            currentDateTime: Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        )

        XCTAssertEqual(gradedFlashcard?.repetition, 1)
        XCTAssertEqual(gradedFlashcard?.interval, 1)
        XCTAssertEqual(gradedFlashcard?.easinessFactor, 2.6)
        XCTAssertEqual(gradedFlashcard?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcard?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_24_2016)))
    }

    func test_flashcardGrader_grade_long_repetition() {

        let october_23_2016 = 1477207892;
        let october_27_2016 = 1477553492;

        let flashcard = LibSpaceyFlashcard()
        flashcard.interval = 6
        flashcard.repetition = 6
        flashcard.previousDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        flashcard.nextDate = Date(timeIntervalSince1970: TimeInterval(october_23_2016))

        let gradedFlashcard = FlashcardGraderWrapper.gradeFlashcard(
            flashcard,
            grade: Grade.VeryEasy,
            currentDateTime: Date(timeIntervalSince1970: TimeInterval(october_23_2016))
        )

        XCTAssertEqual(gradedFlashcard?.repetition, 7)
        XCTAssertEqual(gradedFlashcard?.interval, 4)
        XCTAssertEqual(gradedFlashcard?.easinessFactor, 2.6)
        XCTAssertEqual(gradedFlashcard?.previousDate, Date(timeIntervalSince1970: TimeInterval(october_23_2016)))
        XCTAssertEqual(gradedFlashcard?.nextDate, Date(timeIntervalSince1970: TimeInterval(october_27_2016)))
    }
}
