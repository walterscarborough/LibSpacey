import {LibSpaceyModuleWrapper} from "../LibSpaceyModuleWrapper";
import FlashcardBase, {FlashcardGrade} from "../FlashcardBase";

describe('gradeFlashcard', () => {
    it('should grade a flashcard with an unknown rating', async () => {
        const october_24_2016 = 1477294292;
        const october_25_2016 = 1477380692;

        const flashcard: FlashcardBase = {
            repetition: 0,
            interval: 1,
            easinessFactor: 2.5,
            previousDate: october_24_2016,
            nextDate: october_24_2016
        };

        const flashcardModuleWrapper = new LibSpaceyModuleWrapper();
        const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
            flashcard,
            FlashcardGrade.Unknown,
            october_24_2016
        );

        const expectedGradedFlashcard: FlashcardBase = {
            repetition: 0,
            interval: 1,
            easinessFactor: 1.7,
            previousDate: october_24_2016,
            nextDate: october_25_2016
        };

        actualGradedFlashcard.easinessFactor = (Math.round(actualGradedFlashcard.easinessFactor * 10) / 10);

        expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
    });

    it('should grade a flashcard with a hard rating', async () => {
        const october_23_2016 = 1477207892;
        const october_24_2016 = 1477294292;

        const flashcard: FlashcardBase = {
            repetition: 0,
            interval: 1,
            easinessFactor: 2.5,
            previousDate: october_23_2016,
            nextDate: october_23_2016
        };

        const flashcardModuleWrapper = new LibSpaceyModuleWrapper();
        const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
            flashcard,
            FlashcardGrade.Hard,
            october_23_2016
        );

        const expectedGradedFlashcard: FlashcardBase = {
            repetition: 0,
            interval: 1,
            easinessFactor: 1.96,
            previousDate: october_23_2016,
            nextDate: october_24_2016
        };

        actualGradedFlashcard.easinessFactor = (Math.round(actualGradedFlashcard.easinessFactor * 100) / 100);

        expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
    });

    it('should grade a flashcard with a medium rating', async () => {
        const october_24_2016 = 1477294292;
        const october_25_2016 = 1477380692;

        const flashcard: FlashcardBase = {
            repetition: 0,
            interval: 1,
            easinessFactor: 2.5,
            previousDate: october_24_2016,
            nextDate: october_24_2016
        };

        const flashcardModuleWrapper = new LibSpaceyModuleWrapper();
        const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
            flashcard,
            FlashcardGrade.Medium,
            october_24_2016
        );

        const expectedGradedFlashcard: FlashcardBase = {
            repetition: 0,
            interval: 1,
            easinessFactor: 2.18,
            previousDate: october_24_2016,
            nextDate: october_25_2016
        };

        actualGradedFlashcard.easinessFactor = (Math.round(actualGradedFlashcard.easinessFactor * 100) / 100);

        expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
    });

    it('should grade a flashcard with an easy rating', async () => {
        const october_23_2016 = 1477207892;
        const october_24_2016 = 1477294292;

        const flashcard: FlashcardBase = {
            repetition: 0,
            interval: 1,
            easinessFactor: 2.5,
            previousDate: october_23_2016,
            nextDate: october_23_2016
        };

        const flashcardModuleWrapper = new LibSpaceyModuleWrapper();
        const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
            flashcard,
            FlashcardGrade.Easy,
            october_23_2016
        );

        const expectedGradedFlashcard: FlashcardBase = {
            repetition: 1,
            interval: 1,
            easinessFactor: 2.36,
            previousDate: october_23_2016,
            nextDate: october_24_2016
        };

        actualGradedFlashcard.easinessFactor = (Math.round(actualGradedFlashcard.easinessFactor * 100) / 100);

        expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
    });

    it.skip('should grade a flashcard with a very easy rating', async () => {
        const october_23_2016 = 1477207892;
        const october_24_2016 = 1477294292;

        const flashcard: FlashcardBase = {
            repetition: 0,
            interval: 1,
            easinessFactor: 2.5,
            previousDate: october_23_2016,
            nextDate: october_23_2016
        };

        const flashcardModuleWrapper = new LibSpaceyModuleWrapper();
        const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
            flashcard,
            FlashcardGrade.VeryEasy,
            october_23_2016
        );

        const expectedGradedFlashcard: FlashcardBase = {
            repetition: 1,
            interval: 1,
            easinessFactor: 2.6,
            previousDate: october_23_2016,
            nextDate: october_24_2016
        };

        actualGradedFlashcard.easinessFactor = (Math.round(actualGradedFlashcard.easinessFactor * 100) / 100);

        expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
    });

    it.skip('should grade a flashcard with a very easy rating and a long history', async () => {
        const october_23_2016 = 1477207892;
        const october_27_2016 = 1477553492;

        const flashcard: FlashcardBase = {
            repetition: 6,
            interval: 6,
            easinessFactor: 2.5,
            previousDate: october_23_2016,
            nextDate: october_23_2016
        };

        const flashcardModuleWrapper = new LibSpaceyModuleWrapper();
        const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
            flashcard,
            FlashcardGrade.VeryEasy,
            october_23_2016
        );

        const expectedGradedFlashcard: FlashcardBase = {
            repetition: 7,
            interval: 4,
            easinessFactor: 2.6,
            previousDate: october_23_2016,
            nextDate: october_27_2016
        };

        actualGradedFlashcard.easinessFactor = (Math.round(actualGradedFlashcard.easinessFactor * 100) / 100);

        expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
    });
});
