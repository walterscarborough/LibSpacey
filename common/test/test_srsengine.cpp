#include <iostream>
#include <chrono>
#include "gtest/gtest.h"

#include "flashcard.h"
#include "srsengine.h"

TEST(srsengine, grade_0_response) {

    unsigned int grade = 0;
    unsigned long long october_24_2016 = 1477294292;
    unsigned long long october_25_2016 = 1477380692;

    float expectedEasinessFactor = 1.7;

    Flashcard card = Flashcard();
    card.setPreviousDate(october_24_2016);
    card.setNextDate(october_24_2016);

    SrsEngine engine = SrsEngine();


    Flashcard gradedCard = engine.gradeFlashcard(card, grade, october_24_2016);


    EXPECT_EQ(gradedCard.getRepetition(), 0);
    EXPECT_EQ(gradedCard.getInterval(), 1);
    EXPECT_EQ(gradedCard.getEasinessFactor(), expectedEasinessFactor);
    EXPECT_EQ(gradedCard.getPreviousDate(), october_24_2016);
    EXPECT_EQ(gradedCard.getNextDate(), october_25_2016);
}

TEST(srsengine, grade_1_response) {

    unsigned int grade = 1;
    unsigned long long october_23_2016 = 1477207892;
    unsigned long long october_24_2016 = 1477294292;

    float expectedEasinessFactor = 1.96;

    Flashcard card = Flashcard();
    card.setPreviousDate(october_23_2016);
    card.setNextDate(october_23_2016);

    SrsEngine engine = SrsEngine();


    Flashcard gradedCard = engine.gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.getRepetition(), 0);
    EXPECT_EQ(gradedCard.getInterval(), 1);
    EXPECT_EQ(gradedCard.getEasinessFactor(), expectedEasinessFactor);
    EXPECT_EQ(gradedCard.getPreviousDate(), october_23_2016);
    EXPECT_EQ(gradedCard.getNextDate(), october_24_2016);
}

TEST(srsengine, grade_2_response) {

    unsigned int grade = 2;
    unsigned long long october_24_2016 = 1477294292;
    unsigned long long october_25_2016 = 1477380692;

    float expectedEasinessFactor = 2.18;

    Flashcard card = Flashcard();
    card.setPreviousDate(october_24_2016);
    card.setNextDate(october_24_2016);

    SrsEngine engine = SrsEngine();


    Flashcard gradedCard = engine.gradeFlashcard(card, grade, october_24_2016);


    EXPECT_EQ(gradedCard.getRepetition(), 0);
    EXPECT_EQ(gradedCard.getInterval(), 1);
    EXPECT_EQ(gradedCard.getEasinessFactor(), expectedEasinessFactor);
    EXPECT_EQ(gradedCard.getPreviousDate(), october_24_2016);
    EXPECT_EQ(gradedCard.getNextDate(), october_25_2016);
}

TEST(srsengine, grade_3_response) {

    unsigned int grade = 3;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_24_2016 = october_23_2016 + oneDay;

    float expectedEasinessFactor = 2.36;

    Flashcard card = Flashcard();
    card.setPreviousDate(october_23_2016);
    card.setNextDate(october_23_2016);

    SrsEngine engine = SrsEngine();


    Flashcard gradedCard = engine.gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.getRepetition(), 1);
    EXPECT_EQ(gradedCard.getInterval(), 1);
    EXPECT_EQ(gradedCard.getEasinessFactor(), expectedEasinessFactor);
    EXPECT_EQ(gradedCard.getPreviousDate(), october_23_2016);
    EXPECT_EQ(gradedCard.getNextDate(), october_24_2016);
}

TEST(srsengine, grade_4_response) {

    unsigned int grade = 4;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_24_2016 = october_23_2016 + oneDay;

    float expectedEasinessFactor = 2.5;

    Flashcard card = Flashcard();
    card.setPreviousDate(october_23_2016);
    card.setNextDate(october_23_2016);

    SrsEngine engine = SrsEngine();


    Flashcard gradedCard = engine.gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.getRepetition(), 1);
    EXPECT_EQ(gradedCard.getInterval(), 1);
    EXPECT_EQ(gradedCard.getEasinessFactor(), expectedEasinessFactor);
    EXPECT_EQ(gradedCard.getPreviousDate(), october_23_2016);
    EXPECT_EQ(gradedCard.getNextDate(), october_24_2016);
}

TEST(srsengine, grade_5_response) {

    unsigned int grade = 5;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_24_2016 = october_23_2016 + oneDay;

    float expectedEasinessFactor = 2.6;

    Flashcard card = Flashcard();
    card.setPreviousDate(october_23_2016);
    card.setNextDate(october_23_2016);

    SrsEngine engine = SrsEngine();


    Flashcard gradedCard = engine.gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.getRepetition(), 1);
    EXPECT_EQ(gradedCard.getInterval(), 1);
    EXPECT_EQ(gradedCard.getEasinessFactor(), expectedEasinessFactor);
    EXPECT_EQ(gradedCard.getPreviousDate(), october_23_2016);
    EXPECT_EQ(gradedCard.getNextDate(), october_24_2016);
}

TEST(srsengine, long_repetition_grade_5_response) {

    unsigned int grade = 5;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_27_2016 = october_23_2016 + (oneDay * 4);

    float expectedEasinessFactor = 2.6;

    Flashcard card = Flashcard();
    card.setInterval(6);
    card.setRepetition(6);
    card.setPreviousDate(october_23_2016);
    card.setNextDate(october_23_2016);

    SrsEngine engine = SrsEngine();


    Flashcard gradedCard = engine.gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.getRepetition(), 7);
    EXPECT_EQ(gradedCard.getInterval(), 4);
    EXPECT_EQ(gradedCard.getEasinessFactor(), expectedEasinessFactor);
    EXPECT_EQ(gradedCard.getPreviousDate(), october_23_2016);
    EXPECT_EQ(gradedCard.getNextDate(), october_27_2016);
}
