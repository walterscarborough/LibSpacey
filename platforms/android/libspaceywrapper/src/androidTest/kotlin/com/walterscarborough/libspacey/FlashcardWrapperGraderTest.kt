package com.walterscarborough.libspacey

import androidx.test.ext.junit.runners.AndroidJUnit4
import junit.framework.Assert.assertEquals
import org.junit.Test
import org.junit.runner.RunWith
import java.time.Instant
import java.util.*

@RunWith(AndroidJUnit4::class)
class FlashcardWrapperGraderTest {
    @Test
    fun should_gradeFlashcard_withGrade0() {

        val october_24_2016: Long = 1477294292
        val october_25_2016: Long = 1477380692

        val flashcardWrapper = FlashcardWrapper(
            previousDate = october_24_2016,
            nextDate = october_24_2016
        )

        val currentDate = Date.from(Instant.ofEpochSecond(october_24_2016))
        val actualGradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(
            flashcardWrapper = flashcardWrapper,
            grade = Grade.Unknown,
            currentDate = currentDate
        )

        val expectedGradedFlashcardWrapper = FlashcardWrapper(
            repetition = 0,
            interval = 1,
            easinessFactor = 1.7F,
            previousDate = october_24_2016,
            nextDate = october_25_2016
        )

        assertEquals(actualGradedFlashcardWrapper, expectedGradedFlashcardWrapper)
    }
}
