import FlashcardModule from './../dist-emscripten/libspacey-flashcard-module';
import {LibSpaceyFlashcard, LibSpaceyModuleInstance, LibSpaceySrsEngine} from "./LibSpaceyTypes";
import FlashcardBase, {FlashcardGrade} from "./FlashcardBase";

export class LibSpaceyModuleWrapper {

    private moduleInstance?: LibSpaceyModuleInstance;

    public async gradeFlashcard(flashcard: FlashcardBase, grade: FlashcardGrade, currentDate: number): Promise<FlashcardBase> {
        const libSpaceyFlashcard = await this.convertFlashcardBaseToLibSpaceyFlashcard(flashcard);
        const libSpaceyGrade = this.convertFlashcardGradeToLibSpaceyGrade(grade);

        const gradedLibSpaceyFlashcard = await this.gradeLibSpaceyFlashcard(libSpaceyFlashcard, libSpaceyGrade, currentDate);

        const gradedFlashcardBase = this.convertLibSpaceyFlashcardToFlashcardBase(gradedLibSpaceyFlashcard);

        return gradedFlashcardBase;
    }

    private convertLibSpaceyFlashcardToFlashcardBase(libSpaceyFlashcard: LibSpaceyFlashcard): FlashcardBase {
        return {
            repetition: libSpaceyFlashcard.getRepetition(),
            interval: libSpaceyFlashcard.getInterval(),
            easinessFactor: libSpaceyFlashcard.getEasinessFactor(),
            previousDate: libSpaceyFlashcard.getPreviousDate(),
            nextDate: libSpaceyFlashcard.getNextDate(),
        } as FlashcardBase;
    }

    private async convertFlashcardBaseToLibSpaceyFlashcard(flashcard: FlashcardBase): Promise<LibSpaceyFlashcard> {
        const libSpaceyFlashcard = await this.createFlashcard();

        libSpaceyFlashcard.setInterval(flashcard.interval);
        libSpaceyFlashcard.setRepetition(flashcard.repetition);
        libSpaceyFlashcard.setEasinessFactor(flashcard.easinessFactor);
        libSpaceyFlashcard.setPreviousDate(flashcard.previousDate);
        libSpaceyFlashcard.setNextDate(flashcard.nextDate);

        return libSpaceyFlashcard;
    }

    private convertFlashcardGradeToLibSpaceyGrade(flashcardGrade: FlashcardGrade): number {
        const gradeMapping = {
            [FlashcardGrade.Unknown]: 0,
            [FlashcardGrade.Hard]: 1,
            [FlashcardGrade.Medium]: 2,
            [FlashcardGrade.Easy]: 3,
            [FlashcardGrade.VeryEasy]: 4,
        };

        return gradeMapping[flashcardGrade];
    }

    private async gradeLibSpaceyFlashcard(libSpaceyFlashcard: LibSpaceyFlashcard, grade: number, currentDate: number): Promise<LibSpaceyFlashcard> {
        if (!this.moduleInstance) {
            await this.createModuleInstance();
        }

        const srsEngine = new this.moduleInstance!.SrsEngine();

        const gradedFlashcard = srsEngine.gradeFlashcard(libSpaceyFlashcard, grade, currentDate);

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
            FlashcardModule().then((moduleInstance: LibSpaceyModuleInstance) => {
                this.moduleInstance = moduleInstance;

                success();
            });
        })
    }
}
