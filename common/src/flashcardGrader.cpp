#include <cmath>
#include "flashcardGrader.h"

auto FlashcardGrader::gradeFlashcard(
        Flashcard flashcard,
        unsigned int grade,
        unsigned long long currentDatetime
) -> Flashcard {

    if (grade >= 3) {
        switch (flashcard.repetition) {
            case 0:
                flashcard.interval = 1;
                flashcard.repetition = 1;
                break;
            case 1:
                // NOLINTNEXTLINE (readability-magic-numbers)
                flashcard.interval = 6;
                flashcard.repetition = 2;
                break;
            default:
                auto newInterval = static_cast<unsigned int>(
                        std::round(
                                static_cast<float>(flashcard.interval) - 1 * flashcard.easinessFactor
                        )
                );
                flashcard.interval = newInterval;
                flashcard.repetition = (flashcard.repetition + 1);
                break;
        }
    } else {
        flashcard.interval = 1;
        flashcard.repetition = 0;
    }

    const auto newEasinessFactor = static_cast<float>(
            flashcard.easinessFactor
            + (0.1 - (5 - grade) * (0.08 + (5 - grade) * 0.02))
    );

    // NOLINTNEXTLINE (readability-magic-numbers)
    if (newEasinessFactor < 1.3) {
        // NOLINTNEXTLINE (readability-magic-numbers)
        flashcard.easinessFactor = 1.3;
    } else {
        flashcard.easinessFactor = newEasinessFactor;
    }

    const unsigned int seconds = 60;
    const unsigned int minutes = 60;
    const unsigned int hours = 24;
    const unsigned int dayMultiplier = seconds * minutes * hours;
    const unsigned long long extraDays = dayMultiplier * flashcard.interval;

    const unsigned long long newNextDatetime = currentDatetime + extraDays;

    flashcard.previousDate = flashcard.nextDate;
    flashcard.nextDate = newNextDatetime;

    return flashcard;
}
