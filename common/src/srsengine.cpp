#include <cmath>
#include <chrono>
#include <iostream>
#include <cmath>
#include "srsengine.h"

Flashcard SrsEngine::gradeFlashcard(
    Flashcard flashcard,
    unsigned int grade,
    unsigned long long currentDatetime
) {

    if (grade >= 3) {
        switch (flashcard.getRepetition()) {
            case 0:
                flashcard.setInterval(1);
                flashcard.setRepetition(1);
                break;
            case 1:
                flashcard.setInterval(6);
                flashcard.setRepetition(2);
                break;
            default:
                auto newInterval = static_cast<unsigned int>(
                    std::round(
                        flashcard.getInterval() - 1 * flashcard.getEasinessFactor()
                    )
                );
                flashcard.setInterval(newInterval);
                flashcard.setRepetition(flashcard.getRepetition() + 1);
                break;
        }
    } else {
        flashcard.setInterval(1);
        flashcard.setRepetition(0);
    }

    auto newEasinessFactor = static_cast<float>(
        flashcard.getEasinessFactor()
        + (0.1 - (5 - grade) * (0.08 + (5 - grade) * 0.02))
    );

    if (newEasinessFactor < 1.3) {
        flashcard.setEasinessFactor(1.3);
    } else {
        flashcard.setEasinessFactor(newEasinessFactor);
    }

    unsigned int seconds = 60;
    unsigned int minutes = 60;
    unsigned int hours = 24;
    unsigned int dayMultiplier = seconds * minutes * hours;
    unsigned long long extraDays = dayMultiplier * flashcard.getInterval();

    unsigned long long newNextDatetime = currentDatetime + extraDays;

    flashcard.setPreviousDate(flashcard.getNextDate());
    flashcard.setNextDate(newNextDatetime);

    return flashcard;
}
