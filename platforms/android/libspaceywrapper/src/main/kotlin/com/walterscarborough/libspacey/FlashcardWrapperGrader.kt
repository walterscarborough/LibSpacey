package com.walterscarborough.libspacey

import java.util.*

class FlashcardWrapperGrader {

    companion object {

        fun gradeFlashcardWrapper(
            flashcardWrapper: FlashcardWrapper,
            grade: Grade,
            currentDate: Date
        ): FlashcardWrapper {

            val unixDateTime = (currentDate.time / 1000)

            return gradeFlashcardWithLibSpacey(
                flashcardWrapper,
                grade.ordinal,
                unixDateTime
            )
        }

        init {
            System.loadLibrary("native-lib")
        }

        private external fun gradeFlashcardWithLibSpacey(
            flashcardWrapper: FlashcardWrapper,
            grade: Int,
            currentDate: Long
        ): FlashcardWrapper
    }
}
