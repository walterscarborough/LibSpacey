export interface LibSpaceyFlashcard {
  new (): LibSpaceyFlashcard;
  repetition: number;
  interval: number;
  easinessFactor: number;
  previousDate: number;
  nextDate: number;
}

export interface FlashcardGrader {
  gradeFlashcard: (
    libSpaceyFlashcard: LibSpaceyFlashcard,
    grade: number,
    currentDatetime: number
  ) => LibSpaceyFlashcard;
}

export interface LibSpaceyModuleInstance {
  Flashcard: new () => LibSpaceyFlashcard;
  FlashcardGrader: FlashcardGrader;
}

export interface LibSpaceyModule {
  LibSpaceyModule: Promise<LibSpaceyModuleInstance>;
}
