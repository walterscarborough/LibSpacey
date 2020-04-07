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
  VeryEasy,
}
