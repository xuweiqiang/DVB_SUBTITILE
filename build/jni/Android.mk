LOCAL_PATH := $(call my-dir)


# libDSub
include $(CLEAR_VARS)
LOCAL_MODULE    := DSub
LOCAL_C_INCLUDES := ../src/libSUB ../libwin32/include ../../
SRC_DIR := ../../src/libSUB
LOCAL_SRC_FILES := $(SRC_DIR)/ALI_DTV_SUB.c \
	$(SRC_DIR)/dsub_decoder.c \
	$(SRC_DIR)/dsub_display_set.c \
	$(SRC_DIR)/dsub_finder.c \
	$(SRC_DIR)/dsub_renderer.c \
	$(SRC_DIR)/dsub_segments.c \
	$(SRC_DIR)/exlist.c \
	../../version.c
LOCAL_CFLAGS := -DHAVE_STDINT_H
include $(BUILD_STATIC_LIBRARY)

# libSUBDecoder
include $(CLEAR_VARS)
LOCAL_MODULE    := SUBDecoder
LOCAL_C_INCLUDES := ../src/libSUBDecoder ../src/libSUB ../include ../libwin32/include
SRC_DIR := ../../src/libSUBDecoder
LOCAL_SRC_FILES := $(SRC_DIR)/SUBDecoder.cpp \
	$(SRC_DIR)/SUBSync.cpp
LOCAL_WHOLE_STATIC_LIBRARIES := DSub
LOCAL_LDLIBS := -L../libwin32/lib/ -lwin32
include $(BUILD_SHARED_LIBRARY)
