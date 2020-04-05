package com.walterscarborough.libspacey

data class Flashcard(
    val repetition: Int = 0,
    val interval: Int = 1,
    val easinessFactor: Float = 2.5F,
    val previousDate: Long,
    val nextDate: Long
)
