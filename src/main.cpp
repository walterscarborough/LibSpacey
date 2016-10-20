#include <iostream>

#include "Flashcard.h"
#include "SrsEngine.h"

int main() {

    std::string frontString = "this is the front";
    std::string backString = "and...this is the back";

    Flashcard newCard = Flashcard(frontString, backString);

    newCard.setEasinessFactor(10);
    newCard.setInterval(3);
    newCard.setRepetition(2);

    std::cout << newCard.getFront() << std::endl;

    SrsEngine engine = SrsEngine();

    newCard = engine.gradeFlashcard(newCard, 5);

    std::cout << "interval is: " << newCard.getInterval() << std::endl;
    std::cout << "repCount is: " << newCard.getRepetition() << std::endl;
    std::cout << "easinessFactor is: " << newCard.getEasinessFactor() << std::endl;

    time_t prevDate = std::chrono::system_clock::to_time_t(newCard.getPreviousDate());
    time_t nextDate = std::chrono::system_clock::to_time_t(newCard.getNextDate());


    std::cout << "prevDate is: " << ctime(&prevDate) << std::endl;
    std::cout << "nextDate is: " << ctime(&nextDate) << std::endl;

    return 0;
}
