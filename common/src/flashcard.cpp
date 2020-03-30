#include <utility>
#include "flashcard.h"

Flashcard::Flashcard() = default;

auto Flashcard::getRepetition() -> unsigned int {
    return this->repetition;
}

void Flashcard::setRepetition(unsigned int repetition) {
    this->repetition = repetition;
}

auto Flashcard::getInterval() -> unsigned int {
    return this->interval;
}

void Flashcard::setInterval(unsigned int interval) {
    this->interval = interval;
}

auto Flashcard::getEasinessFactor() -> float {
    return this->easinessFactor;
}

void Flashcard::setEasinessFactor(float easinessFactor) {
    this->easinessFactor = easinessFactor;
}

auto Flashcard::getPreviousDate() -> unsigned long long {
    return this->previousDate;
}

void Flashcard::setPreviousDate(unsigned long long previousDate) {
    this->previousDate = previousDate;
}

auto Flashcard::getNextDate() -> unsigned long long {
    return this->nextDate;
}

void Flashcard::setNextDate(unsigned long long nextDate) {
    this->nextDate = nextDate;
}
