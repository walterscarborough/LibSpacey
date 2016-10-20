#include <cmath>
#include <chrono>
#include <iostream>
#include "SrsEngine.h"

Flashcard SrsEngine::gradeFlashcard(Flashcard flashcard, unsigned int grade) {

    if (grade < 3) {
        flashcard.setRepetitionCount(0);
        flashcard.setInterval(1);
    }
    else {
        float newEasinessFactor = flashcard.getEasinessFactor() + (0.1 - (5 - grade) * (0.08 + (5 - grade) * 0.02));

        if (newEasinessFactor < 1.3) {
            flashcard.setEasinessFactor(1.3);
        }
        else {
            flashcard.setEasinessFactor(newEasinessFactor);
        }

        flashcard.setRepetitionCount(flashcard.getRepetitionCount() + 1);

        switch(flashcard.getRepetitionCount()) {
            case 1:
                flashcard.setInterval(1);
                break;

            case 2:
                flashcard.setInterval(6);
                break;

            default:
                float newInterval = ceil((flashcard.getRepetitionCount() - 1) * flashcard.getEasinessFactor());
                flashcard.setInterval(newInterval);
                break;
        }
    }

    if (grade == 3) {
        flashcard.setInterval(0);
    }

    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
    std::chrono::duration<int,std::ratio<60*60*24> > extraDays (flashcard.getInterval());

    //std::cout << "extraDays are: " << extraDays << std::endl;

    std::chrono::system_clock::time_point newNextDay = today + extraDays;

    flashcard.setNextDate(newNextDay);

    return flashcard;
}
