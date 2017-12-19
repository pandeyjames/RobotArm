#-------------------------------------------------
#
# Project created by QtCreator 2017-12-16T09:06:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = App
TEMPLATE = app
#TARGET = portcomsender
#TEMPLATE = app

# This are the to line you have to add
include(../../src/qextserialport.pri)
#

SOURCES += main.cpp\
        connection.cpp

HEADERS  += connection.h

FORMS    += connection.ui
