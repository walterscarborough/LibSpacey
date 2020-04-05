#include <iostream>

#include "flashcard.h"
#include "gradeFlashcard.h"

auto main() -> int {

    Flashcard newCard = Flashcard();

    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.easinessFactor = 10;
    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.interval = 3;
    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.repetition = 2;

    unsigned long long currentDate = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);

    // NOLINTNEXTLINE (readability-magic-numbers)
    auto gradedCard = gradeFlashcard(newCard, 5, currentDate);

    std::cout << "A interval is: " << newCard.interval << std::endl;
    std::cout << "A repCount is: " << newCard.repetition << std::endl;
    std::cout << "A easinessFactor is: " << newCard.easinessFactor << std::endl;
    std::cout << "A prevDate is: " << newCard.previousDate << std::endl;
    std::cout << "A nextDate is: " << newCard.nextDate << std::endl;
    std::cout << "\n";
    std::cout << "B interval is: " << gradedCard.interval << std::endl;
    std::cout << "B repCount is: " << gradedCard.repetition << std::endl;
    std::cout << "B easinessFactor is: " << gradedCard.easinessFactor << std::endl;
    std::cout << "B prevDate is: " << gradedCard.previousDate << std::endl;
    std::cout << "B nextDate is: " << gradedCard.nextDate << std::endl;

    return 0;
}
