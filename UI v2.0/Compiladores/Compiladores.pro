#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T21:35:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Compiladores
TEMPLATE = app
CONFIG   += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    automaton.cpp \
    normalizador.cpp \
    pre_processing.cpp \
    tabla_token.cpp \
    analizador_lexico.cpp

HEADERS  += mainwindow.h \
    automaton.hpp \
    normalizador.hpp \
    pre_processing.hpp \
    tabla_token.hpp \
    analizador_lexico.hpp


FORMS    += mainwindow.ui
