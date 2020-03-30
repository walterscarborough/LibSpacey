#include <iostream>

#include "flashcard.h"
#include "srsengine.h"

auto main() -> int {

    Flashcard newCard = Flashcard();

    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.setEasinessFactor(10);
    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.setInterval(3);
    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard.setRepetition(2);

    unsigned long long currentDate = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);

    SrsEngine engine = SrsEngine();
    // NOLINTNEXTLINE (readability-magic-numbers)
    newCard = engine.gradeFlashcard(newCard, 5, currentDate);

    std::cout << "interval is: " << newCard.getInterval() << std::endl;
    std::cout << "repCount is: " << newCard.getRepetition() << std::endl;
    std::cout << "easinessFactor is: " << newCard.getEasinessFactor() << std::endl;

    unsigned long long prevDate = newCard.getPreviousDate();
    unsigned long long nextDate = newCard.getNextDate();

    std::cout << "prevDate is: " << prevDate << std::endl;
    std::cout << "nextDate is: " << nextDate << std::endl;

    return 0;
}
