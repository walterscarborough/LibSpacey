#ifndef LIBSPACEY_FLASHCARD_H
#define LIBSPACEY_FLASHCARD_H

#include <string>
#include <chrono>

class Flashcard {

private:
    std::string front;
    std::string back;
    unsigned int repetition = 0;
    unsigned int interval = 0;
    float easinessFactor = 2.5;

    unsigned long long previousDate = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);
    unsigned long long nextDate = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);

public:
    Flashcard();
    Flashcard(std::string front, std::string back);

    std::string getFront();
    void setFront(std::string front);

    std::string getBack();
    void setBack(std::string back);

    unsigned int getRepetition();
    void setRepetition(unsigned int repetition);

    unsigned int getInterval();
    void setInterval(unsigned int interval);

    float getEasinessFactor();
    void setEasinessFactor(float easinessFactor);

    unsigned long long getPreviousDate();
    void setPreviousDate(unsigned long long previousDate);

    unsigned long long getNextDate();
    void setNextDate(unsigned long long nextDate);
};


#endif //LIBSPACEY_FLASHCARD_H
