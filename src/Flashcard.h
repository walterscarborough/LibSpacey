#ifndef LIBSPACEY_FLASHCARD_H
#define LIBSPACEY_FLASHCARD_H

#include <string>
#include <chrono>

class Flashcard {

private:
    std::string front;
    std::string back;
    unsigned int repetitionCount = 0;
    unsigned int interval = 0;
    float easinessFactor = 2.5;
    std::chrono::system_clock::time_point previousDate = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point nextDate = std::chrono::system_clock::now();

public:
    Flashcard();
    Flashcard(std::string front, std::string back);

    std::string getFront();
    void setFront(std::string front);

    std::string getBack();
    void setBack(std::string back);

    unsigned int getRepetitionCount();
    void setRepetitionCount(unsigned int repetitionCount);

    unsigned int getInterval();
    void setInterval(unsigned int interval);

    float getEasinessFactor();
    void setEasinessFactor(float easinessFactor);

    std::chrono::system_clock::time_point getPreviousDate();
    void setPreviousDate(std::chrono::system_clock::time_point previousDate);

    std::chrono::system_clock::time_point getNextDate();
    void setNextDate(std::chrono::system_clock::time_point nextDate);
};


#endif //LIBSPACEY_FLASHCARD_H
