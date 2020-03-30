#ifndef LIBSPACEY_FLASHCARD_H
#define LIBSPACEY_FLASHCARD_H

#include <chrono>

class Flashcard {

private:
    unsigned int repetition = 0;
    unsigned int interval = 1;
    // NOLINTNEXTLINE (readability-magic-numbers)
    float easinessFactor = 2.5;

    unsigned long long previousDate = static_cast<unsigned long long int>(
        std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1)
    );
    unsigned long long nextDate = static_cast<unsigned long long int>(
        std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1)
    );

public:
    Flashcard();

    auto getRepetition() -> unsigned int;
    void setRepetition(unsigned int repetition);

    auto getInterval() -> unsigned int;
    void setInterval(unsigned int interval);

    auto getEasinessFactor() -> float;
    void setEasinessFactor(float easinessFactor);

    auto getPreviousDate() -> unsigned long long;
    void setPreviousDate(unsigned long long previousDate);

    auto getNextDate() -> unsigned long long;
    void setNextDate(unsigned long long nextDate);
};

#endif
