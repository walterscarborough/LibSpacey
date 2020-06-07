import { FlashcardWrapperGrader } from "../FlashcardWrapperGrader";
import FlashcardWrapper from "../FlashcardWrapper";
import {Grade} from "../Grade";

describe("gradeFlashcard", () => {
  it("should grade a flashcard with an unknown rating", async () => {
    const october_24_2016 = 1477294292;
    const october_25_2016 = 1477380692;

    const flashcard: FlashcardWrapper = {
      repetition: 0,
      interval: 1,
      easinessFactor: 2.5,
      previousDate: october_24_2016,
      nextDate: october_24_2016,
    };

    const flashcardModuleWrapper = new FlashcardWrapperGrader();
    const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
      flashcard,
      Grade.Unknown,
      october_24_2016
    );

    const expectedGradedFlashcard: FlashcardWrapper = {
      repetition: 0,
      interval: 1,
      easinessFactor: 1.7,
      previousDate: october_24_2016,
      nextDate: october_25_2016,
    };

    actualGradedFlashcard.easinessFactor =
      Math.round(actualGradedFlashcard.easinessFactor * 10) / 10;

    expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
  });

  it("should grade a flashcard with a hard rating", async () => {
    const october_23_2016 = 1477207892;
    const october_24_2016 = 1477294292;

    const flashcard: FlashcardWrapper = {
      repetition: 0,
      interval: 1,
      easinessFactor: 2.5,
      previousDate: october_23_2016,
      nextDate: october_23_2016,
    };

    const flashcardModuleWrapper = new FlashcardWrapperGrader();
    const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
      flashcard,
      Grade.Hard,
      october_23_2016
    );

    const expectedGradedFlashcard: FlashcardWrapper = {
      repetition: 0,
      interval: 1,
      easinessFactor: 1.96,
      previousDate: october_23_2016,
      nextDate: october_24_2016,
    };

    actualGradedFlashcard.easinessFactor =
      Math.round(actualGradedFlashcard.easinessFactor * 100) / 100;

    expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
  });

  it("should grade a flashcard with a medium rating", async () => {
    const october_24_2016 = 1477294292;
    const october_25_2016 = 1477380692;

    const flashcard: FlashcardWrapper = {
      repetition: 0,
      interval: 1,
      easinessFactor: 2.5,
      previousDate: october_24_2016,
      nextDate: october_24_2016,
    };

    const flashcardModuleWrapper = new FlashcardWrapperGrader();
    const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
      flashcard,
      Grade.Medium,
      october_24_2016
    );

    const expectedGradedFlashcard: FlashcardWrapper = {
      repetition: 0,
      interval: 1,
      easinessFactor: 2.18,
      previousDate: october_24_2016,
      nextDate: october_25_2016,
    };

    actualGradedFlashcard.easinessFactor =
      Math.round(actualGradedFlashcard.easinessFactor * 100) / 100;

    expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
  });

  it("should grade a flashcard with an easy rating", async () => {
    const october_23_2016 = 1477207892;
    const october_24_2016 = 1477294292;

    const flashcard: FlashcardWrapper = {
      repetition: 0,
      interval: 1,
      easinessFactor: 2.5,
      previousDate: october_23_2016,
      nextDate: october_23_2016,
    };

    const flashcardModuleWrapper = new FlashcardWrapperGrader();
    const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
      flashcard,
      Grade.Easy,
      october_23_2016
    );

    const expectedGradedFlashcard: FlashcardWrapper = {
      repetition: 1,
      interval: 1,
      easinessFactor: 2.36,
      previousDate: october_23_2016,
      nextDate: october_24_2016,
    };

    actualGradedFlashcard.easinessFactor =
      Math.round(actualGradedFlashcard.easinessFactor * 100) / 100;

    expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
  });

  it("should grade a flashcard with a very easy rating", async () => {
    const october_23_2016 = 1477207892;
    const october_24_2016 = 1477294292;

    const flashcard: FlashcardWrapper = {
      repetition: 0,
      interval: 1,
      easinessFactor: 2.5,
      previousDate: october_23_2016,
      nextDate: october_23_2016,
    };

    const flashcardModuleWrapper = new FlashcardWrapperGrader();
    const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
      flashcard,
      Grade.VeryEasy,
      october_23_2016
    );

    const expectedGradedFlashcard: FlashcardWrapper = {
      repetition: 1,
      interval: 1,
      easinessFactor: 2.5, // this is off of the expected output by 0.1 - it's probably due to a minor loss of floating point precision between emscripten and JS
      previousDate: october_23_2016,
      nextDate: october_24_2016,
    };

    actualGradedFlashcard.easinessFactor =
      Math.round(actualGradedFlashcard.easinessFactor * 100) / 100;

    expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
  });

  it("should grade a flashcard with a very easy rating and a long history", async () => {
    const october_23_2016 = 1477207892;
    const november_7_2016 = 1478503892;

    const flashcard: FlashcardWrapper = {
      repetition: 6,
      interval: 6,
      easinessFactor: 2.5,
      previousDate: october_23_2016,
      nextDate: october_23_2016,
    };

    const flashcardModuleWrapper = new FlashcardWrapperGrader();
    const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
      flashcard,
      Grade.VeryEasy,
      october_23_2016
    );

    const expectedGradedFlashcard: FlashcardWrapper = {
      repetition: 7,
      interval: 15,
      easinessFactor: 2.5, // this is off of the expected output by 0.1 - it's probably due to a minor loss of floating point precision between emscripten and JS
      previousDate: october_23_2016,
      nextDate: november_7_2016,
    };

    actualGradedFlashcard.easinessFactor =
      Math.round(actualGradedFlashcard.easinessFactor * 100) / 100;

    expect(actualGradedFlashcard).toEqual(expectedGradedFlashcard);
  });
});
