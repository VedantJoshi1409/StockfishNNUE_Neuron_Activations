#include "NNUEVisualization.h"

#include "visualization.h"

using namespace Stockfish::Visualization;

extern Buffer buffer;

JNIEXPORT void JNICALL Java_NNUEVisualization_init
  (JNIEnv *env, jclass this_class, jstring bigNet, jstring smallNet) {

        const char *big = env->GetStringUTFChars(bigNet, NULL);
        const char *small = env->GetStringUTFChars(smallNet, NULL);

        init(big, small);

        env->ReleaseStringUTFChars(bigNet, big);
        env->ReleaseStringUTFChars(smallNet, small);
}


JNIEXPORT jobjectArray JNICALL Java_NNUEVisualization_getNeurons
  (JNIEnv *env, jclass this_class, jstring fen) {
    const char *cfen = env->GetStringUTFChars(fen, NULL);

    int eval = getNeurons(cfen);

    jobjectArray result = env->NewObjectArray(7, env->FindClass("[I"), NULL);

    for (int i = 0; i < 6; ++i) {
        jintArray javaArray = env->NewIntArray(32);

        // Create a temporary jint array to hold the data
        jint tempArray[32];

        // Copy data from uint8_t array to jint array
        switch (i) {
            case 0:
                for (int j = 0; j < 32; ++j) {
                    tempArray[j] = static_cast<jint>(Stockfish::Visualization::buffer.fc_0[j]);
                }
            break;
            case 1:
                for (int j = 0; j < 32; ++j) {
                    tempArray[j] = static_cast<jint>(Stockfish::Visualization::buffer.ac_sqr_0[j]);
                }
            break;
            case 2:
                for (int j = 0; j < 32; ++j) {
                    tempArray[j] = static_cast<jint>(Stockfish::Visualization::buffer.ac_0[j]);
                }
            break;
            case 3:
                for (int j = 0; j < 32; ++j) {
                    tempArray[j] = static_cast<jint>(Stockfish::Visualization::buffer.fc_1[j]);
                }
            break;
            case 4:
                for (int j = 0; j < 32; ++j) {
                    tempArray[j] = static_cast<jint>(Stockfish::Visualization::buffer.ac_1[j]);
                }
            break;
            case 5:
                for (int j = 0; j < 32; ++j) {
                    tempArray[j] = static_cast<jint>(Stockfish::Visualization::buffer.fc_2[j]);
                }
            break;
        }

        // Create a jintArray of size 3 to hold the three integers
        jintArray evalArray = env->NewIntArray(3);

        // Define the three integers you want to store in evalArray
        jint evalValue[3] = { eval, Stockfish::Visualization::buffer.smallNet, Stockfish::Visualization::buffer.bucket };

        // Set the values into evalArray
        env->SetIntArrayRegion(evalArray, 0, 3, evalValue);

        // Set evalArray as the 7th element of result
        env->SetObjectArrayElement(result, 6, evalArray);

        // Release local reference to avoid memory leaks
        env->DeleteLocalRef(evalArray);

        // Set the data into the Java array
        env->SetIntArrayRegion(javaArray, 0, 32, tempArray);

        // Set the Java array into the result
        env->SetObjectArrayElement(result, i, javaArray);

        // Release local reference to avoid memory leaks
        env->DeleteLocalRef(javaArray);
    }

    env->ReleaseStringUTFChars(fen, cfen);

    return result;
}




