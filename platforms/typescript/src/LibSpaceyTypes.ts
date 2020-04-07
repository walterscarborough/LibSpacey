export interface Flashcard {
  new (): Flashcard;
  repetition: number;
  interval: number;
  easinessFactor: number;
  previousDate: number;
  nextDate: number;
}

export interface FlashcardGrader {
  gradeFlashcard: (
    flashcard: Flashcard,
    grade: number,
    currentDatetime: number
  ) => Flashcard;
}

export interface LibSpaceyModuleInstance {
  Flashcard: new () => Flashcard;
  FlashcardGrader: FlashcardGrader;
}

export interface LibSpaceyModule {
  LibSpaceyModule: Promise<LibSpaceyModuleInstance>;
}
