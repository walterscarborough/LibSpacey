#ifndef LIBSPACEY_FLASHCARD_H
#define LIBSPACEY_FLASHCARD_H

#include <chrono>

struct Flashcard {
    Flashcard() {
        repetition = 0;
        interval = 1;

        // NOLINTNEXTLINE (readability-magic-numbers)
        easinessFactor = 2.5;

        previousDate = static_cast<unsigned long long int>(
                std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1)
        );
        nextDate = static_cast<unsigned long long int>(
                std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1)
        );
    }

    unsigned int repetition;
    unsigned int interval;
    float easinessFactor;

    unsigned long long previousDate;
    unsigned long long nextDate;
};

#endif
