QT       += core

QT       -= gui

TARGET = rc_server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    rc_server.cpp

HEADERS += \
    rc_server.h \
    debugging_functions.h \
    utility_functions.h

QT += network
