#include <iostream>

#include "flashcard.h"
#include "flashcardGrader.h"

auto main() -> int {

    Flashcard newCard = Flashcard();

    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.easinessFactor = 2.6;
    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.interval = 3;
    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.repetition = 2;

    unsigned long long currentDate = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);

    // NOLINTNEXTLINE (readability-magic-numbers)
    auto gradedCard = FlashcardGrader::gradeFlashcard(newCard, 5, currentDate);

    std::cout << "Original flashcard interval is: " << newCard.interval << std::endl;
    std::cout << "Original flashcard repCount is: " << newCard.repetition << std::endl;
    std::cout << "Original flashcard easinessFactor is: " << newCard.easinessFactor << std::endl;
    std::cout << "Original flashcard prevDate is: " << newCard.previousDate << std::endl;
    std::cout << "Original flashcard nextDate is: " << newCard.nextDate << std::endl;
    std::cout << "\n";
    std::cout << "Graded flashcard interval is: " << gradedCard.interval << std::endl;
    std::cout << "Graded flashcard repCount is: " << gradedCard.repetition << std::endl;
    std::cout << "Graded flashcard easinessFactor is: " << gradedCard.easinessFactor << std::endl;
    std::cout << "Graded flashcard prevDate is: " << gradedCard.previousDate << std::endl;
    std::cout << "Graded flashcard nextDate is: " << gradedCard.nextDate << std::endl;

    return 0;
}
