#-------------------------------------------------
#
# Project created by QtCreator 2012-07-18T15:06:09
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = rc_client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    rc_client.cpp

HEADERS += \
    rc_client.h \
    debugging_functions.h \
    utility_functions.h

QT += network
