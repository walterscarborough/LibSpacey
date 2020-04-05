import LibSpaceyModule from "./libspacey-build/libspacey-module";
import { LibSpaceyFlashcard, LibSpaceyModuleInstance } from "./LibSpaceyTypes";
import FlashcardBase, { FlashcardGrade } from "./FlashcardBase";

export class LibSpaceyModuleWrapper {
  private moduleInstance?: LibSpaceyModuleInstance;

  public async gradeFlashcard(
    flashcard: FlashcardBase,
    grade: FlashcardGrade,
    currentDate: number
  ): Promise<FlashcardBase> {
    const libSpaceyFlashcard = await this.convertFlashcardBaseToLibSpaceyFlashcard(
      flashcard
    );

    const libSpaceyGrade = this.convertFlashcardGradeToLibSpaceyGrade(grade);

    const gradedLibSpaceyFlashcard = await this.gradeLibSpaceyFlashcard(
      libSpaceyFlashcard,
      libSpaceyGrade,
      currentDate
    );

    const gradedFlashcardBase = this.convertLibSpaceyFlashcardToFlashcardBase(
      gradedLibSpaceyFlashcard
    );

    return gradedFlashcardBase;
  }

  private convertLibSpaceyFlashcardToFlashcardBase(
    libSpaceyFlashcard: LibSpaceyFlashcard
  ): FlashcardBase {
    return {
      interval: libSpaceyFlashcard.interval,
      repetition: libSpaceyFlashcard.repetition,
      easinessFactor: libSpaceyFlashcard.easinessFactor,
      previousDate: libSpaceyFlashcard.previousDate,
      nextDate: libSpaceyFlashcard.nextDate,
    } as FlashcardBase;
  }

  private async convertFlashcardBaseToLibSpaceyFlashcard(
    flashcard: FlashcardBase
  ): Promise<LibSpaceyFlashcard> {
    const libSpaceyFlashcard = await this.createFlashcard();

    libSpaceyFlashcard.interval = flashcard.interval;
    libSpaceyFlashcard.repetition = flashcard.repetition;
    libSpaceyFlashcard.easinessFactor = flashcard.easinessFactor;
    libSpaceyFlashcard.previousDate = flashcard.previousDate;
    libSpaceyFlashcard.nextDate = flashcard.nextDate;

    return libSpaceyFlashcard;
  }

  private convertFlashcardGradeToLibSpaceyGrade(
    flashcardGrade: FlashcardGrade
  ): number {
    const gradeMapping = {
      [FlashcardGrade.Unknown]: 0,
      [FlashcardGrade.Hard]: 1,
      [FlashcardGrade.Medium]: 2,
      [FlashcardGrade.Easy]: 3,
      [FlashcardGrade.VeryEasy]: 4,
    };

    return gradeMapping[flashcardGrade];
  }

  private async gradeLibSpaceyFlashcard(
    libSpaceyFlashcard: LibSpaceyFlashcard,
    grade: number,
    currentDate: number
  ): Promise<LibSpaceyFlashcard> {
    if (!this.moduleInstance) {
      await this.createModuleInstance();
    }

    const flashcardGrader = (this.moduleInstance! as any).FlashcardGrader;

    const gradedFlashcard = flashcardGrader.prototype.gradeFlashcard(
      libSpaceyFlashcard,
      grade,
      currentDate
    );

    return Promise.resolve(gradedFlashcard);
  }

  private async createFlashcard(): Promise<LibSpaceyFlashcard> {
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
