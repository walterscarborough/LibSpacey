#include <iostream>
#include "gtest/gtest.h"

#include "Flashcard.cpp"

TEST(flashcard, front_getter_setter) {
    
    Flashcard card = Flashcard();
    card.setFront("I am a flashcard!");


    EXPECT_EQ(card.getFront(), "I am a flashcard.");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
