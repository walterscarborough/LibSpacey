#include <cmath>
#include <chrono>
#include <iostream>
#include <cmath>
#include "srsengine.h"

SrsEngine::SrsEngine() = default;

auto SrsEngine::gradeFlashcard(
    Flashcard &flashcard,
    unsigned int grade,
    unsigned long long currentDatetime
) -> Flashcard& {

    // NOLINTNEXTLINE (readability-magic-numbers)
    if (grade >= 3) {
        switch (flashcard.getRepetition()) {
            case 0:
                flashcard.setInterval(1);
                flashcard.setRepetition(1);
                break;
            case 1:
                // NOLINTNEXTLINE (readability-magic-numbers)
                flashcard.setInterval(6);
                flashcard.setRepetition(2);
                break;
            default:
                auto newInterval = static_cast<unsigned int>(
                        std::round(
                                static_cast<float>(flashcard.getInterval()) - 1 * flashcard.getEasinessFactor()
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

    const auto newEasinessFactor = static_cast<float>(
            flashcard.getEasinessFactor()
            + (0.1 - (5 - grade) * (0.08 + (5 - grade) * 0.02))
    );

    // NOLINTNEXTLINE (readability-magic-numbers)
    if (newEasinessFactor < 1.3) {
        // NOLINTNEXTLINE (readability-magic-numbers)
        flashcard.setEasinessFactor(1.3);
    } else {
        flashcard.setEasinessFactor(newEasinessFactor);
    }

    const unsigned int seconds = 60;
    const unsigned int minutes = 60;
    const unsigned int hours = 24;
    const unsigned int dayMultiplier = seconds * minutes * hours;
    const unsigned long long extraDays = dayMultiplier * flashcard.getInterval();

    const unsigned long long newNextDatetime = currentDatetime + extraDays;

    flashcard.setPreviousDate(flashcard.getNextDate());
    flashcard.setNextDate(newNextDatetime);

    return flashcard;
}
