//
// Created by zzh on 2018/7/27 0002.
//

#include <jni.h>
#include <android/native_window_jni.h>
#include <log.h>
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

Triangle *triangle = nullptr;
Circle *circle = nullptr;
Square *square = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_JniTriangleActivity__1init(JNIEnv *env, jclass type) {
    if (triangle) {
        delete triangle;
    }
    triangle = new Triangle();
    triangle->init();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_JniTriangleActivity__1resize(JNIEnv *env, jclass type,
                                                                      jint width, jint height) {
    if (!triangle) {
        LOGE("triangle does not initialized");
        return;
    }
    triangle->resize(width, height);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_JniTriangleActivity__1draw(JNIEnv *env, jclass type) {
    if (!triangle) {
        LOGE("triangle does not initialized");
        return;
    }
    triangle->draw();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_EGLCircleActivity__1init(JNIEnv *env, jclass type,
                                                                  jobject surface, jint width,
                                                                  jint height) {
    if (circle) {
        delete circle;
    }
    ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
    circle = new Circle(window);
    circle->resize(width, height);
    circle->start();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_EGLCircleActivity__1draw(JNIEnv *env, jclass type) {
    if (circle == nullptr) {
        LOGE("draw error, shape is null");
        return;
    }
    circle->draw();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_EGLCircleActivity__1release(JNIEnv *env, jclass type) {
    if (circle) {
        circle->stop();
        delete circle;
        circle = nullptr;
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_VaoVboActivity__1init(JNIEnv *env, jclass type,
                                                               jobject surface, jint width,
                                                               jint height) {
    if (square) {
        delete square;
    }
    ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
    square = new Square(window);
    square->resize(width, height);
    square->start();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_VaoVboActivity__1draw(JNIEnv *env, jclass type) {
    if (square == nullptr) {
        LOGE("draw error, shape is null");
        return;
    }
    square->draw();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_VaoVboActivity__1release(JNIEnv *env, jclass type) {
    if (square) {
        square->stop();
        delete square;
        square = nullptr;
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_MatrixTransformActivity__1init(JNIEnv *env, jclass type,
                                                                        jobject surface, jint width,
                                                                        jint height) {
    if (square) {
        delete square;
    }
    ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
    square = new Square(window);
    square->resize(width, height);
    square->start();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_MatrixTransformActivity__1draw(JNIEnv *env, jclass type,
                                                                        jfloatArray matrix_) {
    if (square == nullptr) {
        LOGE("draw error, shape is null");
        return;
    }

    jfloat *matrix = env->GetFloatArrayElements(matrix_, NULL);

    square->setMatrix(matrix);
    square->draw();

    env->ReleaseFloatArrayElements(matrix_, matrix, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_steven_avgraphics_activity_gles_MatrixTransformActivity__1release(JNIEnv *env,
                                                                           jclass type) {
    if (square) {
        square->stop();
        delete square;
        square = nullptr;
    }
}