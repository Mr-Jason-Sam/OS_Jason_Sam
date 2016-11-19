TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS +=-lpthread

SOURCES += \
    OS_Bitmap.cpp \
    OS_Main.cpp \
    OS_Global.cpp \
    OS_Code.cpp \
    OS_Token_Cmd.cpp \
    OS_Parse_Code.cpp \
    OS_AST.cpp \
    OS_File.cpp

CONFIG += link_pkgconfig

PKGCONFIG += gtk+-3.0

DISTFILES += \
    ASC16 \
    read \
    write

HEADERS += \
    OS_Bitmap.h \
    OS_Global.h \
    OS_Code.h \
    OS_Token_Cmd.h \
    OS_Parse_Code.h \
    OS_AST.h \
    OS_File.h
