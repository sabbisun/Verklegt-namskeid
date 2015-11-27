QT += core
QT -= gui

TARGET = Computer_scientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    individual.cpp \
    people.cpp

HEADERS += \
    individual.h \
    people.h

