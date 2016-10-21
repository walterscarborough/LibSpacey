#include <iostream>
#include <chrono>
#include "gtest/gtest.h"

#include "flashcard.h"
#include "srsengine.h"

TEST(srsengine, weak_interval_and_repetition_response) {
    
    Flashcard card = Flashcard();
    card.setFront("I am a flashcard.");


    EXPECT_EQ(1, 2);
}
