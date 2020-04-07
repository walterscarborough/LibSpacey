package com.walterscarborough.libspacey

import java.util.*

class FlashcardGrader {

    companion object {

        fun gradeFlashcard(
            flashcard: Flashcard,
            grade: Grade,
            currentDate: Date
        ): Flashcard {

            val unixDateTime = (currentDate.time / 1000)
            val gradedFlashcard = gradeFlashcardWithLibSpacey(
                flashcard,
                grade.ordinal,
                unixDateTime
            )

            return gradedFlashcard
        }

        init {
            System.loadLibrary("native-lib")
        }

        private external fun gradeFlashcardWithLibSpacey(
            flashcard: Flashcard,
            grade: Int,
            currentDate: Long
        ): Flashcard
    }
}
