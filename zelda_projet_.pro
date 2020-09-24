QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Door.cpp \
    Element.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Hero.cpp \
    Potion.cpp \
    Repeller.cpp \
    Sand.cpp \
    Score.cpp \
    Wall.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bullet.h \
    Door.h \
    Element.h \
    Enemy.h \
    Game.h \
    Health.h \
    Hero.h \
    Potion.h \
    Repeller.h \
    Sand.h \
    Score.h \
    Wall.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    sounds/classic_hurt.mp3 \
    sounds/healing-pokemon-sound.mp3 \
    sounds/pistol_fire3.mp3 \
    sounds/titanic-parody-mp3cut.mp3
