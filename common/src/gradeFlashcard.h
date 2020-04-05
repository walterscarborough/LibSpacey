#ifndef LIBSPACEY_GRADEFLASHCARD_H
#define LIBSPACEY_GRADEFLASHCARD_H

#include "flashcard.h"

auto gradeFlashcard(
        Flashcard flashcard,
        unsigned int grade,
        unsigned long long currentDatetime
) -> Flashcard;

#endif
