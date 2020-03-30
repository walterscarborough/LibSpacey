#ifndef LIBSPACEY_SRSENGINE_H
#define LIBSPACEY_SRSENGINE_H

#include "flashcard.h"

class SrsEngine {
public:
    SrsEngine();
    auto gradeFlashcard(
            Flashcard &flashcard,
            unsigned int grade,
            unsigned long long currentDatetime
    ) -> Flashcard&;
};

#endif
