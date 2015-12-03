#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T14:02:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        main-window.cpp \
    options-form.cpp \
    instructions-form.cpp \
    launch-game-form.cpp \
    game-form.cpp \
    main-form.cpp \
    editor-form.cpp \
    view.cpp \
    scene.cpp \
    wall.cpp \
    map.cpp \
    blank.cpp \
    snake.cpp \
    head.cpp \
    bodypart.cpp \
    food.cpp \
    util.cpp \
    sceneeditor.cpp \
    eraser.cpp \
    clickablelabel.cpp

HEADERS  += main-window.h \
    options-form.h \
    instructions-form.h \
    launch-game-form.h \
    game-form.h \
    main-form.h \
    editor-form.h \
    view.h \
    scene.h \
    wall.h \
    map.h \
    blank.h \
    snake.h \
    head.h \
    bodypart.h \
    food.h \
    util.h \
    sceneeditor.h \
    eraser.h \
    clickablelabel.h

FORMS    += \
    main-window.ui \
    options-form.ui \
    instructions-form.ui \
    launch-game-form.ui \
    game-form.ui \
    main-form.ui \
    editor-form.ui

DISTFILES += \
    default.map \
    labyrinthe.map \
    body.png \
    wall.png \
    blank.png \
    body.png \
    head.png
