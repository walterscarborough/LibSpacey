#ifndef LIBSPACEY_SRSENGINE_H
#define LIBSPACEY_SRSENGINE_H


#include "flashcard.h"

class SrsEngine {

public:
    Flashcard gradeFlashcard(Flashcard flashcard, unsigned int grade, unsigned long long currentDatetime);
};


#endif //LIBSPACEY_SRSENGINE_H
