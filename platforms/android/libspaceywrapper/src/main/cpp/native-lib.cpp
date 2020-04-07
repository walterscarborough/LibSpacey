#include <jni.h>
#include <string>
#include "../../../../../../common/src/flashcardGrader.h"

auto convertJvmFlashcardToCplusplusFlashcard(JNIEnv *env, jobject jvmFlashcard) -> Flashcard {
    jclass flashcardClass = env->GetObjectClass(jvmFlashcard);

    jfieldID interval_fieldId = env->GetFieldID(flashcardClass, "interval", "I");
    jint interval = env->GetIntField(jvmFlashcard, interval_fieldId);

    jfieldID repetition_fieldId = env->GetFieldID(flashcardClass, "repetition", "I");
    jint repetition = env->GetIntField(jvmFlashcard, repetition_fieldId);

    jfieldID easinessFactor_fieldId = env->GetFieldID(flashcardClass, "easinessFactor", "F");
    jfloat easinessFactor = env->GetFloatField(jvmFlashcard, easinessFactor_fieldId);

    jfieldID previousDate_fieldId = env->GetFieldID(flashcardClass, "previousDate", "J");
    jlong previousDate = env->GetLongField(jvmFlashcard, previousDate_fieldId);

    jfieldID nextDate_fieldId = env->GetFieldID(flashcardClass, "nextDate", "J");
    jlong nextDate = env->GetLongField(jvmFlashcard, nextDate_fieldId);

    auto cplusplusFlashcard = Flashcard();
    cplusplusFlashcard.interval = static_cast<unsigned int>(interval);
    cplusplusFlashcard.repetition = static_cast<unsigned int>(repetition);
    cplusplusFlashcard.easinessFactor = easinessFactor;
    cplusplusFlashcard.previousDate = static_cast<unsigned long long int>(previousDate);
    cplusplusFlashcard.nextDate = static_cast<unsigned long long int>(nextDate);

    return cplusplusFlashcard;
}

auto convertCplusplusFlashcardToJvmFlashcard(JNIEnv *env, Flashcard cplusplusFlashcard) -> jobject {
    jclass flashcardClass = env->FindClass("com/walterscarborough/libspacey/FlashcardWrapper");
    jmethodID flashcardConstructor = env->GetMethodID(flashcardClass, "<init>", "(IIFJJ)V");

    jobject jvmFlashcard = env->NewObject(
            flashcardClass,
            flashcardConstructor,
            (int) cplusplusFlashcard.repetition,
            (int) cplusplusFlashcard.interval,
            cplusplusFlashcard.easinessFactor,
            (long long) cplusplusFlashcard.previousDate,
            (long long) cplusplusFlashcard.nextDate
    );

    return jvmFlashcard;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_walterscarborough_libspacey_FlashcardWrapperGrader_00024Companion_gradeFlashcardWithLibSpacey(
        JNIEnv *env,
        jobject thiz,
        jobject flashcard,
        jint grade,
        jlong current_date
) {
    auto cplusplusFlashcard = convertJvmFlashcardToCplusplusFlashcard(
            env,
            flashcard
    );

    auto gradedCplusplusFlashcard = FlashcardGrader::gradeFlashcard(
            cplusplusFlashcard,
            static_cast<unsigned int>(grade),
            static_cast<unsigned long long int>(current_date)
    );

    auto gradedJvmFlashcard = convertCplusplusFlashcardToJvmFlashcard(
            env,
            gradedCplusplusFlashcard
    );

    return gradedJvmFlashcard;
}
