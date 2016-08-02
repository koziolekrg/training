TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    book.cpp \
    testsoflist.cpp \
    testsofvector.cpp \
    testsofdeque.cpp

HEADERS += \
    book.h \
    testsoflist.h \
    testsofvector.h \
    testsofdeque.h

