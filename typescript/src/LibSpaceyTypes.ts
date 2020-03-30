export interface LibSpaceyFlashcard {
    new(): LibSpaceyFlashcard;
    getRepetition: () => number;
    setRepetition(repetition: number): void;

    getInterval: () => number;
    setInterval(interval: number): void;

    getEasinessFactor: () => number;
    setEasinessFactor(easinessFactor: number): void;

    getPreviousDate: () => number;
    setPreviousDate(previousDate: number): void;

    getNextDate: () => number;
    setNextDate(nextDate: number): void;
}

export interface LibSpaceySrsEngine {
    gradeFlashcard: (
        libSpaceyFlashcard: LibSpaceyFlashcard,
        grade: number,
        currentDatetime: number
    ) => LibSpaceyFlashcard
}

export interface LibSpaceyModuleInstance {
    Flashcard: new() => LibSpaceyFlashcard;
    SrsEngine: new() => LibSpaceySrsEngine;
}

export interface LibSpaceyModule {
    FlashcardModule: Promise<LibSpaceyModuleInstance>;
}
