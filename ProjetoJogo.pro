#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T13:53:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoJogo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Peca.cpp \
    Matriz.cpp

HEADERS  += mainwindow.h \
    Matriz.h \
    Peca.h

FORMS    += mainwindow.ui
