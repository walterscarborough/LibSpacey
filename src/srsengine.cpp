#include <cmath>
#include <chrono>
#include <iostream>
#include "srsengine.h"

Flashcard SrsEngine::gradeFlashcard(Flashcard flashcard, unsigned int grade, unsigned long long currentDatetime) {

    if (grade < 3) {
        flashcard.setRepetition(0);
        flashcard.setInterval(0);
    }
    else {
        float newEasinessFactor = flashcard.getEasinessFactor() + (0.1 - (5 - grade) * (0.08 + (5 - grade) * 0.02));

        if (newEasinessFactor < 1.3) {
            flashcard.setEasinessFactor(1.3);
        }
        else {
            flashcard.setEasinessFactor(newEasinessFactor);
        }

        flashcard.setRepetition(flashcard.getRepetition() + 1);

        switch(flashcard.getRepetition()) {
            case 1:
                flashcard.setInterval(1);
                break;
            case 2:
                flashcard.setInterval(6);
                break;
            default:
                int newInterval = ceil((flashcard.getRepetition() - 1) * flashcard.getEasinessFactor());
                flashcard.setInterval(newInterval);
                break;
        }
    }

    if (grade == 3) {
        flashcard.setInterval(0);
    }

    unsigned int seconds = 60;
    unsigned int minutes = 60;
    unsigned int hours = 24;
    unsigned int dayMultiplier = seconds * minutes * hours;
    unsigned long long extraDays = dayMultiplier * flashcard.getInterval();

    unsigned long long newNextDatetime = currentDatetime + extraDays;

    flashcard.setPreviousDate(flashcard.getNextDate());
    flashcard.setNextDate(newNextDatetime);

    //std::cout << "extraDays are: " << extraDays << std::endl;
    return flashcard;
}
