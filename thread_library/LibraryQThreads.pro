QT       += core

QT       -= gui

TARGET = LibraryQThreads
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += \
    main.cpp \
    book.cpp \
    booksstorage.cpp \
    userthread.cpp

HEADERS += \
    book.h \
    booksstorage.h \
    userthread.h
