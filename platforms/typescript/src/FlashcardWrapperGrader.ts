import LibSpaceyModule from "./libspacey-build/libspacey-module";
import { Flashcard, LibSpaceyModuleInstance } from "./LibSpaceyTypes";
import FlashcardWrapper from "./FlashcardWrapper";
import { Grade } from "./Grade";

export class FlashcardWrapperGrader {
  private moduleInstance?: LibSpaceyModuleInstance;

  public async gradeFlashcard(
    flashcardWrapper: FlashcardWrapper,
    grade: Grade,
    currentDate: number
  ): Promise<FlashcardWrapper> {
    const flashcard = await this.convertFlashcardWrapperToFlashcard(
      flashcardWrapper
    );

    const libSpaceyGrade = this.convertFlashcardGradeToLibSpaceyGrade(grade);

    const gradedFlashcard = await this.gradeFlashcardWithLibSpacey(
      flashcard,
      libSpaceyGrade,
      currentDate
    );

    return this.convertFlashcardToFlashcardWrapper(gradedFlashcard);
  }

  private convertFlashcardToFlashcardWrapper(
    flashcard: Flashcard
  ): FlashcardWrapper {
    return {
      interval: flashcard.interval,
      repetition: flashcard.repetition,
      easinessFactor: flashcard.easinessFactor,
      previousDate: flashcard.previousDate,
      nextDate: flashcard.nextDate,
    } as FlashcardWrapper;
  }

  private async convertFlashcardWrapperToFlashcard(
    flashcardWrapper: FlashcardWrapper
  ): Promise<Flashcard> {
    const flashcard = await this.createFlashcard();

    flashcard.interval = flashcardWrapper.interval;
    flashcard.repetition = flashcardWrapper.repetition;
    flashcard.easinessFactor = flashcardWrapper.easinessFactor;
    flashcard.previousDate = flashcardWrapper.previousDate;
    flashcard.nextDate = flashcardWrapper.nextDate;

    return flashcard;
  }

  private convertFlashcardGradeToLibSpaceyGrade(flashcardGrade: Grade): number {
    const gradeMapping = {
      [Grade.Unknown]: 0,
      [Grade.Hard]: 1,
      [Grade.Medium]: 2,
      [Grade.Easy]: 3,
      [Grade.VeryEasy]: 4,
    };

    return gradeMapping[flashcardGrade];
  }

  private async gradeFlashcardWithLibSpacey(
    flashcard: Flashcard,
    grade: number,
    currentDate: number
  ): Promise<Flashcard> {
    if (!this.moduleInstance) {
      await this.createModuleInstance();
    }

    const flashcardGrader = (this.moduleInstance! as any).FlashcardGrader;

    const gradedFlashcard = flashcardGrader.prototype.gradeFlashcard(
      flashcard,
      grade,
      currentDate
    );

    return Promise.resolve(gradedFlashcard);
  }

  private async createFlashcard(): Promise<Flashcard> {
    if (!this.moduleInstance) {
      await this.createModuleInstance();
    }

    return Promise.resolve(new this.moduleInstance!.Flashcard());
  }

  private createModuleInstance(): Promise<void> {
    return new Promise<void>((success) => {
      LibSpaceyModule().then((moduleInstance: LibSpaceyModuleInstance) => {
        this.moduleInstance = moduleInstance;

        success();
      });
    });
  }
}
