#include <iostream>
#include <chrono>
#include "gtest/gtest.h"

#include "flashcard.cpp"

TEST(flashcard, front_getter_setter) {
    
    Flashcard card = Flashcard();
    card.setFront("I am a flashcard.");


    EXPECT_EQ(card.getFront(), "I am a flashcard.");
}

TEST(flashcard, back_getter_setter) {
    
    Flashcard card = Flashcard();
    card.setBack("I am a reversed flashcard!");


    EXPECT_EQ(card.getBack(), "I am a reversed flashcard!");
}

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
    
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();

    Flashcard card = Flashcard();
    card.setPreviousDate(today);


    EXPECT_EQ(card.getPreviousDate(), today);
}

TEST(flashcard, nextDate_getter_setter) {
    
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();

    Flashcard card = Flashcard();
    card.setNextDate(today);


    EXPECT_EQ(card.getNextDate(), today);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
