#include <iostream>
#include <chrono>
#include "gtest/gtest.h"

#include "flashcard.h"
#include "gradeFlashcard.h"

TEST(gradeFlashcard, grade_0_response) {

    unsigned int grade = 0;
    unsigned long long october_24_2016 = 1477294292;
    unsigned long long october_25_2016 = 1477380692;

    float expectedEasinessFactor = 1.7;

    Flashcard card = Flashcard();
    card.previousDate = october_24_2016;
    card.nextDate = october_24_2016;


    Flashcard gradedCard = gradeFlashcard(card, grade, october_24_2016);


    EXPECT_EQ(gradedCard.repetition, 0);
    EXPECT_EQ(gradedCard.interval, 1);
    EXPECT_EQ(gradedCard.easinessFactor, expectedEasinessFactor);
    EXPECT_EQ(gradedCard.previousDate, october_24_2016);
    EXPECT_EQ(gradedCard.nextDate, october_25_2016);
}

TEST(gradeFlashcard, grade_1_response) {

    unsigned int grade = 1;
    unsigned long long october_23_2016 = 1477207892;
    unsigned long long october_24_2016 = 1477294292;

    float expectedEasinessFactor = 1.96;

    Flashcard card = Flashcard();
    card.previousDate = october_23_2016;
    card.nextDate = october_23_2016;


    Flashcard gradedCard = gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.repetition, 0);
    EXPECT_EQ(gradedCard.interval, 1);
    EXPECT_EQ(gradedCard.easinessFactor, expectedEasinessFactor);
    EXPECT_EQ(gradedCard.previousDate, october_23_2016);
    EXPECT_EQ(gradedCard.nextDate, october_24_2016);
}

TEST(gradeFlashcard, grade_2_response) {

    unsigned int grade = 2;
    unsigned long long october_24_2016 = 1477294292;
    unsigned long long october_25_2016 = 1477380692;

    float expectedEasinessFactor = 2.18;

    Flashcard card = Flashcard();
    card.previousDate = october_24_2016;
    card.nextDate = october_24_2016;


    Flashcard gradedCard = gradeFlashcard(card, grade, october_24_2016);


    EXPECT_EQ(gradedCard.repetition, 0);
    EXPECT_EQ(gradedCard.interval, 1);
    EXPECT_EQ(gradedCard.easinessFactor, expectedEasinessFactor);
    EXPECT_EQ(gradedCard.previousDate, october_24_2016);
    EXPECT_EQ(gradedCard.nextDate, october_25_2016);
}

TEST(gradeFlashcard, grade_3_response) {

    unsigned int grade = 3;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_24_2016 = october_23_2016 + oneDay;

    float expectedEasinessFactor = 2.36;

    Flashcard card = Flashcard();
    card.previousDate = october_23_2016;
    card.nextDate = october_23_2016;


    Flashcard gradedCard = gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.repetition, 1);
    EXPECT_EQ(gradedCard.interval, 1);
    EXPECT_EQ(gradedCard.easinessFactor, expectedEasinessFactor);
    EXPECT_EQ(gradedCard.previousDate, october_23_2016);
    EXPECT_EQ(gradedCard.nextDate, october_24_2016);
}

TEST(gradeFlashcard, grade_4_response) {

    unsigned int grade = 4;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_24_2016 = october_23_2016 + oneDay;

    float expectedEasinessFactor = 2.5;

    Flashcard card = Flashcard();
    card.previousDate = october_23_2016;
    card.nextDate = october_23_2016;


    Flashcard gradedCard = gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.repetition, 1);
    EXPECT_EQ(gradedCard.interval, 1);
    EXPECT_EQ(gradedCard.easinessFactor, expectedEasinessFactor);
    EXPECT_EQ(gradedCard.previousDate, october_23_2016);
    EXPECT_EQ(gradedCard.nextDate, october_24_2016);
}

TEST(gradeFlashcard, grade_5_response) {

    unsigned int grade = 5;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_24_2016 = october_23_2016 + oneDay;

    float expectedEasinessFactor = 2.6;

    Flashcard card = Flashcard();
    card.previousDate = october_23_2016;
    card.nextDate = october_23_2016;


    Flashcard gradedCard = gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.repetition, 1);
    EXPECT_EQ(gradedCard.interval, 1);
    EXPECT_EQ(gradedCard.easinessFactor, expectedEasinessFactor);
    EXPECT_EQ(gradedCard.previousDate, october_23_2016);
    EXPECT_EQ(gradedCard.nextDate, october_24_2016);
}

TEST(gradeFlashcard, long_repetition_grade_5_response) {

    unsigned int grade = 5;
    unsigned long long october_23_2016 = 1477207892;

    unsigned int oneDay = 86400;
    unsigned long long october_27_2016 = october_23_2016 + (oneDay * 4);

    float expectedEasinessFactor = 2.6;

    Flashcard card = Flashcard();
    card.interval = 6;
    card.repetition = 6;
    card.previousDate = october_23_2016;
    card.nextDate = october_23_2016;


    Flashcard gradedCard = gradeFlashcard(card, grade, october_23_2016);


    EXPECT_EQ(gradedCard.repetition, 7);
    EXPECT_EQ(gradedCard.interval, 4);
    EXPECT_EQ(gradedCard.easinessFactor, expectedEasinessFactor);
    EXPECT_EQ(gradedCard.previousDate, october_23_2016);
    EXPECT_EQ(gradedCard.nextDate, october_27_2016);
}
