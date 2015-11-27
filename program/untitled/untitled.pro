QT += core
QT -= gui

TARGET = untitled
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../individual.cpp \
    ../main.cpp \
    ../people.cpp

DISTFILES += \
    ../people.o

HEADERS += \
    ../individual.h \
    ../people.h

