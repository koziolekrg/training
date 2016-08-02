TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    book.cpp \
    admin.cpp \
    item.cpp \
    itemstore.cpp \
    magazine.cpp \
    order.cpp \
    orderstore.cpp \
    person.cpp \
    personstore.cpp \
    user.cpp \
    menu.cpp \
    readfile.cpp \
    exception.cpp

HEADERS += \
    book.h \
    admin.h \
    item.h \
    itemstore.h \
    magazine.h \
    order.h \
    orderstore.h \
    person.h \
    personstore.h \
    user.h \
    menu.h \
    readfile.h \
    exception.h

