#include <iostream>
#include <chrono>
#include "gtest/gtest.h"

#include "flashcard.h"

TEST(flashcard, repetition_getter_setter) {

    Flashcard card = Flashcard();
    card.setRepetition(5);


    EXPECT_EQ(card.getRepetition(), 5);
}

TEST(flashcard, interval_getter_setter) {

    Flashcard card = Flashcard();
    card.setInterval(4);


    EXPECT_EQ(card.getInterval(), 4);
}

TEST(flashcard, easinessFactor_getter_setter) {

    float easinessFactor = 3.52;

    Flashcard card = Flashcard();
    card.setEasinessFactor(easinessFactor);


    EXPECT_EQ(card.getEasinessFactor(), easinessFactor);
}

TEST(flashcard, previousDate_getter_setter) {

    unsigned long long october_23_2016 = 1477207892;

    Flashcard card = Flashcard();
    card.setPreviousDate(october_23_2016);


    EXPECT_EQ(card.getPreviousDate(), october_23_2016);
}

TEST(flashcard, nextDate_getter_setter) {

    unsigned long long october_23_2016 = 1477207892;

    Flashcard card = Flashcard();
    card.setNextDate(october_23_2016);


    EXPECT_EQ(card.getNextDate(), october_23_2016);
}
