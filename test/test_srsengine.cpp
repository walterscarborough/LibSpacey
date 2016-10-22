#include <iostream>
#include <chrono>
#include "gtest/gtest.h"

#include "flashcard.h"
#include "srsengine.h"

TEST(srsengine, grade_0_response) {

    unsigned int grade = 0;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_24_2016 = october_23_2016 + oneDay;

    float expectedEasinessFactor = 2.5;

    Flashcard card = Flashcard();
    card.setPreviousDate(october_23_2016);
    card.setNextDate(october_23_2016);

    SrsEngine engine = SrsEngine();


    Flashcard gradedCard = engine.gradeFlashcard(card, grade, october_23_2016);

    std::cout << "easiness factor is: " << card.getEasinessFactor() << std::endl;

    EXPECT_EQ(gradedCard.getRepetition(), 0);
    EXPECT_EQ(gradedCard.getInterval(), 0);
    EXPECT_EQ(gradedCard.getEasinessFactor(), expectedEasinessFactor);
    EXPECT_EQ(gradedCard.getPreviousDate(), october_23_2016);
    EXPECT_EQ(gradedCard.getNextDate(), october_23_2016);
}
