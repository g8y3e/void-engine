LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2
SOURCE_PATH :=  ../../../../source

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include/ \
	$(LOCAL_PATH)/../../../../source/ 

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	../../../../source/main.cc \
	../../../../source/void_engine/base/game.cc \
	../../../../source/void_engine/base/debug/logger.cc \
	../../../../source/void_engine/base/render/render.cc \

LOCAL_SHARED_LIBRARIES := SDL2

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog
LOCAL_CPP_FEATURES += exceptions
LOCAL_LDFLAGS += -latomic
LOCAL_CPPFLAGS := -std=c++11 -fexceptions

include $(BUILD_SHARED_LIBRARY)
