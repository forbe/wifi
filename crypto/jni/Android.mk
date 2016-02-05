LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE     := cry
LOCAL_SRC_FILES  := crypto.c base64.c xxtea.c
LOCAL_LDLIBS    := -lm -llog
#LOCAL_CFLAGS += -ffunction-sections -fvisibility=hidden -fvisibility=hidden -std=c99 -DNATIVE_NETWORK_HELPER -D__DEBUG__
#LOCAL_LDFLAGS += -Wl,--gc-sections

include $(BUILD_SHARED_LIBRARY)

#include $(CLEAR_VARS)

#LOCAL_MODULE     := rpc
#LOCAL_SRC_FILES  := rpc/epollsrv.c rpc/map.c
#LOCAL_LDLIBS    := -lm -llog
#LOCAL_CFLAGS += -pie -fPIE -D__DEBUG__
#LOCAL_LDFLAGS += -pie -fPIE
##LOCAL_CFLAGS += -ffunction-sections -fvisibility=hidden -fvisibility=hidden -std=c99 -DNATIVE_NETWORK_HELPER -D__DEBUG__
##LOCAL_LDFLAGS += -Wl,--gc-sections

#include $(BUILD_EXECUTABLE)

#include $(CLEAR_VARS)
#LOCAL_MODULE     := functions
#LOCAL_SRC_FILES  := functions/functions.c functions/mongoose.c  functions/http_client.c
#LOCAL_LDLIBS    := -lm -llog
#LOCAL_CFLAGS += -pie -fPIE -D__DEBUG__
#LOCAL_LDFLAGS += -pie -fPIE
##LOCAL_CFLAGS += -ffunction-sections -fvisibility=hidden -fvisibility=hidden -std=c99 -DNATIVE_NETWORK_HELPER -D__DEBUG__
##LOCAL_LDFLAGS += -Wl,--gc-sections

#include $(BUILD_EXECUTABLE)