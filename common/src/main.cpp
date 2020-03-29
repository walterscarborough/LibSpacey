#include <iostream>

#include "flashcard.h"
#include "srsengine.h"

int main() {

    std::string frontString = "this is the front";
    std::string backString = "and...this is the back";

    Flashcard newCard = Flashcard(frontString, backString);

    newCard.setEasinessFactor(10);
    newCard.setInterval(3);
    newCard.setRepetition(2);

    std::cout << newCard.getFront() << std::endl;

    unsigned long long currentDate = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);
    SrsEngine engine = SrsEngine();
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
