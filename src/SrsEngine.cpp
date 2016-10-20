#include <cmath>
#include <chrono>
#include <iostream>
#include "SrsEngine.h"

Flashcard SrsEngine::gradeFlashcard(Flashcard flashcard, unsigned int grade) {

    if (grade >= 3) {
        if (flashcard.getRepetition() == 0) {
            flashcard.setInterval(1);
            flashcard.setRepetition(1);
        }
        else if (flashcard.getRepetition() == 1) {
            flashcard.setInterval(6);
            flashcard.setRepetition(2);
        }
        else {
            float newInterval = ceil(flashcard.getInterval() * flashcard.getEasinessFactor());
            flashcard.setInterval(newInterval);

            flashcard.setRepetition(flashcard.getRepetition() + 1);
        }
    }
    else {
        flashcard.setRepetition(0);
        flashcard.setInterval(1);
    }

    float newEasinessFactor = flashcard.getEasinessFactor() + (0.1 - (5 - grade) * (0.08 + (5 - grade) * 0.02));

    if (newEasinessFactor < 1.3) {
        flashcard.setEasinessFactor(1.3);
    }
    else {
        flashcard.setEasinessFactor(newEasinessFactor);
    }

    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
    std::chrono::duration<int,std::ratio<60*60*24> > extraDays (flashcard.getInterval());

    //std::cout << "extraDays are: " << extraDays << std::endl;

    std::chrono::system_clock::time_point newNextDay = today + extraDays;

    flashcard.setNextDate(newNextDay);

    return flashcard;
}
