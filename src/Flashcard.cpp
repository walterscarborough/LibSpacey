#include "Flashcard.h"

Flashcard::Flashcard(void) {

}

Flashcard::Flashcard(std::string front, std::string back) {
    this->setFront(front);
    this->setBack(back);
}

std::string Flashcard::getFront() {
    return this->front;
}

void Flashcard::setFront(std::string front) {
    this->front = front;
}

std::string Flashcard::getBack() {
    return this->back;
}

void Flashcard::setBack(std::string back) {
    this->back = back;
}

unsigned int Flashcard::getRepetitionCount(){
    return this->repetitionCount;
}

void Flashcard::setRepetitionCount(unsigned int repetitionCount){
    this->repetitionCount = repetitionCount;
}

unsigned int Flashcard::getInterval() {
    return this->interval;
}

void Flashcard::setInterval(unsigned int interval){
    this->interval = interval;
}

float Flashcard::getEasinessFactor(){
    return this->easinessFactor;
}

void Flashcard::setEasinessFactor(float easinessFactor){
    this->easinessFactor = easinessFactor;
}

std::chrono::system_clock::time_point Flashcard::getPreviousDate(){
    return this->previousDate;
}

void Flashcard::setPreviousDate(std::chrono::system_clock::time_point previousDate){
    this->previousDate = previousDate;
}

std::chrono::system_clock::time_point Flashcard::getNextDate(){
    return this->nextDate;
}

void Flashcard::setNextDate(std::chrono::system_clock::time_point nextDate){
    this->nextDate = nextDate;
}
