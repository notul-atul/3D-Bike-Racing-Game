#-------------------------------------------------
#
# Project created by QtCreator 2013-08-10T12:40:04
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = MainMenu
TEMPLATE = app

LIBS += -lGL -lGLU

SOURCES += main.cpp\
        mainwindow.cpp \
    newprofile.cpp \
    selecttrack.cpp \
    imageInfo.cpp \
    terrain.cpp \
    Vector.cpp \
    texture.cpp \
    gamewindow.cpp \
    libtarga.cpp \
    objectRender.cpp \
    trackpreview.cpp \
    hud.cpp \
    speedometer.cpp \
    player.cpp \
    glm.cpp \
    pausedmenu.cpp \
    GameEngine.cpp \
    displayobstaclesbonuses.cpp \
    obstaclesbonuses.cpp \
    selectprofile.cpp \
    options.cpp

HEADERS  += mainwindow.h \
    newprofile.h \
    selecttrack.h \
    imageInfo.h \
    terrain.h \
    Vector.h \
    texture.h \
    gamewindow.h \
    libtarga.h \
    objectRender.h \
    trackpreview.h \
    hud.h \
    speedometer.h \
    player.h \
    pausedmenu.h \
    GameEngine.h \
    displayobstaclesbonuses.h \
    obstaclesbonuses.h \
    selectprofile.h \
    options.h

FORMS    += mainwindow.ui \
    newprofile.ui \
    selecttrack.ui \
    gamewindow.ui \
    hud.ui \
    pausedmenu.ui \
    trackmap.ui \
    showlock.ui \
    selectprofile.ui \
    options.ui
