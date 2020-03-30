export default interface FlashcardBase {
    repetition: number;
    interval: number;
    easinessFactor: number;
    previousDate: number;
    nextDate: number;
}

export enum FlashcardGrade {
    Unknown,
    Hard,
    Medium,
    Easy,
    VeryEasy
}

const createFlashcard = (): FlashcardBase => {
    const flashcard: FlashcardBase = {
        repetition: 0,
        interval: 1,
        easinessFactor: 2.5,
        previousDate: 0,
        nextDate: 0
    };

    return flashcard;
};
