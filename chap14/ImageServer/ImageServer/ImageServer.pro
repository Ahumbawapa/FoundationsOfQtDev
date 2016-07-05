QT += core network


CONFIG += c++11

TARGET = ImageServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp \
    serverthread.cpp

HEADERS += \
    server.h \
    serverthread.h
