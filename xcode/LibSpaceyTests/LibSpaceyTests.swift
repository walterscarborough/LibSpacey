//
//  LibSpaceyTests.swift
//  LibSpaceyTests
//
//  Created by Walter Scarborough on 2016/10/22.
//  Copyright © 2016年 Inanimate Studios. All rights reserved.
//

import XCTest
@testable import LibSpacey

class LibSpaceyTests: XCTestCase {

    var flashcardGrader: FlashcardGrader!
    var inputFlashcard: GradeableFlashcard!

    override func setUp() {
        self.flashcardGrader = FlashcardGrader()
        self.inputFlashcard = GradeableFlashcard()
    }

    func test_flashcardGrader_canGrade_flashcards() {

        if let outputCard = self.flashcardGrader.gradeFlashcard(0, gradeableFlashcard: self.inputFlashcard) {
            XCTAssertNotNil(outputCard)
        }
        else {
            XCTFail()
        }
    }
}
