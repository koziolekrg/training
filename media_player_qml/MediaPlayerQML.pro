TEMPLATE = app

QT += core gui
QT += qml quick
QT += multimedia multimediawidgets

CONFIG += c++11

SOURCES += main.cpp \
    mediaplayer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mediaplayer.h
