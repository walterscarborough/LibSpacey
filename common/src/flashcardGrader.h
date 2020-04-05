#ifndef LIBSPACEY_FLASHCARDGRADER_H
#define LIBSPACEY_FLASHCARDGRADER_H

#include "flashcard.h"

class FlashcardGrader {
public:
    static auto gradeFlashcard(
        Flashcard flashcard,
        unsigned int grade,
        unsigned long long currentDatetime
    ) -> Flashcard;
};

#endif
