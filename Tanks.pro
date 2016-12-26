QT += widgets

TEMPLATE = app
TARGET = Tanks
INCLUDEPATH += .
DESTDIR = bin		#Destination du fichier TARGET "Tanks"
OBJECTS_DIR = bin	#Destination des fichiers objet
RCC_DIR = bin		#Destination des fichiers qrc
MOC_DIR = bin
UI_DIR = BIN


SOURCES += \
    src/main.cpp \
    src/ButtonWidget.cpp \
    src/Menu.cpp \
    src/MenuJeu.cpp \
    src/Jeu.cpp \
    src/Point.cpp \
    src/Segment.cpp \
    src/Terrain.cpp \
    src/Tank.cpp \
    src/Canon.cpp \
    src/Obus.cpp \
    src/Obstacle.cpp \


HEADERS += \
    head/Definitions.h \
    head/ButtonWidget.h \
    head/Menu.h \
    head/MenuJeu.h \
    head/Jeu.h \
    head/Point.h \
    head/Segment.h \
    head/Terrain.h \
    head/Tank.h \
    head/Canon.h \
    head/Obus.h \
    head/Obstacle.h \


RESOURCES += \
    img/logo.qrc \
    img/bg.qrc \
    img/tank1.qrc \
    img/tank2.qrc \
    img/tank3.qrc \
    img/tank4.qrc \
    img/canon1.qrc \
    img/canon2.qrc \
    img/canon3.qrc \
    img/canon4.qrc \
    img/rocher.qrc \
    img/arbre.qrc \
    img/obus.qrc \
    img/terrain.qrc
