#include <iostream>
#include <chrono>
#include "gtest/gtest.h"

#include "flashcard.h"
#include "flashcardGrader.h"

TEST(flashcard, defaults) {
    auto flashcard = Flashcard();

    EXPECT_EQ(flashcard.repetition, 0);
    EXPECT_EQ(flashcard.interval, 1);
    EXPECT_EQ(flashcard.easinessFactor, 2.5);
    EXPECT_GT(flashcard.previousDate, 0);
    EXPECT_GT(flashcard.nextDate, 0);
}

TEST(flashcard, changing_flashcard_property_does_not_change_defaults) {

    auto flashcard = Flashcard();
    flashcard.repetition = 10;
    flashcard.interval = 11;
    flashcard.easinessFactor = 12;
    flashcard.previousDate = 0;
    flashcard.nextDate = 0;

    EXPECT_EQ(flashcard.repetition, 10);
    EXPECT_EQ(flashcard.interval, 11);
    EXPECT_EQ(flashcard.easinessFactor, 12);
    EXPECT_EQ(flashcard.previousDate, 0);
    EXPECT_EQ(flashcard.nextDate, 0);

    auto newFlashcard = Flashcard();

    EXPECT_EQ(newFlashcard.repetition, 0);
    EXPECT_EQ(newFlashcard.interval, 1);
    EXPECT_EQ(newFlashcard.easinessFactor, 2.5);
    EXPECT_GT(newFlashcard.previousDate, 0);
    EXPECT_GT(newFlashcard.nextDate, 0);

    EXPECT_EQ(flashcard.repetition, 10);
    EXPECT_EQ(flashcard.interval, 11);
    EXPECT_EQ(flashcard.easinessFactor, 12);
    EXPECT_EQ(flashcard.previousDate, 0);
    EXPECT_EQ(flashcard.nextDate, 0);
}
