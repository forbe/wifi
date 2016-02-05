#include <jni.h>
#ifndef __Util_H__
#define __Util_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <jni.h>
#include <assert.h>
#include "base64.h"
#include "xxtea.h"


#define  LOG_TAG    "▇(＞﹏＜)▇!!!"
#ifdef __DEBUG__
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#else
#define  LOGI(...)
#define  LOGD(...)
#define  LOGE(...)
#endif

#define ABS(a) ((a)<(0)?(-a):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define MAX_RESULT_LEN 1024*10
char *encode( const char * , const char * );
char *decode( const char * , const char * );
#ifdef __cplusplus
}
#endif

#endif